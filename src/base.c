/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:47:59 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/09 10:57:49 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	base_philo(long number_philo, long time_to_die,
	long time_to_eat, long time_to_sleep)
{
	t_table			*table;
	t_philo_args	args;

	// if (table->num_philos == 1)
	// 	one_philo()
	
	table = malloc_prevent(sizeof(t_table));
	if (!table)
		return ;
	args.number_philo = number_philo;
	args.time_to_die = time_to_die;
	args.time_to_eat = time_to_eat;
	args.time_to_sleep = time_to_sleep;
	args.repeat = -1;
	ft_init(table, args);
	do_routine(table);
}
