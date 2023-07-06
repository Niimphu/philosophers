/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:26:15 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/06 20:26:15 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	main(int argn, char *arguments[])
{
	t_params	vars;

	if (parse(argn, arguments, &vars))
		return (printf("Invalid number of arguments\n"));
	printf("Number of philos: %i\n Time to die: %i\n Time to eat: %i\n Time to sleep: %i\n Max number of means: %i\n", vars.philo_count, vars.die_time, vars.eat_time, vars.sleep_time, vars.max_meals);
	return (0);
}
