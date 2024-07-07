/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:38:13 by chhoflac          #+#    #+#             */
/*   Updated: 2024/07/07 17:52:28 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec);
}

void	update_time_left(t_program *prog, int *satisfied)
{
	int	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		prog->philos[i]->time_left--;
		if (prog->philos[i]->time_left == 0)
		{
			kill_philo(prog);
			died(prog->philos[i]);
			break ;
		}
		else if (prog->philos[i]->must_eat == 0)
			(*satisfied)++;
		i++;
	}
}
