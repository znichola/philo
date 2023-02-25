/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:57:23 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 17:52:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	prep_philo(t_philo *current, int id, t_app *d, t_philo *left);
static void	set_left(t_app *d);

int	prep_all_philos(t_app *d)
{
	int		i;
	t_philo	*to_left;

	i = d->args[e_num_philos];
	d->philo_table = malloc(sizeof(t_philo) * d->args[e_num_philos]);
	if (d->philo_table == NULL)
		return (FATAL_ERROR);
	d->death_state = 0;
	if (pthread_mutex_init(&d->death_lock, NULL))
		return (FATAL_ERROR);
	to_left = NULL;
	while (--i >= 0)
	{
		if (prep_philo(&d->philo_table[i], i, d, to_left))
			return (FATAL_ERROR);
	}
	set_left(d);
	return (0);
}

static int	prep_philo(t_philo *current, int id, t_app *d, t_philo *left)
{
	if (philo_factory(current, &(t_philo){.id_number=id,
					.eat_time=d->args[e_time_to_eat],
					.sleep_time=d->args[e_time_to_sleep],
					.time_to_die=d->args[e_time_to_die],
					.meals_left=d->args[e_n_of_meals],
					.to_left=left,
					.death_state=&(d->death_state),
					.death_lock=&(d->death_lock)}))
		return (FATAL_ERROR);
	return (0);
}

static void	set_left(t_app *d)
{
	t_philo	*last;
	int	i;

	i = d->args[e_num_philos];
	last = &d->philo_table[0];
	while (--i >= 0)
	{
		d->philo_table[i].to_left = last;
		last = &d->philo_table[i];
	}
}
