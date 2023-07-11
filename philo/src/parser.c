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

int	create_struct(char **arguments, t_main *input);

int	parse(int argn, char *arguments[], t_main *data)
{
	if (argn < 5 || argn > 6)
		return (1);
	create_struct(arguments, data);
	return (0);
}

int	create_struct(char *arguments[], t_main *input)
{
	input->philo_count = ft_atoi(arguments[1]);
	input->die_time = ft_atoi(arguments[2]);
	input->eat_time = ft_atoi(arguments[3]);
	input->sleep_time = ft_atoi(arguments[4]);
	input->max_meals = -1;
	input->philos = malloc(sizeof(t_philo *) * input->philo_count);
	if (arguments[5])
		input->max_meals = ft_atoi(arguments[5]);
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
