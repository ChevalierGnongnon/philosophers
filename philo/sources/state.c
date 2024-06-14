/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:41:28 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/12 16:50:58 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(int time_stamp, int philosopher)
{
	printf("%d %d has taken a fork\n", time_stamp, philosopher);
	printf("%d %d has taken a fork\n", time_stamp, philosopher);
	printf("%d %d is eating\n", time_stamp, philosopher);
}

void	is_sleeping(int time_stamp, int philosopher)
{
	printf("%d %d is sleeping\n", time_stamp, philosopher);
	usleep(time_stamp);
}

void	is_thinking(int philosopher)
{
	printf("%d is thinking\n", philosopher);
}

void	died(int time_stamp, int philosopher)
{
	printf("%d %d died\n", time_stamp, philosopher);
}
