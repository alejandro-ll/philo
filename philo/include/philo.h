/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:24:30 by allera-m          #+#    #+#             */
/*   Updated: 2025/02/26 18:28:50 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define INSTRUCTION_MESSAGE "Uso: ./philo num_filosofos time_to_die "
# define INSTRUCTION_MESSAGE2 "time_to_eat time_to_sleep [num_comidas]\n"

typedef struct s_config
{
	int				num_filosofos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start_time;
	int				simulation_running;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
}					t_config;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	pthread_t		thread;
	t_config		*config;
}					t_philo;

int					parse_args(int argc, char **argv, t_config *config);
long				get_time(void);
void				init_simulation(t_config *config, t_philo **philos,
						pthread_mutex_t **forks);
void				*philosopher(void *arg);
void				*monitor(void *arg);
void				cleanup(t_config *config, t_philo *philos,
						pthread_mutex_t *forks);
void				print_status(t_config *config, int id, char *status);

int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					run_check(t_philo *philo);

#endif
