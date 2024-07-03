/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:08:46 by chhoflac          #+#    #+#             */
/*   Updated: 2024/07/03 16:38:50 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_philo *philo)
{
	is_eating(philo);
	is_sleeping(philo);
	is_thinking(philo);
	if (philo->is_dead)
		exit(0);
}

void	*start_routine(void *data)
{
	t_philo		*philos;

	philos = data;
	philos->is_dead = 0;
	while (1)
		routine(philos);
	return (NULL);
}
