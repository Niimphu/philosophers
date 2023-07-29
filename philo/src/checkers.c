/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:08 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/29 16:47:21 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

bool	ready_check(t_main *data);

bool	continue_program(t_main *data)
{
	bool	philos_are_alive;

	pthread_mutex_lock(data->philos_alive_lock);
	philos_are_alive = data->all_philos_alive;
	pthread_mutex_unlock(data->philos_alive_lock);
	return (philos_are_alive);
}

void	lets_go(t_main *data)
{
	pthread_mutex_lock(data->ready_lock);
	data->ready = true;
	data->start_time = get_time_ms();
	pthread_mutex_unlock(data->ready_lock);
}

void	not_yet(t_main *data)
{
	while (!ready_check(data))
		;
}

bool	ready_check(t_main *data)
{
	bool	we_ready;

	pthread_mutex_lock(data->ready_lock);
	we_ready = data->ready;
	pthread_mutex_unlock(data->ready_lock);
	return (we_ready);
}

int	get_times_munched(t_philo *philo)
{
	int	meals_eaten;

	pthread_mutex_lock(&philo->last_munch_lock);
	meals_eaten = philo->times_munched;
	pthread_mutex_unlock(&philo->last_munch_lock);
	return (meals_eaten);
}
