/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:27:01 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/07 16:27:01 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec / 1000);
}

int	get_elapsed_time(int start_time)
{
	int	time;

	time = get_time_ms();
	return (time - start_time);
}

void	msleep(int time_ms)
{
	usleep(time_ms * 1000);
}
