/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ready.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:46:40 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/14 15:46:40 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

t_philo	*create_philo_struct(t_main *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo *));
	if (!philo)
		return (NULL);
	philo->id = data->i;
	philo->data = data;
	philo->is_dead = false;
	return (philo);
}

pthread_mutex_t	*left_fork(t_philo *philo)
{
	return (&philo->data->forks[philo->id - 1]);
}

pthread_mutex_t	*right_fork(t_philo *philo)
{
	if (philo->id == philo->data->philo_count)
		return (&philo->data->forks[0]);
	else
		return (&philo->data->forks[philo->id]);
}
