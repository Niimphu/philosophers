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
		msleep(philo->eat_time / 2);
	life_cycle(philo);
	return (NULL);
}

void	life_cycle(t_philo *philo)
{
	while (!philo->is_dead && are_philos_alive(philo->data))
	{
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
}
