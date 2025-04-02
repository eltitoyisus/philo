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

void base_philo(int number_philo, int time_to_die, int time_to_eat, int time_to_sleep)
{
	t_table	*table;
	long	i;

	table = malloc_prevent(sizeof(t_table));
	table->num_philos = number_philo;
	table->time_to_die = time_to_die;
	table->time_to_eat = time_to_eat;
	table->time_to_sleep = time_to_sleep;
	table->num_eats = 0;
	table->start_time = get_current_time();
	mutex_init(table);
	ft_init(table);
	i = 0;
	while (i < table->num_philos)
	{
		pthread_create(&table->philos[i].thread, NULL, &routine, &table->philos[i]);
		i++;
	}
	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	mutex_destroy(table);
}
