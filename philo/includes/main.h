#ifndef MAIN_H
# define MAIN_H

# include <sys/time.h>
# include <pthread.h>

typedef struct s_programm_options
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}					t_programm_options;

void				set_programm_philosophers_number(int np);
void				set_programm_times(int ttd, int tte, int tts);
void				set_programm_times_to_satiety(int time);
t_programm_options	get_programm_options(void);

void				careful_print(char *message, int time_moment, \
									int philosopher_number);
void				lock_print(void);
void				unlock_print(void);

void				set_start_time(void);
int					get_time(void);
void				accurate_usleep(int	ms);
int					ft_atoi(const char *str);

#endif
