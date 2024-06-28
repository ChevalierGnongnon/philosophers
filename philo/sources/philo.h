/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:09 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/20 13:19:57 by chhoflac         ###   ########.fr       */
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

typedef struct s_timings
{
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;	
}	t_timings;

typedef struct s_philo
{
	t_timings			*timings;
	int					must_eat;
	int					id;
	pthread_mutex_t		right_fork;
	pthread_mutex_t		left_fork;
}	t_philo;

typedef struct s_program
{
	t_timings			*timings;
	int					must_eat;
	int					nb_philos;
	t_philo				**philos;
}	t_program;

/*
 * Utils
 */
int					ft_atoi(char *str);
unsigned long long	ft_atollu(char *str);

/*
 * Parsing
 */
t_program			*initiate(int argc, char **argv);
t_philo				**create_philos(int argc, char **argv);
t_timings			*set_time(char *ttd, char *tte, char *tts);

/*
 * Current state
 */
void				is_eating(int time_stamp, int philo);
void				is_sleeping(int time_stamp, int philo);
void				is_thinking(int philo);
void				is_dead(int time_stamp, int philo);

/*
 * Free memory allocation
 */
void				*ft_free_timings(t_timings *timings);
void				*ft_free_prog(t_program *program);
void				*ft_free_philos(t_philo **philos, int nb_philos);
void				ft_clear(t_program *prog);

#endif
