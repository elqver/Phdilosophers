#include "../includes/philosopher.h"

static int	*death_time_singleton(int *new_death_time)
{
	static int	*death_time;

	if (new_death_time)
	{
		free(death_time);
		death_time = new_death_time;
	}
	return (death_time);
}

int	get_death_time(int philosopher_number)
{
	return (death_time_singleton(NULL)[philosopher_number]);
}

void	set_death_time(int philosopher_number)
{
	death_time_singleton(NULL)[philosopher_number] = \
		get_time() + get_programm_options().time_to_die;
}

void	set_up_death_time(void)
{
	int				i;
	int				amount;
	struct timeval	current_time;
	int				*death_time;

	amount = get_programm_options().number_of_philosophers;
	death_time = calloc(sizeof(int), amount);
	gettimeofday(&current_time, NULL);
	i = 0;
	while (i < amount)
	{
		death_time[i] = get_time() + get_programm_options().time_to_die;
		i++;
	}
	death_time_singleton(death_time);
}
