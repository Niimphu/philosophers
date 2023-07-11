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

int	ft_atoi(char *string)
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
