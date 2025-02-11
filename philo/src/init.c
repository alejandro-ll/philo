#include "../include/philo.h"

void init_mutex(t_config *config, pthread_mutex_t **forks)
{
    int i = 0;
    *forks = malloc(sizeof(pthread_mutex_t) * config->num_filosofos);
    while (i < config->num_filosofos)
        pthread_mutex_init(&(*forks)[i++], NULL);
    pthread_mutex_init(&config->print_mutex, NULL);
    pthread_mutex_init(&config->state_mutex, NULL);
}

void init_philosophers(t_config *config, t_philo **philos, pthread_mutex_t *forks)
{
    int i = 0;
    *philos = malloc(sizeof(t_philo) * config->num_filosofos);
    while (i < config->num_filosofos)
    {
        (*philos)[i].id = i + 1;
        (*philos)[i].meals_eaten = 0;
        (*philos)[i].last_meal = get_time();
        (*philos)[i].config = config;

        pthread_mutex_init(&(*philos)[i].meal_mutex, NULL); // Inicializar meal_mutex
        // 🟢 Diferenciamos entre filósofos pares e impares para evitar deadlocks
        if (i % 2 == 0)
        {
            (*philos)[i].left_fork = &forks[i];
            (*philos)[i].right_fork = &forks[(i + 1) % config->num_filosofos];
        }
        else
        {
            (*philos)[i].right_fork = &forks[i];
            (*philos)[i].left_fork = &forks[(i + 1) % config->num_filosofos];
        }
        i++;
    }
}

void start_threads(t_config *config, t_philo *philos)
{
    int i = 0;
    pthread_t monitor_thread;

    // 🔴 Crear hilos de filósofos
    while (i < config->num_filosofos)
    {
        pthread_create(&philos[i].thread, NULL, philosopher, &philos[i]);
        i++;
    }

    // 🔴 Iniciar monitor
    pthread_create(&monitor_thread, NULL, monitor, philos);

    // 🔴 Esperar a que el monitor termine
    pthread_join(monitor_thread, NULL);

    // 🔴 Asegurar que todos los hilos de filósofos terminan
    i = 0;
    while (i < config->num_filosofos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
}


void init_simulation(t_config *config, t_philo **philos, pthread_mutex_t **forks)
{
    config->start_time = get_time();
    config->simulation_running = 1;
    init_mutex(config, forks);
    init_philosophers(config, philos, *forks);
    start_threads(config, *philos);
}
