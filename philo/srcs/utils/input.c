/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:07:52 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 15:46:21 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_inputs(int ac, char **av, int args[5])
{
	if (ac != 5 && ac != 6)
	{
		printf("usage:\n    ./philo ");
		printf("n_philos time_to_die time_to_eat time_to_sleep [n_of_meals]\n");
		return (1);
	}
	if(ft_safe_atoi(&args[0], av[1]) + ft_safe_atoi(&args[1], av[2])
		+ ft_safe_atoi(&args[2], av[3]) + ft_safe_atoi(&args[3], av[4]))
	{
		printf("please use valid int32 numbers\n");
		return (2);
	}
	if (ac == 6)
	{
		if (ft_safe_atoi(&args[4], av[5]))
		{
			printf("please use valid int32 numbers\n");
			return (3);
		}
	}
	else
		args[4] = 0;
	return (0);
}
