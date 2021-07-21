#ifndef FORKS_H
# define FORKS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include "main.h"

void			set_up_forks(void);
pthread_mutex_t	*get_fork_mutex_pointer(int n);
pthread_mutex_t	get_fork_mutex(int n);

#endif
