/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:21:14 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/24 15:50:17 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*ft_parse(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table *));
	if (!table)
		return (NULL);
	table->nb_philo = ft_atoi(argv[1]);
	if (table->nb_philo <= 0)
		return (NULL);
	table->nb_forks = table->nb_philo;
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = 1;
	return (table);
}
