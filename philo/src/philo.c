/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:27:37 by allera-m          #+#    #+#             */
/*   Updated: 2025/02/26 18:34:54 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->config->state_mutex);
	if (!philo->config->simulation_running)
	{
		pthread_mutex_unlock(&philo->config->state_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->config->state_mutex);
	pthread_mutex_lock(philo->left_fork);
	print_status(philo->config, philo->id, "has taken a fork");
	if (pthread_mutex_lock(philo->right_fork) != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		print_status(philo->config, philo->id, "has taken a fork");
		return ;
	}
	print_status(philo->config, philo->id, "has taken a fork");
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->config->state_mutex);
	if (!philo->config->simulation_running)
	{
		pthread_mutex_unlock(&philo->config->state_mutex);
		release_forks(philo);
		return (0);
	}
	pthread_mutex_unlock(&philo->config->state_mutex);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo->config, philo->id, "is eating");
	usleep(philo->config->time_to_eat * 1000);
	release_forks(philo);
	return (1);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->config->state_mutex);
		if (!philo->config->simulation_running)
		{
			pthread_mutex_unlock(&philo->config->state_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->config->state_mutex);
		print_status(philo->config, philo->id, "is thinking");
		if (!eat(philo))
			return (NULL);
		print_status(philo->config, philo->id, "is sleeping");
		if (!run_check(philo))
			return (NULL);
	}
	return (NULL);
}
