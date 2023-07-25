/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:28:07 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/25 13:57:38 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void			*meals_done(t_main *data);

void	*meal_checker(void *void_data)
{
	t_main	*data;
	int		i;
	int		philos_done;

	data = (t_main *)void_data;
	not_yet(data);
	if (data->max_meals == -1)
		return (NULL);
	i = 0;
	while (are_philos_alive(data))
	{
		if (i >= data->philo_count)
		{
			philos_done = 0;
			i = 0;
		}
		pthread_mutex_lock(&data->philos[i]->meal_count_lock);
		if (data->philos[i]->times_munched >= data->max_meals)
			philos_done++;
		if (philos_done == data->philo_count)
			return (meals_done(data));
		pthread_mutex_unlock(&data->philos[i]->meal_count_lock);
		i++;
	}
	return (NULL);
}

void	*meals_done(t_main *data)
{
	if (!are_philos_alive(data))
		return (NULL);
	pthread_mutex_lock(&data->stdout);
	printf("All philosophers have eaten %i meals.\n", data->max_meals);
	pthread_mutex_lock(&data->philos_alive_lock);
	data->all_philos_alive = false;
	pthread_mutex_unlock(&data->philos_alive_lock);
	return (NULL);
}

void	*death_checker(void *void_data)
{
	t_main	*data;
	t_philo	*current_philo;
	int		i;

	data = (t_main *)void_data;
	lets_go(data);
	pthread_mutex_init(&data->philos_alive_lock, NULL);
	i = 0;
	while (are_philos_alive(data))
	{
		if (i >= data->philo_count)
			i = 0;
		current_philo = data->philos[i];
		pthread_mutex_lock(&current_philo->last_munch_lock);
		if (get_elapsed_time(data->start_time) - current_philo->last_munch
			> data->die_time)
			return (death(data, data->philos[i]));
		pthread_mutex_unlock(&current_philo->last_munch_lock);
		i++;
	}
	return (NULL);
}

void	*death(t_main *data, t_philo *dead_philo)
{
	print_action(dead_philo, DIE);
	pthread_mutex_lock(&data->philos_alive_lock);
	data->all_philos_alive = false;
	pthread_mutex_unlock(&data->philos_alive_lock);
	return (NULL);
}
