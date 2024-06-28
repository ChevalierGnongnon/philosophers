/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:41:28 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/28 16:17:13 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(int time_stamp, t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	printf("%d %d has taken a fork\n", time_stamp, philosopher->id);
	pthread_mutex_lock(philosopher->right_fork);
	printf("%d %d has taken a fork\n", time_stamp, philosopher->id);
	printf("%d %d is eating\n", time_stamp, philosopher->id);
	usleep(philosopher->timings->time_to_eat);
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
}

void	is_sleeping(int time_stamp, t_philo	*philosopher)
{
	printf("%d %d is sleeping\n", time_stamp, philosopher->id);
	usleep(time_stamp);
}

void	is_thinking(t_philo *philosopher)
{
	printf("%d is thinking\n", philosopher->id);
}

void	died(int time_stamp, t_philo *philosopher)
{
	printf("%d %d died\n", time_stamp, philosopher->id);
}
