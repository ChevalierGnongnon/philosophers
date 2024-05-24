/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:41:28 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/24 15:22:07 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(int time_stamp, int philosopher)
{
	printf("%d %d has taken a fork", time_stamp, philosopher);
}

void	is_eating(int time_stamp, int philosopher)
{
	printf("%d %d is eating", time_stamp, philosopher);
}

void	is_sleeping(int time_stamp, int philosopher)
{
	printf("%d %d is sleeping", time_stamp, philosopher);
}

void	is_thinking(int time_stamp, int philosopher)
{
	printf("%d %d is thinking", time_stamp, philosopher);
}

void	died(int time_stamp, int philosopher)
{
	printf("%d %d died", time_stamp, philosopher);
}
