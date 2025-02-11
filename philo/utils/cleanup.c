#include "../include/philo.h"

void destroy_forks(t_config *config, pthread_mutex_t *forks)
{
    int i = 0;
    while (i < config->num_filosofos)
        pthread_mutex_destroy(&forks[i++]);
}

void cleanup_mutexes(t_config *config, pthread_mutex_t *forks)
{
    destroy_forks(config, forks);
    pthread_mutex_destroy(&config->print_mutex);
    pthread_mutex_destroy(&config->state_mutex);
}

void free_memory(t_philo *philos, pthread_mutex_t *forks)
{
    free(forks);
    free(philos);
}

void cleanup(t_config *config, t_philo *philos, pthread_mutex_t *forks)
{
    int i = 0;

    while (i < config->num_filosofos)
    {
        pthread_mutex_destroy(&philos[i].meal_mutex); // 🔴 Liberar el meal_mutex
        i++;
    }
    cleanup_mutexes(config, forks);
    free_memory(philos, forks);
}
