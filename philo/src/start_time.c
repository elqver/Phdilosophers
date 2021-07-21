#include "../includes/main.h"

static struct timeval	*start_time_singleton(void)
{
	static struct timeval	start_time;

	return (&start_time);
}

void	set_start_time(void)
{
	gettimeofday(start_time_singleton(), NULL);
}

struct timeval	get_start_time(void)
{
	return (*start_time_singleton());
}

int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec - get_start_time().tv_sec) * 1000 +\
			(current_time.tv_usec - get_start_time().tv_usec) / 1000);
}
