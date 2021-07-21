#include "../includes/philosopher.h"

static pthread_t	*philosophers_singleton(pthread_t *new_philosophers)
{
	static pthread_t	*philosophers;

	if (new_philosophers)
	{
		free(philosophers);
		philosophers = new_philosophers;
	}
	return (philosophers);
}

void	set_up_philosophers(void)
{
	pthread_t	*philosophers;

	philosophers = calloc(sizeof(pthread_t), \
			get_programm_options().number_of_philosophers);
	philosophers_singleton(philosophers);
}

pthread_t	*get_philosophers(void)
{
	return (philosophers_singleton(NULL));
}	

pthread_t	get_philosopher(int n)
{
	return (get_philosophers()[n]);
}

pthread_t	*get_philosopher_pointer(int n)
{
	return (&(get_philosophers()[n]));
}
