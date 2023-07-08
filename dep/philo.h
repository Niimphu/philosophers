/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:47:29 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/07 15:51:51 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_input{
	int	philo_count;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	max_meals;
}	t_input;

typedef struct s_philo{
	int	start_time;
}	t_philo;

int			parse(int argn, char *arguments[], t_input *input);
int			ft_atoi(char *string);
int			create_threads(t_input *input);
void		*philosophise(t_input *input);

#endif