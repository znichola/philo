/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:14 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 15:25:49 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	philo_factory(&(t_philo){para1, para2});
 */
t_philo	*philo_factory(t_philo *blueprint)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * 1);
	if (blueprint)
	{
		;
	}
	else
		printf("error! use the blueprint when making a philo\n");
	return (philo);
}

typedef struct s_philo2
{
	int				id_number;
	int				eat_time;
	int				sleep_time;
	int				time_to_die;
	int				meals_left;
	pthread_mutex_t	fork;
	struct s_philo	*to_left;
}	t_philo2;
