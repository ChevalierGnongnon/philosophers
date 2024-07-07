/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:08:46 by chhoflac          #+#    #+#             */
/*   Updated: 2024/07/07 17:51:58 by chhoflac         ###   ########.fr       */
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
	t_philo	*philos;

	philos = data;
	if (philos->nb_philos == 1)
	{
		usleep(philos->timings->time_to_die);
		died(philos);
		return (NULL);
	}
	while (philos->is_dead != 1)
		routine(philos);
	return (NULL);
}
