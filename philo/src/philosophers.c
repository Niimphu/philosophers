/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:24:28 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/28 17:03:24 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	life_cycle(t_philo *philo);
void	*single_philo(t_philo *philo);

void	*philosophise(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	not_yet(philo->data);
	if (!(philo->id % 2))
		msleep(philo->eat_time - 1);
	if (philo->data->philo_count == 1)
		return (single_philo(philo));
	life_cycle(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->data->print_lock);
	return (NULL);
}

void	life_cycle(t_philo *philo)
{
	while (are_philos_alive(philo->data))
	{
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
}

void	*single_philo(t_philo *philo)
{
	print_action(philo, FORK);
	msleep(philo->data->die_time);
	return (NULL);
}
