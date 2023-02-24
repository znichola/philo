/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:35:51 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 00:02:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

static void	eating(t_philo *p);
static void	give_back(pthread_mutex_t *m, int *thing);
static int	try_reserve(pthread_mutex_t *m, int *thing);
static int	try_return(pthread_mutex_t *m, int *thing);

void	thinking(t_philo *p)
{
	print_log(p->id_number, e_msg_is_thinking);
	while (1)
	{
		if (try_reserve(&p->fork_lock, &p->fork_state))
		{
			if (try_reserve(&p->to_left->fork_lock, &p->to_left->fork_state))
			{
				print_log(p->id_number, e_msg_taken_fork);
				print_log(p->id_number, e_msg_taken_fork);
				eating(p);
				give_back(&p->to_left->fork_lock, &p->to_left->fork_state);
				give_back(&p->fork_lock, &p->fork_state);
				return ;
			}
			give_back(&p->fork_lock, &p->fork_state);
		}
	}
}

static void	eating(t_philo *p)
{
	print_log(p->id_number, e_msg_is_eating);
	philo_sleep(p->eat_time);
	if (p->meals_left != -1)
		p->meals_left -= 1;
}

static void	give_back(pthread_mutex_t *m, int *thing)
{
	int	have_i_given_back_the_reasource;

	have_i_given_back_the_reasource = 1;
	while (have_i_given_back_the_reasource)
	{
		if (try_return(m, thing))
			have_i_given_back_the_reasource = 0;
	}
}

/*
	return 1 if was able reserve the reasource/thing

	reserving a reasrouce is flipping it to 1 if it's not alreay
	this way we tell all the other hungy threads that it's mine!
 */
static int	try_reserve(pthread_mutex_t *m, int *thing)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(m);
	if (*thing == 0)
	{
		*thing = 1;
		ret = 1;
	}
	pthread_mutex_unlock(m);
	return (ret);
}

/*
	return 1 if was able return the reasource/thing

	returning a reasource is flipping it to 0 so others can use it
	This should theoretically never fail, but how knows.
 */
static int	try_return(pthread_mutex_t *m, int *thing)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(m);
	if (*thing == 1)
	{
		*thing = 0;
		ret = 1;
	}
	pthread_mutex_unlock(m);
	return (ret);
}
