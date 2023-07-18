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
void	lets_go(t_main *data);
void	not_yet(t_main *data);

void	*philosophise(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	if (philo->id == philo->data->philo_count)
		lets_go(philo->data);
	else
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
	data->ready = true;
}

void	not_yet(t_main *data)
{
	while (data->ready == true)
		usleep(10);
}
