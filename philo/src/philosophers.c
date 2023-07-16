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

void	eating(t_philo *philo);

void	*philosophise(void *philo_p)
{
	t_philo*philo = philo_p;
	if (!(philo->id % 2))
		msleep(200);
//	pthread_mutex_lock(&philo->data->stdout);
	printf("Philo %i here\n", philo->id);
//	pthread_mutex_unlock(&philo->data->stdout);
	eating(philo);
//	printf("%i says: 'nice' @ %i\n\n", philo->id, get_elapsed_time(data->start_time));
	return (NULL);
}

void	eating(t_philo *philo)
{
//	pthread_mutex_lock(left_fork(philo));
//	pthread_mutex_lock(right_fork(philo));
//	printf("there\n");
	print_action(philo, eat);
	msleep(philo->eat_time);
//	pthread_mutex_unlock(left_fork(philo));
//	pthread_mutex_unlock(right_fork(philo));
}
