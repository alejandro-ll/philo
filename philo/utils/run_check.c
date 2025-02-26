/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:23:07 by allera-m          #+#    #+#             */
/*   Updated: 2025/02/26 18:28:44 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	run_check(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->config->time_to_sleep)
	{
		usleep(10000);
		pthread_mutex_lock(&philo->config->state_mutex);
		if (!philo->config->simulation_running)
		{
			pthread_mutex_unlock(&philo->config->state_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo->config->state_mutex);
		i += 10;
	}
	return (1);
}
