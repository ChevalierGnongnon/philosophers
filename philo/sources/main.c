/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:07:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/05/24 15:47:46 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc >= 5 && argc < 7)
	{
		table = ft_parse(argc, argv);
		if (!table)
			printf("ERROR");
		else
		{
			printf("philos : %d forks : %d\n", table->nb_philo, table->nb_forks);
			printf("die : %d eat: %d sleep: %d\n", table->time_to_die, table->time_to_eat, table->time_to_sleep);
		}
	}
}
