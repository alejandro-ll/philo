#include "../include/philo.h"

void take_forks(t_philo *philo)
{
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

void eat(t_philo *philo)
{
    take_forks(philo);
    print_status(philo->config, philo->id, "está comiendo");
    philo->last_meal = get_time();
    philo->meals_eaten++;
    usleep(philo->config->time_to_eat * 1000);
    release_forks(philo);
}

void *philosopher(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    while (1)
    {
        print_status(philo->config, philo->id, "está pensando");
        eat(philo);
        print_status(philo->config, philo->id, "está durmiendo");
        usleep(philo->config->time_to_sleep * 1000);
    }
    return (NULL);
}
