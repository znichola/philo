/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:01:12 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 21:08:38 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long ret_time_in_ms(void);

void	print_log(int id, int msg)
{
	printf("%lld %d ", ret_time_in_ms(), id);
	if (msg == e_msg_taken_fork)
		printf(" has taken a fork\n");
	else if (msg == e_msg_is_sleeping)
		printf(" is sleeping\n");
	else if (msg == e_msg_is_eating)
		printf(" is eating\n");
	else if (msg == e_msg_is_thinking)
		printf(" is thinking\n");
	else if (msg == e_msg_is_dead)
		printf(" died\n");
}

void	print_philo(t_philo *p)
{
	if (p == NULL)
		return ;
	printf("thread:%p\n", (void*)p->my_thread);
	printf("    id:%-3d   die_time:%-5d\n", p->id_number, p->time_to_die);
	printf(" meals:%-3d   eat_time:%-5d\n", p->meals_left, p->eat_time);
	printf("  dead:%-3d sleep_time:%-5d\n", p->time_to_die, p->sleep_time);
	printf("\n");
}

static long long ret_time_in_ms(void)
{
	struct timeval	now;
	long long		ret;

	gettimeofday(&now,NULL);
	ret = ((long long)now.tv_sec)*1000;
	ret += ((long long)now.tv_usec)/1000;
	return (ret);
}
