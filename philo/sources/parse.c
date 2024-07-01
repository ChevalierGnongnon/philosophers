/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:21:14 by chhoflac          #+#    #+#             */
/*   Updated: 2024/07/01 11:52:35 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_program	*initiate(int argc, char **argv)
{
	t_program	*prog;

	prog = malloc(sizeof(t_program));
	if (!prog)
		return (NULL);
	prog->nb_philos = ft_atoi(argv[1]);
	prog->timings = set_time(argv[2], argv[3], argv[4]);
	if (argc == 5)
		prog->must_eat = 0;
	else if (argc == 6)
		prog->must_eat = ft_atoi(argv[5]);
	prog->philos = create_philos(argc, argv);
	if (!prog->philos)
		return (ft_free_prog(prog));
	prog->mutexes = malloc(sizeof(pthread_mutex_t) * prog->nb_philos);
	assign_forks(prog);
	return (prog);
}

t_philo	**create_philos(int argc, char **argv)
{
	t_philo	**philosophers;
	int		n;

	n = ft_atoi(argv[1]);
	philosophers = malloc(n * sizeof(t_timings *));
	if (!philosophers)
		return (NULL);
	while (n)
	{
		philosophers[n - 1] = malloc(sizeof(t_philo));
		if (!philosophers[n - 1])
			return (ft_free_philos(philosophers, n));
		philosophers[n - 1]->timings = set_time(argv[2], argv[3], argv[4]);
		if (!philosophers[n - 1]->timings)
			return (ft_free_philos(philosophers, n));
		if (argc > 5)
			philosophers[n - 1]->must_eat = ft_atoi(argv[5]);
		else
			philosophers[n - 1]->must_eat = 0;
		philosophers[n - 1]->id = n;
		philosophers[n - 1]->left_fork = NULL;
		philosophers[n - 1]->right_fork = NULL;
		n--;
	}
	return (philosophers);
}

t_timings	*set_time(char *ttd, char *tte, char *tts)
{
	t_timings	*timings;

	timings = malloc(sizeof(t_timings));
	if (!timings)
		return (NULL);
	timings->time_to_die = ft_atollu(ttd);
	timings->time_to_eat = ft_atollu(tte);
	timings->time_to_sleep = ft_atollu(tts);
	return (timings);
}

void	assign_forks(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		prog->philos[i]->left_fork = &prog->mutexes[i];
		if (i < prog->nb_philos - 1)
			prog->philos[i]->right_fork = &prog->mutexes[i + 1];
		else
			prog->philos[i]->right_fork = &prog->mutexes[0];
		i++;
	}
}

void	create_threads(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		if (prog->philos[i]->id % 2 == 0)
			pthread_create(&prog->philos[i]->thread, NULL,
				start_routine, prog->philos[i]);
		i++;
	}
	usleep(1000);
	i = 0;
	while (i < prog->nb_philos)
	{
		if (prog->philos[i]->id % 2 == 1)
			pthread_create(&prog->philos[i]->thread, NULL,
				start_routine, prog->philos[i]);
		i++;
	}
}
