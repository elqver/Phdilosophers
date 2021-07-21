#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include "forks.h"

void			*philosopher_routine(void *arg);
void			set_up_philosophers(void);

pthread_t		get_philosopher(int	n);
pthread_t		*get_philosopher_pointer(int n);

int				check_for_dead(void);

int				get_hungry_amount(void);
void			set_hungry_amount(int amount);
void			decrease_hungry_amount(void);

void			set_up_death_mutex(void);
pthread_mutex_t	*get_death_mutex_pointer(int philosopher_number);
pthread_mutex_t	get_death_mutex(int philosopher_number);

int				get_death_time(int philosopher_number);
void			set_death_time(int philosopher_number);
void			set_up_death_time(void);

#endif
