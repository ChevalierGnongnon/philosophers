/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:07:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/07/02 15:40:01 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_program *prog, int *satisfied)
{
	int	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		if (prog->philos[i]->is_dead)
			return (0);
		i++;
	}
	return ((*satisfied) < prog->nb_philos);
}

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
			prog->philos[i]->is_dead = 1;
			died(prog->philos[i]);
			break ;
		}
		else if (prog->philos[i]->must_eat == 0)
			(*satisfied)++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program	*prog;
	int			satisfied;
	int			ref_time;
	int			delta_time;
	int			i;

	i = 0;
	satisfied = 0;
	if (argc >= 5)
	{
		prog = initiate(argc, argv);
		create_threads(prog);
		usleep(1000);
		ref_time = gettime();
		while (check_dead(prog, &satisfied))
		{
			delta_time = gettime();
			if (delta_time - ref_time >= 1000)
			{
				update_time_left(prog, &satisfied);
				ref_time = delta_time;
			}
		}
		while (i < prog->nb_philos)
		{
			pthread_mutex_destroy(&prog->mutexes[i]);
			i++;
		}
	}
}
