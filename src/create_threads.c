/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:15:02 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/07 15:51:51 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

t_input	*copy_data(t_input *input);

int	create_threads(t_input *input)
{
	pthread_t	philo;

	while (input->philo_count > 0)
	{
		pthread_create(&philo, NULL, (void *)philosophise, copy_data(input));
		input->philo_count--;
	}
	usleep(50);
	return (0);
}

t_input	*copy_data(t_input *input)
{
	t_input	*copy;

	copy = malloc(sizeof(t_input *));
	if (!copy)
		return (NULL);
	copy->philo_count = input->philo_count;
	copy->die_time = input->die_time;
	copy->eat_time = input->eat_time;
	copy->sleep_time = input->sleep_time;
	copy->max_meals = input->max_meals;
	return (copy);
}
