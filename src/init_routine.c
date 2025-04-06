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

void ft_init(t_table *table, long number_philo, long time_to_die, long time_to_eat, long time_to_sleep)
{
	long i;

	table->num_philos = number_philo;
	table->time_to_die = time_to_die;
	table->time_to_eat = time_to_eat;
	table->time_to_sleep = time_to_sleep;
	table->num_eats = 0;
	table->start_time = get_current_time();
	table->philos = malloc_prevent(sizeof(t_philo) * table->num_philos);
	table->forks = malloc_prevent(sizeof(pthread_mutex_t) * table->num_philos);
	
	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].eat_count = 0;
		table->philos[i].last_eat_time = get_current_time();
		table->philos[i].table = table;
		table->philos[i].fork_left = &table->forks[i];
		table->philos[i].fork_right = &table->forks[(i + 1) % table->num_philos];
		i++;
	}
}

void do_routine(t_table *table)
{
	mutex_init(table);
	create_thread(table);
	join_thread(table);
	mutex_destroy(table);
}
