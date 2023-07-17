/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:19:00 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/06 21:19:00 by yiwong           ###   ########.fr       */
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

void	print(t_main *data, char *string)
{
	pthread_mutex_lock(&data->stdout);
	printf("%s\n", string);
	pthread_mutex_unlock(&data->stdout);
}

void	print_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->data->stdout);
	colour(action);
	print_time_and_id(philo);
	printf("%s", get_action_string(action));
	printf(END);
	pthread_mutex_unlock(&philo->data->stdout);
}

void	colour(int action)
{
	if (action == fork)
		printf(YELLOW);
	else if (action == eat)
		printf(BLUE);
	else if (action == sleep)
		printf(GREEN);
	else if (action == die)
		printf(RED);
}

void	print_time_and_id(t_philo *philo)
{
	printf("%i %i ", get_elapsed_time(philo->start_time), philo->id);
}

char	*get_action_string(int action)
{
	if (action == fork)
		return ("has taken a fork\n");
	if (action == eat)
		return ("is eating\n");
	if (action == sleep)
		return ("is sleeping\n");
	if (action == think)
		return ("is thinking\n");
	if (action == die)
		return ("died\n");
	return (NULL);
}
