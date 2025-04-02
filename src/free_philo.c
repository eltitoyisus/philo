/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:46:33 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/02 15:46:33 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philo(t_table *table)
{
	int i = 0;
	while (i < table->num_philos)
	{
		free(table->num_philos[i]);
		i++;
	}
}
