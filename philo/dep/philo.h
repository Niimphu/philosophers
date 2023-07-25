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
# include <stdbool.h>

# define fork 0
# define eat 1
# define sleep 2
# define think 3
# define die 4

# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define END "\033[0m"

typedef struct s_philo	t_philo;

typedef struct s_main{
	pthread_t		waiter_of_death;
	pthread_t		actual_waiterino;
	int				philo_count;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_meals;
	int				start_time;
	int				i;
	bool			ready;
	bool			all_philos_alive;
	t_philo			**philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	stdout;
	pthread_mutex_t	ready_lock;
	pthread_mutex_t	philos_alive_lock;
}	t_main;

typedef struct s_philo{
	pthread_t		philo_thread;
	int				id;
	int				eat_time;
	int				sleep_time;
	int				start_time;
	int				last_munch;
	int				times_munched;
	bool			is_dead;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	last_munch_lock;
	pthread_mutex_t	meal_count_lock;
	t_main			*data;
}	t_philo;

int				parse(int argn, char *arguments[], t_main *data);
int				initialise_data(t_main *data);
int				ft_atoi(const char *string);
int				create_threads(t_main *data);
void			*philosophise(void *philo_p);
int				get_time_ms(void);
int				get_elapsed_time(int start_time);
void			msleep(unsigned long long time_ms);
t_philo			*create_philo_struct(t_main *data);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			*meal_checker(void *void_data);
void			*death_checker(void *void_data);
void			*death(t_main *data, t_philo *dead_philo);
bool			are_philos_alive(t_main *data);
void			not_yet(t_main *data);
void			lets_go(t_main *data);
void			free_philos(t_main *data);
void			free_all(t_main *data);
void			print_action(t_philo *philo, int action);

#endif