/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:26:15 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/10 20:40:27 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	main(int argn, char *arguments[])
{
	t_main	data;

	if (parse(argn, arguments, &data))
		return (printf("Invalid number of arguments\n"));
	initialise_data(&data);
	data.start_time = get_time_ms();
	create_threads(&data);
	return (0);
}
