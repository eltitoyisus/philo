/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:14:45 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/02 09:14:45 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include "philo.h"
#include "headers.h"

typedef struct s_table;

typedef struct s_philo
{
	long			id;
	long			eat_count;
	size_t			last_eat_time;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	struct s_table	*table;
}	t_philo;

struct s_table
{
	long			num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_eats;
	size_t			start_time;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_table;

#endif
