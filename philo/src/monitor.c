/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:26:55 by allera-m          #+#    #+#             */
/*   Updated: 2025/02/26 17:27:24 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_death(t_philo *philos)
{
	int		i;
	long	current_time;

	i = 0;
	while (i < philos[0].config->num_filosofos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		current_time = get_time();
		if ((current_time
				- philos[i].last_meal) > philos[i].config->time_to_die)
		{
			pthread_mutex_unlock(&philos[i].meal_mutex);
			print_status(philos[i].config, philos[i].id, "died");
			pthread_mutex_lock(&philos[0].config->state_mutex);
			philos[0].config->simulation_running = 0;
			pthread_mutex_unlock(&philos[0].config->state_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
	}
	return (0);
}

int	check_meals(t_philo *philos)
{
	int	i;
	int	full_count;

	if (philos[0].config->must_eat == -1)
		return (0);
	i = 0;
	full_count = 0;
	pthread_mutex_lock(&philos[0].config->state_mutex);
	while (i < philos[0].config->num_filosofos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		if (philos[i].meals_eaten >= philos[0].config->must_eat)
			full_count++;
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
	}
	pthread_mutex_unlock(&philos[0].config->state_mutex);
	return (full_count == philos[0].config->num_filosofos);
}

void	*monitor(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (check_death(philos) || check_meals(philos))
		{
			pthread_mutex_lock(&philos[0].config->state_mutex);
			philos[0].config->simulation_running = 0;
			pthread_mutex_unlock(&philos[0].config->state_mutex);
			usleep(50000);
			return (NULL);
		}
		usleep(500);
	}
	return (NULL);
}
