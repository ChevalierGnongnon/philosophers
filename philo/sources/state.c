/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:41:28 by chhoflac          #+#    #+#             */
/*   Updated: 2024/07/02 17:33:36 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philo *philosopher)
{
	struct timeval	tv;

	pthread_mutex_lock(philosopher->left_fork);
	gettimeofday(&tv, NULL);
	if (!philosopher->is_dead)
		printf("%li %d has taken a fork\n",
			(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
	pthread_mutex_lock(philosopher->right_fork);
	if (!philosopher->is_dead)
		printf("%li %d has taken a fork\n",
			(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
	if (!philosopher->is_dead)
		printf("%li %d is eating\n",
			(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
	usleep(philosopher->timings->time_to_eat * 1000);
	philosopher->time_left = philosopher->timings->time_to_die;
	if (philosopher->must_eat > 0)
		philosopher->must_eat--;
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
}

void	is_sleeping(t_philo	*philosopher)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (!philosopher->is_dead)
	{
		printf("%li %d is sleeping\n",
			(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
	}
	usleep(philosopher->timings->time_to_sleep * 1000);
}

void	is_thinking(t_philo *philosopher)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (!philosopher->is_dead)
	{
		printf("%li %d is thinking\n",
			(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
	}
}

void	died(t_philo *philosopher)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	usleep(1000);
	printf("%li %d died\n",
		(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philosopher->id);
}
