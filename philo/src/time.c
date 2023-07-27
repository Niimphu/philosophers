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
	return ((int)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

int	get_elapsed_time(int start_time)
{
	int	time;

	time = get_time_ms();
	return (time - start_time);
}

void	msleep(unsigned long long time_ms)
{
	unsigned long long	start;
	unsigned long long	elapsed;

	start = get_time_ms();
	elapsed = get_time_ms();
	usleep(time_ms * 980);
	while (elapsed - start < time_ms)
	{
		usleep(500);
		elapsed = get_time_ms();
	}
}
