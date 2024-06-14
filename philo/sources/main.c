/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:07:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/14 13:37:29 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *tab)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *) tab;
	is_eating(table->time_to_eat, table->philos[i]);
	is_sleeping(table->time_to_sleep, table->philos[i]);
	is_thinking(table->philos[i]);
	return (NULL);
}

void	go(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_create(&table->philos[i], NULL,	routine, table);
		pthread_join(table->philos[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program	*prog;

	if (argc >= 5 && argc <= 6)
	{
		prog = create(argc, argv);
		go(prog);
		ft_free(prog);
	}
}
