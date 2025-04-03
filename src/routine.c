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

void	sleep()
{
	t_table *table;
	char **argv;

	if (!take_fork(table, argv[4]) && table->time_to_sleep <= argv[4])
		printf("%zu is sleeping", table->philos[table->id].id);
}

void	eat()
{
	t_table *table;
	char **argv;

	if (take_fork(table, argv[3]) && table->time_to_eat <= argv[3])
		printf("%zu is eating", table->philos[table->id].id);
}

void	think()
{
	t_table *table;
	char **argv;

	if (sleep() && eat() && !die())
		ft_usleep(argv[2] - (argv[3] + argv[4]));
	printf("%zu is thinking", table->philos[table->id].id);
}

void take_fork(t_table *table, char **argv)
{
	if (table->num_philos % 2 == 0)
	{
		pthread_mutex_lock(&table->forks[table->id]);
		pthread_mutex_lock(&table->forks[(table->id + 1) % table->num_philos]);
		table->philos[table->id].last_eat_time = get_current_time();
		table->philos[table->id].eat_count++;
		printf("%zu has taken a fork", table->philos[table->id].id);
		printf("%zu has taken a fork", table->philos[(table->id + 1) % table->num_philos].id);
	}
	else
	{
		pthread_mutex_lock(&table->forks[table->id]);
		pthread_mutex_lock(&table->forks[(table->id - 1) % table->num_philos]);
		table->philos[table->id].last_eat_time = get_current_time();
		table->philos[table->id].eat_count++;
		printf("%zu has taken a fork", table->philos[table->id].id);
		printf("%zu has taken a fork", table->philos[(table->id - 1) % table->num_philos].id);
	}
}

void die()
{
	t_table *table;
	char **argv;

	if (table->time_to_die >= ft_atol(argv[2])
		|| table->time_to_eat >= ft_atol(argv[3])
		|| table->time_to_sleep >= ft_atol(argv[4]))
	{
		break ;
		printf("%zu has died", table->philos[table->id].id);
		free(table->time_to_die);
		free(table->time_to_eat);
		free(table->time_to_sleep);
	}
}
