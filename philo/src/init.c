/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:23:20 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/12 20:23:20 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	initialise_data(t_main *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo *) * data->philo_count);
	if (!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t *) * data->philo_count);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->philo_count)
		pthread_mutex_init(&data->forks[i++], NULL);
	return (0);
}
