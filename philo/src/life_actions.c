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

int	put_down_forks(t_philo *philo);

int	eating(t_philo *philo)
{
//	printf("\033[0;35m%i %i is trying to eat\n\033[0m", get_elapsed_time(philo->start_time), philo->id);
	if (!are_philos_alive(philo->data))
		return (STOP);
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, FORK);
	if (!are_philos_alive(philo->data))
		return (STOP + put_down_forks(philo));
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, FORK);
	if (!are_philos_alive(philo->data))
		return (STOP + put_down_forks(philo));
	pthread_mutex_lock(&philo->last_munch_lock);
	philo->last_munch = get_elapsed_time(philo->start_time);
	pthread_mutex_unlock(&philo->last_munch_lock);
	print_action(philo, EAT);
	pthread_mutex_lock(&philo->meal_count_lock);
	pthread_mutex_unlock(&philo->meal_count_lock);
	msleep(philo->eat_time);
	philo->times_munched++;
	pthread_mutex_unlock(philo->left_fork);
//	printf("%i %i put away fork\n", get_elapsed_time(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->right_fork);
//	printf("%i %i put away fork\n", get_elapsed_time(philo->start_time), philo->id);
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

int	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}
