#include "../include/philo.h"

long get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void print_status(t_config *config, int id, char *status)
{
    pthread_mutex_lock(&config->state_mutex);
    if (!config->simulation_running && ft_strcmp(status, "ha muerto") != 0)
    {
        pthread_mutex_unlock(&config->state_mutex);
        return;
    }
    pthread_mutex_unlock(&config->state_mutex);

    pthread_mutex_lock(&config->print_mutex);
    printf("[%ld] Filósofo %d %s\n", get_time() - config->start_time, id, status);
    pthread_mutex_unlock(&config->print_mutex);
}

int is_valid_number(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int parse_args(int argc, char **argv, t_config *config)
{
    if (argc < 5 || argc > 6)
        return (printf("Uso: ./philo num_filosofos time_to_die time_to_eat time_to_sleep [num_comidas]\n"), 1);
    
    if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]) ||
        !is_valid_number(argv[3]) || !is_valid_number(argv[4]) ||
        (argc == 6 && !is_valid_number(argv[5])))
        return (printf("Error: Todos los valores deben ser enteros positivos.\n"), 1);

    config->num_filosofos = ft_atoi(argv[1]);
    config->time_to_die = ft_atoi(argv[2]);
    config->time_to_eat = ft_atoi(argv[3]);
    config->time_to_sleep = ft_atoi(argv[4]);
    config->must_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;

    if (config->num_filosofos < 1 || config->time_to_die <= 0 || 
        config->time_to_eat <= 0 || config->time_to_sleep <= 0 || 
        (argc == 6 && config->must_eat <= 0))
        return (printf("Error: Valores inválidos.\n"), 1);

    return (0);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}