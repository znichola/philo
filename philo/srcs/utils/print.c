/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:01:12 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 15:41:24 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(int id, int msg)
{
	printf("timestamp_in_ms %d ", id);
	if (msg == e_msg_taken_fork)
		printf(" has taken a fork\n");
	else if (msg == e_msg_is_sleeping)
		printf(" is sleeping\n");
	else if (msg == e_msg_is_thinking)
		printf(" is thinking\n");
	else if (msg == e_msg_is_dead)
		printf(" dead\n");
}
