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
	data->i = 1;
	data->start_time = get_time_ms();
	while (data->i <= data->philo_count)
	{
		data->philos[data->i - 1] = create_philo_struct(data);
		fprintf(stderr, "%d\n", data->philos[data->i - 1]->data->i);
		fprintf(stderr, "%d\n", data->philos[data->i - 1]->id);
		pthread_create(&data->philos[data->i - 1]->philo_thread, NULL, philosophise,
			(void *)data->philos[data->i - 1]);
		data->i++;
	}
	msleep(10000);
	free_all(data);
	return (0);
}
