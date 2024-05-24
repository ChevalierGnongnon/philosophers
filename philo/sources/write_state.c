/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:41:28 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/24 11:03:42 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(double time_stamp, int philosopher)
{
	printf("%d %d has taken a fork", time_stamp, philosopher);
}

void	is_eating(double time_stamp, int philosopher)
{
	printf("%d %d is eating", time_stamp, philosopher);
}

void	is_sleeping(double time_stamp, int philosopher)
{
	printf("%d %d is sleeping", time_stamp, philosopher);
}

void	is_thinking(double time_stamp, int philosopher)
{
	printf("%d %d is thinking", time_stamp, philosopher);
}

void	died(double time_stamp, int philosopher)
{
	printf("%d %d died", time_stamp, philosopher);
}
