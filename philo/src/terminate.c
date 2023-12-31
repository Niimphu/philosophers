/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:57:18 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/26 20:04:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	kill_mutex(pthread_mutex_t *mutex);

void	destroy_data_mutexes(t_main *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
		kill_mutex(&forks[i++]);
	kill_mutex(data->print_lock);
	free(data->print_lock);
	kill_mutex(data->ready_lock);
	free(data->ready_lock);
	kill_mutex(data->philos_alive_lock);
	free(data->philos_alive_lock);
}

void	destroy_philo_mutexes(t_philo *philo)
{
	kill_mutex(&philo->last_munch_lock);
	kill_mutex(&philo->meal_count_lock);
}

void	kill_mutex(pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
	pthread_mutex_destroy(mutex);
}

void	unlock_forks(t_main *data)
{
	int	i;

	msleep(100);
	i = 0;
	while (i < data->philo_count)
		pthread_mutex_unlock(&data->forks[i++]);
	pthread_mutex_unlock(data->print_lock);
}
