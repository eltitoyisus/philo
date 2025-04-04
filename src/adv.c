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

void adv_philo(void)
{
	t_table	*table;
	char **argv;
	int i = 0;
	int n = ft_atol(argv[5]);
	if (argv == 5)
	{
		while (i <= n)
		{
			base_philo(argv[1], argv[2], argv[3], argv[4]);
			i++;
		}
	}
}
