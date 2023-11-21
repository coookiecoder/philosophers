/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
unsigned long long int	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (1000 * tv.tv_sec + tv.tv_usec / 1000LL);
}

static
void	eat_baka(t_data *data)
{
	if (data->idiot.alive == 1)
	{
		pthread_mutex_lock(data->idiot.left_fork);
		log_fork(gettime(), data);
		pthread_mutex_lock(data->idiot.right_fork);
		log_fork(gettime(), data);
		if (data->idiot.alive == 1)
			log_eating(gettime(), data);
	}
	if (data->idiot.time_left >= data->settings.time_to_eat)
		usleep(data->settings.time_to_eat * 1000);
	else
		usleep(data->settings.time_to_die * 1000);
	pthread_mutex_unlock(data->idiot.left_fork);
	pthread_mutex_unlock(data->idiot.right_fork);
}

static
void	sleep_baka(t_data *data)
{
	if (data->idiot.alive == 1)
		log_sleeping(gettime(), data);
	if (data->idiot.time_left >= data->settings.time_to_sleep)
		usleep(data->settings.time_to_sleep * 1000);
	else
		usleep(data->settings.time_to_die * 1000);
	if (data->idiot.alive == 1)
		log_thinking(gettime(), data);
}

void	*life(void	*data)
{
	unsigned long long int	time_to_die;

	time_to_die = ((t_data *)data)->settings.time_to_die;
	((t_data *)data)->idiot.time_left = time_to_die;
	((t_data *)data)->idiot.eaten = 0;
	while (((t_data *)data)->idiot.alive == 1)
	{
		eat_baka(data);
		((t_data *)data)->idiot.time_left = time_to_die;
		((t_data *)data)->idiot.eaten += 1;
		sleep_baka(data);
	}
	return (NULL);
}
