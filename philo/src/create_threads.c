/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:15:02 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/10 20:40:27 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	create_threads(t_main *data)
{
	pthread_t	philo_thread;

	data->i = 1;
	data->start_time = get_time_ms();
	while (data->i <= data->philo_count)
	{
		data->philos[data->i - 1] = create_philo_struct(data);
		pthread_create(&philo_thread, NULL, (void *)philosophise,
			(void *)data->philos[data->i - 1]);
		data->i++;
	}
	msleep(1000);
	free_philos(data);
	return (0);
}
