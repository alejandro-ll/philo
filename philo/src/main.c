#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_config config;
    t_philo *philos;
    pthread_mutex_t *forks;

    if (parse_args(argc, argv, &config))
        return (1);
    init_simulation(&config, &philos, &forks);
    cleanup(&config, philos, forks);
    return (0);
}
