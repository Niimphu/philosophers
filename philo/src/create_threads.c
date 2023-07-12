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

t_philo	*create_philo_struct(t_main *data);
void	free_philos(t_main *data);

int	create_threads(t_main *data)
{
	pthread_t	philo_thread;

	data->i = 1;
	data->start_time = get_time_ms();
	while (data->i <= data->philo_count)
	{
		data->philos[data->i - 1] = create_philo_struct(data);
		pthread_create(&philo_thread, NULL, (void *)philosophise, (void *)data->philos[data->i - 1]);
		data->i++;
	}
	msleep(1000);
	free_philos(data);
	return (0);
}

t_philo	*create_philo_struct(t_main *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo *));
	philo->id = data->i;
	philo->data = data;
	return (philo);
}

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
