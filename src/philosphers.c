/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosphers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:24:28 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/07 16:24:28 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	*philosophise(t_input *input)
{
	struct timeval	time;

	if (!(input->philo_count % 2))
		usleep(10);
	gettimeofday(&time, NULL);
	printf("Philo %i here at %i:)\n", input->philo_count, time.tv_usec);
	printf("%i says: 'nice'\n", input->philo_count);
	free(input);
	return (NULL);
}
