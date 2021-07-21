#include "../includes/main.h"

pthread_mutex_t	*get_satiety_mutex_pointer(void)
{
	static pthread_mutex_t	satiety_mutex = PTHREAD_MUTEX_INITIALIZER;

	return (&satiety_mutex);
}

static int	*satiety_singleton(void)
{
	static int	hungry_amount;

	return (&hungry_amount);
}

void	set_hungry_amount(int amount)
{
	pthread_mutex_lock(get_satiety_mutex_pointer());
	*satiety_singleton() = amount;
	pthread_mutex_unlock(get_satiety_mutex_pointer());
}

int	get_hungry_amount(void)
{
	return (*(satiety_singleton()));
}

void	decrease_hungry_amount(void)
{
	pthread_mutex_lock(get_satiety_mutex_pointer());
	*satiety_singleton() -= 1;
	pthread_mutex_unlock(get_satiety_mutex_pointer());
}
