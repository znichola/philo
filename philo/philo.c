/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:55:57 by znichola          #+#    #+#             */
/*   Updated: 2022/12/29 19:19:51 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_app *a)
{
	t_philo	*t;
	t_philo	*foo;

	t = a->philo;
	printf("t is %p\n", t);
	if (t == NULL)
		return ;
	if (t->to_left == NULL)
	{
		printf("exception freeing philo number %d at adress \033[31m%p\033[0m\n", t->number, t);
		free(t);
		return ;
	}
	while(t->to_left && t->number != a->philo_count)
	{
		printf("      freeing philo number %d at adress \033[31m%p\033[0m left is \033[31m%p\033[0m\n", t->number, t, t->to_left);
		foo = t->to_left;
		free(t);
		t = foo;
	}
	printf("final freeing philo number %d at adress \033[31m%p\033[0m left is \033[31m%p\033[0m\n", t->number, t, t->to_left);
	free(t);
}

int	init_philos(t_app *a)
{
	int		i;
	t_philo	*t;
	t_philo	*old;
	i = 0;

	while (i++ < a->philo_count)
	{
		printf("       making philo number %d at adress ", i);
		t = (t_philo *)malloc(sizeof(t_philo) * 1);
		if (!t)
			return (MALLOC_ERROR);
		if (i == 1)
			a->philo = t;
		else
			old->to_left = t;
		printf("\033[31m%p\033[0m\n", t);
		t->number = i;
		t->diet = a->ttdie;
		t->eatt = a->tteat;
		t->sleept = a->ttsleep;
		t->meals = a->meals;
		t->fork_status = dirty;
		t->to_left = NULL;
		old = t;
		// t = t->to_left;
		// not setting to_left to NULL correctly
	}
	old->to_left = a->philo;
}
