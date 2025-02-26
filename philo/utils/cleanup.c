/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:29:34 by allera-m          #+#    #+#             */
/*   Updated: 2025/02/26 17:32:19 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_forks(t_config *config, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < config->num_filosofos)
		pthread_mutex_destroy(&forks[i++]);
}

void	cleanup_mutexes(t_config *config, pthread_mutex_t *forks)
{
	destroy_forks(config, forks);
	pthread_mutex_destroy(&config->print_mutex);
	pthread_mutex_destroy(&config->state_mutex);
}

void	free_memory(t_philo *philos, pthread_mutex_t *forks)
{
	free(forks);
	free(philos);
}

void	cleanup(t_config *config, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < config->num_filosofos)
	{
		pthread_mutex_destroy(&philos[i].meal_mutex);
		i++;
	}
	cleanup_mutexes(config, forks);
	free_memory(philos, forks);
}
