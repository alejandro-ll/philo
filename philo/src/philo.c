#include "../include/philo.h"

void take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->config->state_mutex);
    if (!philo->config->simulation_running)
    {
        pthread_mutex_unlock(&philo->config->state_mutex);
        return;
    }
    pthread_mutex_unlock(&philo->config->state_mutex);

    pthread_mutex_lock(philo->left_fork);
    print_status(philo->config, philo->id, "tomó el tenedor izquierdo");

    if (pthread_mutex_lock(philo->right_fork) != 0) 
    {
        pthread_mutex_unlock(philo->left_fork);
        print_status(philo->config, philo->id, "soltó el tenedor izquierdo");
        return ;
    }
    print_status(philo->config, philo->id, "tomó el tenedor derecho y está comiendo");
}

void release_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    print_status(philo->config, philo->id, "soltó los tenedores y está pensando");
}

int eat(t_philo *philo)
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
    philo->last_meal = get_time();  // 🔴 Ahora se actualiza ANTES de dormir
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->meal_mutex);

    print_status(philo->config, philo->id, "está comiendo");
    usleep(philo->config->time_to_eat * 1000);

    release_forks(philo);
    return (1);
}

void *philosopher(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (1)
    {
        pthread_mutex_lock(&philo->config->state_mutex);
        if (!philo->config->simulation_running)
        {
            pthread_mutex_unlock(&philo->config->state_mutex);
            return (NULL);
        }
        pthread_mutex_unlock(&philo->config->state_mutex);

        pthread_mutex_lock(&philo->meal_mutex);
        if (philo->config->must_eat != -1 && philo->meals_eaten >= philo->config->must_eat)
        {
            pthread_mutex_unlock(&philo->meal_mutex);
            return (NULL); // 🔴 El filósofo termina si ya comió suficiente
        }
        pthread_mutex_unlock(&philo->meal_mutex);

        print_status(philo->config, philo->id, "está pensando");
        eat(philo);

        print_status(philo->config, philo->id, "está durmiendo");
        usleep(philo->config->time_to_sleep * 1000);
    }

    return (NULL);
}
