#include "../includes/main.h"
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t	*print_mutex_singleton(void)
{
	static pthread_mutex_t	print_mutex = PTHREAD_MUTEX_INITIALIZER;

	return (&print_mutex);
}

void	lock_print(void)
{
	pthread_mutex_lock(print_mutex_singleton());
}

void	unlock_print(void)
{
	pthread_mutex_unlock(print_mutex_singleton());
}

void	careful_print(char *message, int time_moment, int philosopher_number)
{
	lock_print();
	printf(message, time_moment, philosopher_number);
	unlock_print();
}
