/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:52:27 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/02 15:52:27 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void ft_init(t_table *table)
{
	table->philos = malloc_prevent(sizeof(t_philo) * table->num_philos);
	table->forks = malloc_prevent(sizeof(pthread_mutex_t) * table->num_philos);
	
}