/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:19:17 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 16:14:42 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define SLEEP_CHUNK 4

static int	sleep_chunk(t_philo *p, int sleep_in_ms);
static int	check_death(t_philo *p);

int	do_activity(t_philo *p, int sleep_in_ms)
{
	int	chunks_count;

	chunks_count = sleep_in_ms / SLEEP_CHUNK;
	while (chunks_count-- > 0)
	{
		if (sleep_chunk(p, SLEEP_CHUNK))
			return (1);
	}
	if (sleep_in_ms % SLEEP_CHUNK)
		return (sleep_chunk(p, sleep_in_ms % SLEEP_CHUNK));
	return (0);
}

static int	sleep_chunk(t_philo *p, int sleep_in_ms)
{
	if (check_death(p))
		return (1);
	usleep(sleep_in_ms * 1000);
	return (0);
}

static int	check_death(t_philo *p)
{
	long long	meal_time_diff;

	meal_time_diff = ret_time_in_ms() - p->last_meal_time;
	if (get_mutex_state(&p->to_left->death_lock, &p->to_left->death_state))
	{
		if (!try_reserve(&p->death_lock, &p->death_state))
			printf("we should be the only ones to set the death time\n");
		return (1);
	}
	if (meal_time_diff > p->time_to_die)
	{
		try_reserve(&p->to_left->death_lock, &p->to_left->death_state);
		if (try_reserve(&p->death_lock, &p->death_state))
		{
			print_log(p->id_number, e_msg_is_dead);
		}
		return (1);
	}
	return (0);
}

// static int	sleep_chunk(t_philo *p, int sleep_in_ms)
// {
// 	struct timeval	start_tv;
// 	struct timeval	current_tv;
// 	long			diff_sec;
// 	long			diff_usec;
// 	long long		diff_msec;

// 	gettimeofday(&start_tv, NULL);
// 	if (get_mutex_state(&p->death_lock, &p->death_state))
// 		return (1);
// 	printf("%d rested for %d\n", p->id_number, sleep_in_ms);
// 	gettimeofday(&current_tv, NULL);
// 	diff_sec = current_tv.tv_sec - start_tv.tv_sec;
// 	diff_usec = current_tv.tv_usec - start_tv.tv_usec;
// 	diff_msec = (long long)diff_sec * 1000;
// 	diff_msec += (long long)diff_usec / 1000;
// 	if (diff_msec == 0)
// 		usleep((long long)sleep_in_ms * 1000 - diff_usec);
// 	else if (diff_msec > sleep_in_ms)
// 		printf("something is very wrong! sleep time mutex is clogged up");
// 	else
// 	{
// 		printf("here\n");
// 		usleep(((long long)sleep_in_ms - diff_msec) * 1000);
// 	}
// 	return (0);
// }
