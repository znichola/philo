/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:01:12 by znichola          #+#    #+#             */
/*   Updated: 2022/12/29 16:17:28 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *p)
{
	printf("id: %4d   ~~~   \n", p->number);
	printf("die:%4d eat:%4d sleep:%4d\n", p->diet, p->eatt, p->sleept);
	printf("meals:%4d fork_status%4d\n", p->meals, p->fork_status);
	printf("\n");
}
