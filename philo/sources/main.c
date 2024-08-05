/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:07:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/08/05 15:51:44 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_program *prog, int *satisfied)
{
	int	i;

	i = 0;
	if (prog->nb_philos == 1)
		return (usleep(prog->timings->time_to_die * 1000), 0);
	while (i < prog->nb_philos)
	{
		if (prog->philos[i]->is_dead)
			return (0);
		i++;
	}
	return ((*satisfied) < prog->nb_philos);
}

void	kill_philo(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philos)
		prog->philos[i++]->is_dead = 1;
	i = 0;
	while (i < prog->nb_philos)
		pthread_detach(prog->philos[i++]->thread);
}

void	diner(t_program *prog, int *satisfied)
{
	t_time	delta_time;
	t_time	ref_time;

	ref_time = gettime();
	while (check_dead(prog, satisfied))
	{
		delta_time = gettime();
		if (delta_time - ref_time >= 1000)
		{
			update_time_left(prog, satisfied);
			ref_time = delta_time;
		}
	}
}

int	main(int argc, char **argv)
{
	t_program	*prog;
	int			satisfied;
	int			i;

	i = 0;
	satisfied = 0;
	if ((argc == 5 || argc == 6) && check_args(argc, argv))
	{
		prog = initiate(argc, argv);
		create_threads(prog);
		usleep(1000);
		diner(prog, &satisfied);
		usleep(prog->timings->time_to_eat);
		usleep(prog->timings->time_to_sleep);
		ft_free(prog);
	}
}
