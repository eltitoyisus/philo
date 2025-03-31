/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:32:01 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/31 09:32:01 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	if (argc == 5)
		base_philo();
	else if (argc == 6)
		adv_philo();
	else
		write(1, "Usage: ./philo 'pn' 'ttd' 'tte' 'tts' 'nmu' ")
}




/*

number of philo

time to die

time to eat

time to sleep

number of must eat

*/