/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:55:26 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 21:09:49 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	rec_free(t_philo *p);

void	cleanup_philos(t_app *d)
{
	// int		i;
	// t_philo	*tmp;

	// i = d->args[e_num_philos];
	// while (--i >= 0)
	// {
	// 	printf("freeing :%d\n", i);
	// 	pthread_mutex_destroy(&d->philo_table[i].fork);
	// 	free(d->philo_table + i);
	// }
	// rec_free(d->philo_table);
	d->philo_table[0];
	free(d->philo_table);
}

static void	rec_free(t_philo *p)
{
	t_philo	*tmp;

	if (p == NULL)
		return ;
	print_philo(p);
	tmp = p->to_left;
	free(p);
	p = NULL;
	rec_free(tmp);
}
