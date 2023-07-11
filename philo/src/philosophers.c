/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosphers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:24:28 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/10 20:40:27 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	*philosophise(t_philo *philo)
{
	t_main	*data;

	data = philo->data;
	printf("Philo %i here at %i:)\n", philo->id, get_elapsed_time(data->start_time));
	if (!(philo->id % 2))
		msleep(100);
	printf("%i says: 'nice' @ %i\n\n", philo->id, get_elapsed_time(data->start_time));
	return (NULL);
}
