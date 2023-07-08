/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:26:15 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/07 15:51:51 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"

int	main(int argn, char *arguments[])
{
	t_input	input;

	if (parse(argn, arguments, &input))
		return (printf("Invalid number of arguments\n"));
	create_threads(&input);
	return (0);
}
