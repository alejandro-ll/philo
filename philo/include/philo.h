#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_config
{
    int num_filosofos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
    long start_time;
    int simulation_running;
    pthread_mutex_t print_mutex;
    pthread_mutex_t state_mutex;
} t_config;

typedef struct s_philo
{
    int id;
    int meals_eaten;
    long last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t meal_mutex;
    pthread_t thread;
    t_config *config;
} t_philo;

int     parse_args(int argc, char **argv, t_config *config);
long    get_time(void);
void    init_simulation(t_config *config, t_philo **philos, pthread_mutex_t **forks);
void    *philosopher(void *arg);
void    *monitor(void *arg);
void    cleanup(t_config *config, t_philo *philos, pthread_mutex_t *forks);
void    print_status(t_config *config, int id, char *status);

int	ft_atoi(const char *str);


#endif