/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:09 by chhoflac          #+#    #+#             */
/*   Updated: 2024/08/05 15:50:58 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef unsigned long long int	t_time;

typedef struct s_timings
{
	t_time	time_to_die;
	t_time	time_to_eat;
	t_time	time_to_sleep;	
}	t_timings;

typedef struct s_philo
{
	t_timings			*timings;
	t_time				time_left;
	int					must_eat;
	pthread_t			thread;
	int					id;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	int					is_dead;
	int					nb_philos;
}	t_philo;

typedef struct s_program
{
	t_timings			*timings;
	int					must_eat;
	int					nb_philos;
	t_philo				**philos;
	pthread_mutex_t		*mutexes;
}	t_program;

int					ft_atoi(char *str);
unsigned long long	ft_atollu(char *str);
int					check_numeric(int argc, char **argv);
int					check_args(int argc, char **argv);

t_program			*initiate(int argc, char **argv);
t_philo				**create_philos(int argc, char **argv, t_program *prog);
t_timings			*set_time(char *ttd, char *tte, char *tts, t_philo *ph);
void				assign_forks(t_program *prog);
void				create_threads(t_program *prog);

void				is_eating(t_philo *philo);
void				is_sleeping(t_philo *philo);
void				is_thinking(t_philo *philo);
void				died(t_philo *philo);
void				*start_routine(void *data);

void				*free_philos(t_program *prog);
void				*destroy_mutex(t_program *prog);
void				*ft_free(t_program *prog);

void				update_time_left(t_program *prog, int *satisfied);
t_time				gettime(void);

void				kill_philo(t_program *prog);

#endif
