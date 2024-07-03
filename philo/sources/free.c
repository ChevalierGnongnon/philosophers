/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:46:31 by chhoflac          #+#    #+#             */
/*   Updated: 2024/07/03 16:04:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_philos(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		free(prog->philos[i]->timings);
		pthread_detach(prog->philos[i]->thread);
		free(prog->philos[i]);
		i++;
	}
	free(prog->philos);
	return (NULL);
}

void	*destroy_mutex(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		pthread_mutex_destroy(&prog->mutexes[i]);
		i++;
	}
	free(prog->mutexes);
	return (NULL);
}

void	*ft_free(t_program *prog)
{
	destroy_mutex(prog);
	free_philos(prog);
	free(prog->timings);
	free(prog);
	return (NULL);
}

