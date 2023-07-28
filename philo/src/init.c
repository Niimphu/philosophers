/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:23:20 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/28 22:43:51 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	allocate_mutex_memory(t_main *data);
int	invalid_arguments(char *arguments[]);

int	parse(int argn, char *arguments[], t_main *data)
{
	if (argn < 5 || argn > 6)
		return (STOP);
	if (invalid_arguments(arguments))
		return (STOP);
	data->philo_count = ft_atoi(arguments[1]);
	data->die_time = ft_atoi(arguments[2]);
	data->eat_time = ft_atoi(arguments[3]);
	data->sleep_time = ft_atoi(arguments[4]);
	data->max_meals = -1;
	data->write_check = 0;
	if (arguments[5])
		data->max_meals = ft_atoi(arguments[5]);
	return (0);
}

int	initialise_data(t_main *data)
{
	int	i;

	if (allocate_mutex_memory(data) == -1)
		return (-1);
	i = 0;
	data->ready = false;
	data->all_philos_alive = true;
	while (i < data->philo_count)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(data->print_lock, NULL);
	pthread_mutex_init(data->ready_lock, NULL);
	pthread_mutex_init(data->philos_alive_lock, NULL);
	return (0);
}

int	allocate_mutex_memory(t_main *data)
{
	data->philos = malloc(sizeof(t_philo *) * data->philo_count);
	if (!data->philos)
		return (-1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (-1);
	data->print_lock = malloc(sizeof(pthread_mutex_t));
	if (!data->print_lock)
		return (-1);
	data->ready_lock = malloc(sizeof(pthread_mutex_t));
	if (!data->ready_lock)
		return (-1);
	data->philos_alive_lock = malloc(sizeof(pthread_mutex_t));
	if (!data->philos_alive_lock)
		return (-1);
	return (0);
}

int	invalid_arguments(char *arguments[])
{
	int	i;
	int	j;

	i = 1;
	while (arguments[i])
	{
		j = 0;
		if (arguments[i][j] == '+')
			j++;
		while (arguments[i][j])
		{
			if (arguments[i][j] < '0' || arguments[i][j] > '9')
				return (STOP);
			j++;
		}
		i++;
	}
	return (OK);
}
