/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:01:12 by znichola          #+#    #+#             */
/*   Updated: 2023/02/17 00:20:39 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	print_philo(t_philo *p)
// {
// 	if (p == NULL)
// 		return ;
// 	printf("\nphilo_id:\033[36m%d\033[0m  \n", p->id);
// 	printf("  die:%-4d  eat:%-4d sleep:%-4d\n", p->diet, p->eatt, p->sleept);
// 	printf("meals:%-4d me: %p left:%p\n", p->meals, p, p->to_left);
// 	printf("fork_status  my:%-3d  left:%-3d\n",  p->x_fork_status, p->to_left->x_fork_status);
// 	printf("\n");
// }

void	print_all_philos(t_app *a)
{
	int		i;
	t_philo	*t;

	i = 0;
	t = a->philo;
	while (i++ < a->philo_count)
	{
		print_philo(t);
		printf("\033[1Acan i eat: %s\n", (can_i_eat(t) == SUCCESS ? "yes" : "no" ));
		t = t->to_left;
	}
}
