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

int	parse(int argn, char *arguments[], t_main *data)
{
	if (argn < 5 || argn > 6)
		return (1);
	data->philo_count = ft_atoi(arguments[1]);
	data->die_time = ft_atoi(arguments[2]);
	data->eat_time = ft_atoi(arguments[3]);
	data->sleep_time = ft_atoi(arguments[4]);
	data->max_meals = -1;
	if (arguments[5])
		data->max_meals = ft_atoi(arguments[5]);
	return (0);
}

int	initialise_data(t_main *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo *) * data->philo_count);
	if (!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (1);
	i = 0;
	data->ready = false;
	data->all_philos_alive = true;
	while (i < data->philo_count)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->stdout, NULL);
	pthread_mutex_init(&data->ready_lock, NULL);
	return (0);
}
