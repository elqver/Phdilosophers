#include "../includes/philosopher.h"
#include "../includes/main.h"
#include "../includes/forks.h"

void	accurate_usleep(int	ms)
{
	int	target_time;

	target_time = get_time() + ms;
	while (target_time > get_time())
		usleep(1);
}

void	animate_philosophers(void)
{
	int	amount;
	int	i;

	i = 0;
	amount = get_programm_options().number_of_philosophers;
	while (i < amount)
	{
		pthread_create(get_philosopher_pointer(i), NULL, \
				philosopher_routine, (void *)(intptr_t) i);
		pthread_detach(get_philosopher(i));
		i++;
	}
}

static void	set_up(void)
{
	set_up_forks();
	set_up_philosophers();
	set_start_time();
	set_up_death_mutex();
	set_up_death_time();
	set_hungry_amount(get_programm_options().number_of_philosophers);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("wrong nubmer of argumetns\n");
		return (1);
	}
	set_programm_philosophers_number(ft_atoi(argv[1]));
	set_programm_times(ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc == 6)
		set_programm_times_to_satiety(ft_atoi(argv[5]));
	else
		set_programm_times_to_satiety(-1);
	set_up();
	animate_philosophers();
	while ((get_hungry_amount() && !check_for_dead()))
		usleep(1);
	return (0);
}
