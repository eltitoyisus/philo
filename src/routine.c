/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:59:15 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/31 09:59:15 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void sleep()
{

}

void eat()
{

}

void take_fork(t_table *table, char **argv)
{
	if (table->num_philos % 2 == 0)
	{
		pthread_mutex_lock(&table->forks[table->id]);
		pthread_mutex_lock(&table->forks[(table->id + 1) % table->num_philos]);
	}
	else
	{
		pthread_mutex_lock(&table->forks[(table->id + 1) % table->num_philos]);
		pthread_mutex_lock(&table->forks[table->id]);
	}
}

void die(t_table *table, char **argv)
{
	if (table->time_to_die >= ft_atol(argv[2])
		|| table->time_to_eat >= ft_atol(argv[3])
		|| table->time_to_sleep >= ft_atol(argv[4]))
	{
		break ;
		printf("%zu has died", philo->id);
		free(table->time_to_die);
		free(table->time_to_eat);
		free(table->time_to_sleep);
	}
}


/*
	if (table->num_philos % 2 == 0)
	{
		pthread_mutex_lock(&table->forks[table->id]);
		pthread_mutex_lock(&table->forks[(table->id + 1) % table->num_philos]);
	}
	else
	{
		pthread_mutex_lock(&table->forks[(table->id + 1) % table->num_philos]);
		pthread_mutex_lock(&table->forks[table->id]);
	}
*/