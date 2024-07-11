/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:40:26 by chhoflac          #+#    #+#             */
/*   Updated: 2024/07/08 13:29:49 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	ft_atollu(char *str)
{
	unsigned long long	res;
	int					i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

int	check_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (!check_numeric(argc, argv))
		return (0);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
