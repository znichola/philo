/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:01:20 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 14:08:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include "defines.h"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				diet;
	int				eatt;
	int				sleept;
	int				meals;
	int				is_eating;
	// int				x_my_fork; // should be a mutex
	int				x_fork_status;
	int				x_fork_lock;
	pthread_mutex_t	*mutex;
	int			dead;
	struct s_philo	*to_left;
}	t_philo;

// typedef struct s_philo
// {

// }

typedef struct s_app
{
	int				philo_count;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				meals;
	pthread_mutex_t	mutex;
	t_philo			*philo;
}	t_app;

#endif
