/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:19:00 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/26 20:04:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

void	print_time_and_id(t_philo *philo);
char	*get_action_string(int action);
void	colour(int action);

int	ft_atoi(const char *string)
{
	int	i;
	int	string_as_int;

	i = 0;
	string_as_int = 0;
	while (string[i])
	{
		string_as_int = string_as_int * 10 + (string[i] - '0');
		i++;
	}
	return (string_as_int);
}

int	print_action(t_philo *philo, int action)
{
	if (!are_philos_alive(philo->data))
		return (STOP);
	pthread_mutex_lock(philo->data->print_lock);
	if (action == DIE)
	{
		pthread_mutex_lock(philo->data->philos_alive_lock);
		philo->data->all_philos_alive = false;
		pthread_mutex_unlock(philo->data->philos_alive_lock);
	}
	colour(action);
	print_time_and_id(philo);
	printf("%s", get_action_string(action));
	printf(END);
	pthread_mutex_unlock(philo->data->print_lock);
	return (OK);
}

void	colour(int action)
{
	if (action == FORK)
		printf(YELLOW);
	else if (action == EAT)
		printf(BLUE);
	else if (action == SLEEP)
		printf(GREEN);
	else if (action == DIE)
		printf(RED);
}

void	print_time_and_id(t_philo *philo)
{
	printf("%i %i ", get_elapsed_time(philo->start_time), philo->id);
}

char	*get_action_string(int action)
{
	if (action == FORK)
		return ("has taken a fork\n");
	if (action == EAT)
		return ("is eating\n");
	if (action == SLEEP)
		return ("is sleeping\n");
	if (action == THINK)
		return ("is thinking\n");
	if (action == DIE)
		return ("died\n");
	return (NULL);
}
