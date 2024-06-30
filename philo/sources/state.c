/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:41:28 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/30 16:04:18 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philo *philosopher)
{
	struct timeval	tv;

	pthread_mutex_lock(philosopher->left_fork);
	gettimeofday(&tv, NULL);
	printf("%li %d has taken a fork\n",
		(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
	pthread_mutex_lock(philosopher->right_fork);
	printf("%li %d has taken a fork\n",
		(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
	printf("%li %d is eating\n",
		(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
	usleep(philosopher->timings->time_to_eat * 1000);
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
}

void	is_sleeping(t_philo	*philosopher)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%li %d is sleeping\n",
		(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
	usleep(philosopher->timings->time_to_sleep * 1000);
}

void	is_thinking(t_philo *philosopher)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%li %d is thinking\n",
		(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
}

void	died(t_philo *philosopher)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%li %d died\n",
		(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
}
