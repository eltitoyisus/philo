/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:54:45 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/31 09:54:45 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 2);
	while (1)
	{
		if (check_death(philo))
			break ;
		eat(philo);
		if (philo->table->num_eats > 0 && philo->eat_count
			>= philo->table->num_eats)
			break ;
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	adv_philo(t_philo_args args)
{
	t_table	*table;

	table = malloc_prevent(sizeof(t_table));
	if (!table)
		return ;
	ft_init(table, args);
	table->num_eats = args.repeat;
	do_routine(table);
}
