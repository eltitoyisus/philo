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

void adv_philo(int argc, char **argv)
{
	int i = 0;
	
	if (argc == 6)
	{
		int n = ft_atol(argv[5]);
		while (i < n)
		{
			base_philo(ft_atol(argv[1]), ft_atol(argv[2]),
						ft_atol(argv[3]), ft_atol(argv[4]));
			i++;
		}
	}
}
