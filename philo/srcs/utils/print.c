/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:01:12 by znichola          #+#    #+#             */
/*   Updated: 2023/02/27 22:57:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(int id, int msg)
{
	int	time_since_start;

	time_since_start = get_time_since_start();
	id += 1;
	if (msg == e_msg_taken_fork)
		printf("%d %d has taken a fork\n", time_since_start, id);
	else if (msg == e_msg_is_sleeping)
		printf("%d %d is sleeping\n", time_since_start, id);
	else if (msg == e_msg_is_eating)
		printf("%d %d is eating\n", time_since_start, id);
	else if (msg == e_msg_is_thinking)
		printf("%d %d is thinking\n", time_since_start, id);
	else if (msg == e_msg_is_dead)
		printf("%d %d died\n", time_since_start, id);
	else if (msg == 42)
		printf("%d %d custom  - -            <------\n", time_since_start, id);
}

void	print_philo(t_philo *p)
{
	if (p == NULL)
		return ;
	printf("thread:%p\n", (void *)p->my_thread);
	printf("    id:%-3d   die_time:%-5d\n", p->id_number, p->time_to_die);
	printf(" meals:%-3d   eat_time:%-5d\n", p->meals_left, p->eat_time);
	printf("  dead:%-3d sleep_time:%-5d\n", p->time_to_die, p->sleep_time);
	printf("\n");
}
