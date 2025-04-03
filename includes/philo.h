/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:48:21 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/31 09:48:21 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include "headers.h"
#include "struct.h"

// UTILS
long	ft_atol(char *str);
void	*malloc_prevent(size_t bytes);

// TIME CONTROL
size_t	get_current_time(void);
int		ft_usleep(size_t m);

// PARSE
void	valid_args(t_table *table, char **argv);

// DO PHILO
void	ft_init(long number_philo, long time_to_die, long time_to_eat, long time_to_sleep);
void	do_routine(t_table *table);
void	base_philo(long number_philo, long time_to_die, long time_to_eat, long time_to_sleep);
void	adv_philo(void);

// DO MUTEX
void	mutex_init(t_table *table);
void	mutex_destroy(t_table *table);

// ROUTINE
void	ft_init(t_table *table);
void	sleep();
void	eat();
void	think();
void	take_fork(t_table *table, char **argv);
void	die();

#endif
