/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:47:59 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/31 09:47:59 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void base_philo(long number_philo, long time_to_die, long time_to_eat, long time_to_sleep)
{
	t_table	*table;

	table = malloc_prevent(sizeof(t_table));
	ft_init(table, number_philo, time_to_die, time_to_eat, time_to_sleep);
	do_routine(table);
}
