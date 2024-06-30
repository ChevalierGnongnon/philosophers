/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:07:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/30 17:01:51 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		if (prog->philos[i]->is_dead)
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_program	*prog;
	int			i;

	i = 0;
	if (argc >= 5)
	{
		prog = initiate(argc, argv);
		create_threads(prog->philos);
		while (check_dead(prog))
		{
			i = 0;
			while (i < prog->nb_philos)
			{
				prog->philos[i]->time_left--;
				if (prog->philos[i]->time_left == 0)
				{
					prog->philos[i]->is_dead = 1;
					died(prog->philos[i]);
					break;
				}
				i++;
			}
			usleep(1000);
		}
	}
}
