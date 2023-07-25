/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:57:18 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/14 15:57:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	destroy_data_mutexes(t_main *data, pthread_mutex_t *forks);
void	kill_mutex(pthread_mutex_t *mutex);
void	destroy_philo_mutexes(t_philo *philo);

void	free_all(t_main *data)
{
	if (data->forks)
	{
		destroy_data_mutexes(data, data->forks);
		free(data->forks);
		data->forks = NULL;
	}
	free_philos(data);
}

void	free_philos(t_main *data)
{
	int	i;

	if (!data->philos)
		return ;
	i = 0;
	while (i < data->philo_count)
	{
		destroy_philo_mutexes(data->philos[i]);
		free(data->philos[i]);
		data->philos[i++] = NULL;
	}
	free(data->philos);
	data->philos = NULL;
}

void	destroy_data_mutexes(t_main *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
		kill_mutex(&forks[i++]);
	kill_mutex(&data->stdout);
	kill_mutex(&data->ready_lock);
	kill_mutex(&data->philos_alive_lock);
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
