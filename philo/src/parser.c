/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:52:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/10 20:40:37 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	init_data(char **arguments, t_main *data);

int	parse(int argn, char *arguments[], t_main *data)
{
	if (argn < 5 || argn > 6)
		return (1);
	init_data(arguments, data);
	return (0);
}

int	init_data(char *arguments[], t_main *data)
{
	data->philo_count = ft_atoi(arguments[1]);
	data->die_time = ft_atoi(arguments[2]);
	data->eat_time = ft_atoi(arguments[3]);
	data->sleep_time = ft_atoi(arguments[4]);
	data->max_meals = -1;
	data->philos = malloc(sizeof(t_philo *) * data->philo_count);
	if (arguments[5])
		data->max_meals = ft_atoi(arguments[5]);
	return (0);
}
//
//int	is_main_valid(char **arguments)
//{
//	int	i;
//
//	i = 0;
//	while (!)
//}
