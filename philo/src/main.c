#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_config config;
    t_philo *philos;
    pthread_mutex_t *forks;

    if (parse_args(argc, argv, &config))
        return (1);
    if (config.num_filosofos == 1)
    {
        long start_time = get_time();

        printf("[%ld] Philosopher 1 is thinking\n", get_time() - start_time);
        printf("[%ld] Philosopher 1 has taken a fork\n", get_time() - start_time);
        usleep(config.time_to_die * 1000);
        printf("[%ld] Philosopher 1 died\n", get_time() - start_time);
        return (0);
    }
    init_simulation(&config, &philos, &forks);
    cleanup(&config, philos, forks);
    return (0);
}
