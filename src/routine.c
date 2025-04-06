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

void	philo_sleep(t_philo *philo)
{
	printf("%ld %ld is sleeping\n",
		get_current_time() - philo->table->start_time, philo->id);
	ft_usleep(philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	printf("%ld %ld is thinking\n",
		get_current_time() - philo->table->start_time, philo->id);
}

void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_left);
		printf("%ld %ld has taken a fork\n", 
			get_current_time() - philo->table->start_time, philo->id);
		pthread_mutex_lock(philo->fork_right);
		printf("%ld %ld has taken a fork\n", 
			get_current_time() - philo->table->start_time, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		printf("%ld %ld has taken a fork\n", 
			get_current_time() - philo->table->start_time, philo->id);
		pthread_mutex_lock(philo->fork_left);
		printf("%ld %ld has taken a fork\n", 
			get_current_time() - philo->table->start_time, philo->id);
	}
}

void	eat(t_philo *philo)
{
	take_fork(philo);

	philo->last_eat_time = get_current_time();
	philo->eat_count++;

	printf("%ld %ld is eating\n",
		get_current_time() - philo->table->start_time, philo->id);
	ft_usleep(philo->table->time_to_eat);

	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

int	check_death(t_philo *philo)
{
	size_t	current_time;

	current_time = get_current_time();
	if (current_time - philo->last_eat_time > (size_t)philo->table->time_to_die)
	{
		printf("%ld %ld died\n",
			current_time - philo->table->start_time, philo->id);
		return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 2);
		
	while (1)
	{
		if (check_death(philo))
			break;
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	die(t_table *table)
{
	long	i;
	size_t	current_time;

	while (1)
	{
		i = 0;
		while (i < table->num_philos)
		{
			current_time = get_current_time();
			if (current_time - table->philos[i].last_eat_time > 
				(size_t)table->time_to_die)
			{
				printf("%ld %ld died\n", 
					current_time - table->start_time, table->philos[i].id);
				return;
			}
			i++;
		}
		ft_usleep(1000);
	}
}
