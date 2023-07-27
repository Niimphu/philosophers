/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:47:29 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/26 20:04:17 by yiwong           ###   ########.fr       */
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

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

# define STOP -1
# define OK 0

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
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*ready_lock;
	pthread_mutex_t	*philos_alive_lock;
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

int		parse(int argn, char *arguments[], t_main *data);
int		initialise_data(t_main *data);
int		create_threads(t_main *data);
t_philo	*create_philo_struct(t_main *data);

void	not_yet(t_main *data);
void	lets_go(t_main *data);
int		get_times_munched(t_philo *philo);

void	*meal_checker(void *void_data);
void	*death_checker(void *void_data);
void	*philosophise(void *philo_p);

int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);
int		print_action(t_philo *philo, int action);

bool	are_philos_alive(t_main *data);

int		get_time_ms(void);
int		get_elapsed_time(int start_time);
void	msleep(unsigned long long time_ms);

void	free_philos(t_main *data);
void	free_all(t_main *data);

int		ft_atoi(const char *string);

#endif