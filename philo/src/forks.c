#include "../includes/forks.h"

static pthread_mutex_t	*forks_singleton(pthread_mutex_t *new_forks)
{
	static pthread_mutex_t	*forks;

	if (new_forks)
	{
		free(forks);
		forks = new_forks;
	}
	return (forks);
}

static void	set_forks(pthread_mutex_t *new_forks)
{
	forks_singleton(new_forks);
}

void	set_up_forks(void)
{
	pthread_mutex_t	*forks;
	int				amount;
	int				i;

	amount = get_programm_options().number_of_philosophers;
	forks = calloc(sizeof(pthread_mutex_t), amount);
	i = 0;
	while (i < amount)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	set_forks(forks);
}

pthread_mutex_t	*get_fork_mutex_pointer(int n)
{
	return (&(forks_singleton(NULL)[n]));
}

pthread_mutex_t	get_fork_mutex(int n)
{
	return (forks_singleton(NULL)[n]);
}
