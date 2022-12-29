/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:07:52 by znichola          #+#    #+#             */
/*   Updated: 2022/12/29 15:51:53 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_check_assign(int ac, char **av, t_app *a)
{
	if (ac > 6 || ac < 5)
		return (1);
	if(ft_safe_atoi(&a->philo_count, av[1]) + ft_safe_atoi(&a->ttdie, av[2]) 
		+ ft_safe_atoi(&a->tteat, av[3]) + ft_safe_atoi(&a->ttsleep, av[4]))
		return (2);
	if (ac == 6)
		if (ft_safe_atoi(&a->meals, av[5]))
			return (3);
	return (SUCCESS);
}
