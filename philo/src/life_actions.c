/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:56:25 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/28 19:18:55 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	eating(t_philo *philo)
{
	if (!continue_program(philo->data))
		return (STOP);
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, FORK);
	if (!continue_program(philo->data))
		return (STOP);
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, FORK);
	if (!continue_program(philo->data))
		return (STOP);
	pthread_mutex_lock(&philo->last_munch_lock);
	philo->last_munch = get_elapsed_time(philo->start_time);
	pthread_mutex_unlock(&philo->last_munch_lock);
	print_action(philo, EAT);
	pthread_mutex_lock(&philo->meal_count_lock);
	pthread_mutex_unlock(&philo->meal_count_lock);
	msleep(philo->eat_time);
	pthread_mutex_lock(&philo->last_munch_lock);
	philo->times_munched++;
	pthread_mutex_unlock(&philo->last_munch_lock);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (!continue_program(philo->data))
		return (STOP);
	return (OK);
}

int	sleeping(t_philo *philo)
{
	print_action(philo, SLEEP);
	msleep(philo->sleep_time);
	if (!continue_program(philo->data))
		return (STOP);
	return (OK);
}

int	thinking(t_philo *philo)
{
	return (print_action(philo, THINK));
}
