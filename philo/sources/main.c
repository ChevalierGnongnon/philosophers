/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:07:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/02 13:51:47 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc >= 5 && argc <= 6)
	{
		table = create_table(argc, argv);
		printf("%d %d %llu %llu %llu %d", table->nb_forks, table->nb_philo,
			table->time_to_die, table->time_to_eat, table->time_to_sleep,
			table->must_eat);
	}
}
