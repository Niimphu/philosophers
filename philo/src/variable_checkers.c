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

bool	are_philos_alive(t_main *data)
{
	bool	philos_are_alive;

	pthread_mutex_lock(&data->philos_alive_lock);
	philos_are_alive = data->all_philos_alive;
	pthread_mutex_unlock(&data->philos_alive_lock);
	return (philos_are_alive);
}
