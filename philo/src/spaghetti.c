/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaghetti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:01:39 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/29 16:39:33 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/philo.h"
#include "../dep/philo_fun.h"

void	print_food(int time)
{
	time = time % 10;
	if (time == 0)
		printf("spaghetti\n");
	else if (time == 1)
		printf("lasagne\n");
	else if (time == 2)
		printf("soup\n");
	else if (time == 3)
		printf("sushi\n");
	else if (time == 4)
		printf("kebab\n");
	else if (time == 5)
		printf("ramen\n");
	else if (time == 6)
		printf("borgir\n");
	else if (time == 7)
		printf("fries\n");
	else if (time == 8)
		printf("pudding\n");
	else if (time == 9)
		printf("pizza\n");
}