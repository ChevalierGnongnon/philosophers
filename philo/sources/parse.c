/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:21:14 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/02 15:10:08 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*create_table(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->nb_philo = ft_atoi(argv[1]);
	table->nb_forks = table->nb_philo;
	table->time_to_die = ft_atollu(argv[2]);
	table->time_to_eat = ft_atollu(argv[3]);
	table->time_to_sleep = ft_atollu(argv[4]);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = 0;
	table->philos = malloc(sizeof(pthread_t) * table->nb_philo);
	if (!table->philos)
		return (NULL);
	return (table);
}