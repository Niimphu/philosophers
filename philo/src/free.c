/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:57:18 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/14 15:57:18 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	free_philos(t_main *data)
{
	int	i;

	if (!data->philos)
		return ;
	i = 0;
	while (i < data->philo_count)
	{
		free(data->philos[i]);
		data->philos[i++] = NULL;
	}
	free(data->philos);
	data->philos = NULL;
}
