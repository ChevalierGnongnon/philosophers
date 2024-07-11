/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:08:46 by chhoflac          #+#    #+#             */
/*   Updated: 2024/07/11 17:48:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_philo *philo)
{
	is_eating(philo);
	is_sleeping(philo);
	is_thinking(philo);
}

void	*start_routine(void *data)
{
	t_philo			*philos;
	struct timeval	tv;

	philos = data;
	if (philos->nb_philos == 1)
	{
		gettimeofday(&tv, NULL);
		printf("%li %d has taken a fork\n",
			(1000 * tv.tv_sec) + (tv.tv_usec / 1000), philos->id);
		usleep(philos->timings->time_to_die * 1000);
		died(philos);
		return (NULL);
	}
	while (philos->is_dead != 1)
		routine(philos);
	return (NULL);
}
