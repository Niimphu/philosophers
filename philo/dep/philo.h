/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:47:29 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/10 20:40:37 by yiwong           ###   ########.fr       */
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

typedef struct s_philo t_philo;


typedef struct s_main{
	int				philo_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_meals;
	int				start_time;
	int				i;
	t_philo			**philos;
	pthread_mutex_t	*forks;
}	t_main;

typedef struct s_philo{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_main	*data;
}	t_philo;

int				parse(int argn, char *arguments[], t_main *data);
int				initialise_data(t_main *data);
int				ft_atoi(char *string);
int				create_threads(t_main *data);
void			*philosophise(t_philo *philo);
int				get_time_ms(void);
int				get_elapsed_time(int start_time);
void			msleep(int time_ms);
t_philo			*create_philo_struct(t_main *data);
void			free_philos(t_main *data);
pthread_mutex_t	*get_left_fork(t_philo *philo);
pthread_mutex_t	*get_right_fork(t_philo *philo);
#endif