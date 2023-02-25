/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:55:41 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 23:27:50 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_app	data;

	if (validate_inputs(argc, argv, data.args))
		return (1);
	if (prep_all_philos(&data) == FATAL_ERROR)
		return (FATAL_ERROR);
	if (launch_all_philos(&data) == FATAL_ERROR)
		return (FATAL_ERROR);
	wait_all_philos(&data);
	cleanup_philos(&data);
	return (0);
}

/*
	awk 'NR == 1 {origin = $1} {$1 = $1 - origin; print}'
 */
