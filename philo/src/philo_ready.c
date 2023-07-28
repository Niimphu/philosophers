/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ready.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:46:40 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/28 17:02:38 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

pthread_mutex_t	*get_left_fork(t_main *data, int philo_id);
pthread_mutex_t	*get_right_fork(t_main *data, int philo_id);

t_philo	*create_philo_struct(t_main *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = data->i;
	philo->eat_time = data->eat_time;
	philo->sleep_time = data->sleep_time;
	philo->start_time = data->start_time;
	philo->last_munch = 0;
	philo->times_munched = 0;
	philo->left_fork = get_left_fork(data, philo->id);
	philo->right_fork = get_right_fork(data, philo->id);
	pthread_mutex_init(&philo->last_munch_lock, NULL);
	pthread_mutex_init(&philo->meal_count_lock, NULL);
	philo->data = data;
	return (philo);
}

pthread_mutex_t	*get_left_fork(t_main *data, int philo_id)
{
	return (&data->forks[philo_id - 1]);
}

pthread_mutex_t	*get_right_fork(t_main *data, int philo_id)
{
	if (philo_id == data->philo_count)
		return (&data->forks[0]);
	else
		return (&data->forks[philo_id]);
}
