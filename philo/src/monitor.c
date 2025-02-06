#include "../include/philo.h"

int check_death(t_philo *philos)
{
    int i;
    long current_time;

    i = 0;
    while (i < philos[0].config->num_filosofos)
    {
        current_time = get_time();
        if ((current_time - philos[i].last_meal) > philos[i].config->time_to_die)
        {
            print_status(philos[i].config, philos[i].id, "ha muerto");
            return (1);
        }
        i++;
    }
    return (0);
}

int check_meals(t_philo *philos)
{
    int i;
    int full_count;

    if (philos[0].config->must_eat == -1)
        return (0);
    i = 0;
    full_count = 0;
    while (i < philos[0].config->num_filosofos)
        if (philos[i++].meals_eaten >= philos[0].config->must_eat)
            full_count++;
    return (full_count == philos[0].config->num_filosofos);
}

void *monitor(void *arg)
{
    t_philo *philos;

    philos = (t_philo *)arg;
    while (1)
    {
        if (check_death(philos) || check_meals(philos))
            return (NULL);
        usleep(1000);
    }
    return (NULL);
}
