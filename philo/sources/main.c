/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:07:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/12 14:40:29 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_table *table)
{
	free(table->philos);
	free(table);
}

void	*routine(void *test)
{
	test = (int *) test;
	printf("time_to_eat\n");
	return (NULL);
}

void	go(t_table *table)
{
	int		i;
	void	*test;

	test = NULL;
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
	t_table	*table;

	if (argc >= 5 && argc <= 6)
	{
		table = create_table(argc, argv);
		go(table);
		ft_free(table);
	}
}
