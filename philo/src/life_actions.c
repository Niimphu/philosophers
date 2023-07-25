/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:56:25 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/25 13:57:31 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, FORK);
	pthread_mutex_lock(&philo->last_munch_lock);
	philo->last_munch = get_elapsed_time(philo->start_time);
	pthread_mutex_unlock(&philo->last_munch_lock);
	print_action(philo, EAT);
	msleep(philo->eat_time);
	pthread_mutex_lock(&philo->meal_count_lock);
	philo->times_munched++;
	pthread_mutex_unlock(&philo->meal_count_lock);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (!are_philos_alive(philo->data))
		return (STOP);
	return (OK);
}

int	sleeping(t_philo *philo)
{
	print_action(philo, SLEEP);
	msleep(philo->sleep_time);
	if (!are_philos_alive(philo->data))
		return (STOP);
	return (OK);
}

int	thinking(t_philo *philo)
{
	return (print_action(philo, THINK));
}
