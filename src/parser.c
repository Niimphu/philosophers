/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:52:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/06 20:52:39 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	create_struct(char **arguments, t_params *vars);

int	parse(int argn, char *arguments[], t_params *vars)
{
	if (argn < 5 || argn > 6)
		return (1);
	create_struct(arguments, vars);
	return (0);
}

int	create_struct(char *arguments[], t_params *vars)
{
	vars->philo_count = ft_atoi(arguments[1]);
	vars->die_time = ft_atoi(arguments[2]);
	vars->eat_time = ft_atoi(arguments[3]);
	vars->sleep_time = ft_atoi(arguments[4]);
	vars->max_meals = -1;
	if (arguments[5])
		vars->max_meals = ft_atoi(arguments[5]);
	return (0);
}
//
//int	is_input_valid(char **arguments)
//{
//	int	i;
//
//	i = 0;
//	while (!)
//}
