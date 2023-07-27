/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:28:07 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/27 20:37:09 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	*meals_done(t_main *data);
void	*death(t_main *data, t_philo *dead_philo);
int		is_philo_done(t_main *data, int i);

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
	philos_done = 0;
	while (are_philos_alive(data))
	{
		pthread_mutex_lock(&data->philos[i]->meal_count_lock);
		philos_done += is_philo_done(data, i);
		pthread_mutex_unlock(&data->philos[i]->meal_count_lock);
		if (philos_done == data->philo_count)
			return (meals_done(data));
		if (++i >= data->philo_count)
		{
			philos_done = 0;
			i = 0;
			usleep(1000);
		}
	}
	return (NULL);
}

int	is_philo_done(t_main *data, int i)
{
	if (get_times_munched(data->philos[i]) >= data->max_meals)
		return (1);
	return (0);
}

void	*meals_done(t_main *data)
{
	if (!are_philos_alive(data))
		return (NULL);
	pthread_mutex_lock(data->philos_alive_lock);
	data->all_philos_alive = false;
	pthread_mutex_unlock(data->philos_alive_lock);
	return (NULL);
}

void	*death_checker(void *void_data)
{
	t_main	*data;
	t_philo	*current_philo;
	int		i;

	data = (t_main *)void_data;
	lets_go(data);
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
	pthread_mutex_lock(data->philos_alive_lock);
	data->all_philos_alive = false;
	pthread_mutex_unlock(data->philos_alive_lock);
	return (NULL);
}
