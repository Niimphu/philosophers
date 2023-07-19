/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosphers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:24:28 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/10 20:40:27 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	life_cycle(t_philo *philo);

void	*philosophise(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	not_yet(philo->data);
	if (!(philo->id % 2))
		msleep(10);
	life_cycle(philo);
	return (NULL);
}

void	life_cycle(t_philo *philo)
{
	while (!philo->is_dead)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

void	lets_go(t_main *data)
{
	data->start_time = get_time_ms();
	pthread_mutex_lock(&data->ready_lock);
	data->ready = true;
	pthread_mutex_unlock(&data->ready_lock);
}

void	not_yet(t_main *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->ready_lock);
		if (data->ready == true)
			break ;
		pthread_mutex_unlock(&data->ready_lock);
		msleep(1);
	}
	pthread_mutex_unlock(&data->ready_lock);
}
