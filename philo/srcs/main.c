/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:55:41 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 14:46:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_t	*philo_threads;
	t_philo		*philo_table;
	int			args[5];

	if (validate_inputs(argc, argv, args))
		return (1);
	philo_threads = (pthread_t *)malloc(sizeof(pthread_t) * args[e_num_philos]);
	philo_table = (t_philo *)malloc(sizeof(t_philo) * args[e_num_philos]);

	free(philo_threads);
	free(philo_table);
	return (0);
}
