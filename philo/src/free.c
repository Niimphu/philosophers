/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:37:15 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/28 16:37:15 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	free_all(t_main *data)
{
	if (data->forks)
	{
		destroy_data_mutexes(data, data->forks);
		free(data->forks);
		data->forks = NULL;
	}
	free_philos(data);
}

void	free_philos(t_main *data)
{
	int	i;

	if (!data->philos)
		return ;
	i = 0;
	while (i < data->philo_count)
	{
		destroy_philo_mutexes(data->philos[i]);
		free(data->philos[i]);
		data->philos[i++] = NULL;
	}
	free(data->philos);
	data->philos = NULL;
}
