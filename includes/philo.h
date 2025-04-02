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
size_t	get_current_time(void);
int		ft_usleep(size_t m);
void	base_philo(int number_philo, int time_to_die, int time_to_eat, int time_to_sleep);
void	adv_philo(void);
void	valid_args(t_table *table, char **argv);
void	*malloc_prevent(size_t bytes);
void	mutex_init(t_table *table);
void	mutex_destroy(t_table *table);



#endif
