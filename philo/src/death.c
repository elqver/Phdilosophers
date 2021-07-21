#include "../includes/philosopher.h"

int	check_for_dead(void)
{
	int	amount;
	int	check_moment;
	int	i;

	i = 0;
	amount = get_programm_options().number_of_philosophers;
	while (i < amount)
	{
		pthread_mutex_lock(get_death_mutex_pointer(i));
		check_moment = get_time();
		if (get_death_time(i) < check_moment)
		{
			lock_print();
			printf("%d %d dead\n", check_moment, i + 1);
			return (1);
		}
		pthread_mutex_unlock(get_death_mutex_pointer(i));
		i++;
	}
	return (0);
}
