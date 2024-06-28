/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:46:31 by chhoflac          #+#    #+#             */
/*   Updated: 2024/06/28 15:05:58 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_free_timings(t_timings *timings)
{
	free(timings);
	return (NULL);
}

void	*ft_free_prog(t_program *prog)
{
	free(prog);
	return (NULL);
}

void	*ft_free_philos(t_philo **philos, int nb_philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		free(philos[i]);
		i++;
	}
	free(philos);
	return (NULL);
}

void	ft_clear(t_program *prog)
{
	ft_free_timings(prog->timings);
	ft_free_prog(prog);
	ft_free_philos(prog->philos, prog->nb_philos);
}
