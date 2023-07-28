/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:26:15 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/28 22:33:49 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	loop_until_death(t_main *data);


int	main(int argn, char *arguments[])
{
	t_main	data;

	if (parse(argn, arguments, &data))
		return (printf("Invalid number of arguments and/or characters\n"));
	initialise_data(&data);
	data.start_time = get_time_ms();
	create_threads(&data);
	loop_until_death(&data);
	free_all(&data);
	return (0);
}

void	loop_until_death(t_main *data)
{
	int	i;

	pthread_join(data->waiter_of_death, NULL);
	pthread_join(data->actual_waiterino, NULL);
	i = 0;
	while (i < data->philo_count)
		pthread_join(data->philos[i++]->philo_thread, NULL);
}
