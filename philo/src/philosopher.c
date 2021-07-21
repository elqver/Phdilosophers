#include "../includes/philosopher.h"

static int	get_first_fork_number(int philosopher_number)
{
	if (philosopher_number % 2 == 0)
	{
		if (philosopher_number == \
				get_programm_options().number_of_philosophers - 1)
			return (0);
		return (philosopher_number + 1);
	}
	return (philosopher_number);
}

static int	get_second_fork_number(int philosopher_number)
{
	if (philosopher_number % 2 == 0)
		return (philosopher_number);
	if (philosopher_number == get_programm_options().number_of_philosophers - 1)
		return (0);
	return (philosopher_number + 1);
}

static void	philosopher_existance_loop(int pn, int ffn, int sfn)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(get_fork_mutex_pointer(ffn));
		careful_print("%d %d has taken a fork\n", get_time(), pn + 1);
		pthread_mutex_lock(get_fork_mutex_pointer(sfn));
		careful_print("%d %d has taken a fork\n", get_time(), pn + 1);
		careful_print("%d %d is eating\n", get_time(), pn + 1);
		pthread_mutex_lock(get_death_mutex_pointer(pn));
		set_death_time(pn);
		pthread_mutex_unlock(get_death_mutex_pointer(pn));
		accurate_usleep(get_programm_options().time_to_eat);
		careful_print("%d %d is sleeping\n", get_time(), pn + 1);
		pthread_mutex_unlock(get_fork_mutex_pointer(sfn));
		pthread_mutex_unlock(get_fork_mutex_pointer(ffn));
		accurate_usleep(get_programm_options().time_to_sleep);
		if (++i == \
		get_programm_options().number_of_times_each_philosopher_must_eat &&\
		get_programm_options().number_of_times_each_philosopher_must_eat != -1)
			decrease_hungry_amount();
	}
}

void	*philosopher_routine(void *arg)
{
	int	philosopher_number;
	int	first_fork_number;
	int	second_fork_number;

	philosopher_number = (int)arg;
	first_fork_number = get_first_fork_number(philosopher_number);
	second_fork_number = get_second_fork_number(philosopher_number);
	philosopher_existance_loop(philosopher_number, \
								first_fork_number, \
								second_fork_number);
	return (NULL);
}
