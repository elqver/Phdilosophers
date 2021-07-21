#include "../includes/philosopher.h"

static pthread_mutex_t	*death_mutex_singleton(pthread_mutex_t *new_death_mutex)
{
	static pthread_mutex_t	*death_mutex;

	if (new_death_mutex)
	{
		free(death_mutex);
		death_mutex = new_death_mutex;
	}
	return (death_mutex);
}

void	set_up_death_mutex(void)
{
	pthread_mutex_t	*death_mutex;
	int				amount;
	int				i;

	amount = get_programm_options().number_of_philosophers;
	death_mutex = calloc(sizeof(pthread_mutex_t), amount);
	i = 0;
	while (i < amount)
	{
		pthread_mutex_init(&death_mutex[i], NULL);
		i++;
	}
	death_mutex_singleton(death_mutex);
}

pthread_mutex_t	*get_death_mutex_pointer(int philosopher_number)
{
	return (&(death_mutex_singleton(NULL)[philosopher_number]));
}

pthread_mutex_t	get_death_mutex(int philosopher_number)
{
	return (death_mutex_singleton(NULL)[philosopher_number]);
}
