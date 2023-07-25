/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_checkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/24 18:37:08 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

bool	ready_check(t_main *data);

bool	are_philos_alive(t_main *data)
{
	bool	philos_are_alive;

	pthread_mutex_lock(data->philos_alive_lock);
	philos_are_alive = data->all_philos_alive;
	pthread_mutex_unlock(data->philos_alive_lock);
	return (philos_are_alive);
}

void	lets_go(t_main *data)
{
	data->start_time = get_time_ms();
	pthread_mutex_lock(data->ready_lock);
	data->ready = true;
	pthread_mutex_unlock(data->ready_lock);
}

void	not_yet(t_main *data)
{
	while (!ready_check(data))
		msleep(1);
	pthread_mutex_unlock(data->ready_lock);
}

bool	ready_check(t_main *data)
{
	bool	we_ready;

	pthread_mutex_lock(data->ready_lock);
	we_ready = data->ready;
	pthread_mutex_unlock(data->ready_lock);
	return (we_ready);
}
