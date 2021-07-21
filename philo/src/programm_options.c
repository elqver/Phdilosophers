#include "../includes/main.h"

static t_programm_options	*programm_options_singlton(void)
{
	static t_programm_options	programm_options;

	return (&programm_options);
}

void	set_programm_philosophers_number(int np)
{
	t_programm_options	*programm_options;

	programm_options = programm_options_singlton();
	programm_options->number_of_philosophers = np;
}

void	set_programm_times(int ttd, int tte, int tts)
{
	t_programm_options	*programm_options;

	programm_options = programm_options_singlton();
	programm_options->time_to_die = ttd;
	programm_options->time_to_eat = tte;
	programm_options->time_to_sleep = tts;
}

void	set_programm_times_to_satiety(int time)
{
	t_programm_options	*programm_options;

	programm_options = programm_options_singlton();
	programm_options->number_of_times_each_philosopher_must_eat = time;
}

t_programm_options	get_programm_options(void)
{
	return (*programm_options_singlton());
}
