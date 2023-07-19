/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:28:07 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/19 19:28:28 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	*death_checker(void *void_data)
{
	t_main	*data;
	int		i;
	t_philo	*current_philo;

	data = (t_main *)void_data;
	lets_go(data);
	pthread_mutex_init(&data->philos_alive_lock, NULL);
	i = 0;
	while (1)
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
}

void	*death(t_main *data, t_philo *dead_philo)
{
	print_action(dead_philo, die);
	pthread_mutex_lock(&data->philos_alive_lock);
	data->all_philos_alive = false;
	pthread_mutex_unlock(&data->philos_alive_lock);
	return (NULL);
}
