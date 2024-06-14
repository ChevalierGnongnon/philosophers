/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:21:14 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/14 16:18:46 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_program	*initiate(int argc, char **argv)
{
	t_program	*prog;
	t_philo		*philo;

	prog = malloc(sizeof(t_program));
	if (!prog)
		return (NULL);
	prog->nb_philos = ft_atoi(argv[1]);
	prog->timings = set_time(argc, argv);
	if (argc > 5)
		prog->must_eat = ft_atoi(argv[5]);
	else
		prog->must_eat = 0;
	philo = create_philos(argc, argv);
	if (!philo)
		return (ft_free());
}

t_philo	**create_philos(int argc, char **argv)
{
	t_philo	**philosophers;
	int		n;

	n = argv[1];
	philosophers = malloc(n);
	while (--n)
	{
		philosophers[n] = malloc(sizeof(t_philo *));
		philosophers[n]->timings = set_time(argc, argv);
		if (!philosophers[n] || philosophers[n]->timings)
			return (ft_free(), NULL);
		if (argc > 5)
			philosophers[n]->must_eat = ft_atoi(argv[5]);
		else
			philosophers[n]->must_eat = 0;
		philosophers[n]->id = n + 1;
	}
	return (philosophers);
}

t_timings	*set_time(int argc, char **argv)
{
	t_timings	*timings;

	timings = malloc(sizeof(t_timings));
	if (!timings)
		return (NULL);
	timings->time_to_die = argv[2];
	timings->time_to_eat = argv[3];
	timings->time_to_sleep = argv[4];
}
