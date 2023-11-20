/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/20 11:12:25 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
unsigned long long int	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (1000000 * tv.tv_sec + tv.tv_usec);
}

static
void	eat_baka(t_data data)
{
	unsigned long long int	eating;

	if (data.idiot.alive == 1)
	{
		pthread_mutex_lock(data.idiot.left_fork);
		if (data.idiot.alive == 1)
			log_fork(gettime(), data.idiot.idiot_number);
		pthread_mutex_lock(data.idiot.right_fork);
		if (data.idiot.alive == 1)
			log_fork(gettime(), data.idiot.idiot_number);
		eating = 0;
		if (data.idiot.alive == 1)
			log_eating(gettime(), data.idiot.idiot_number);
	}
	while (data.idiot.alive == 1 && eating < data.settings.time_to_eat * 100)
	{
		eating = eating + 100;
		usleep(100);
	}
	pthread_mutex_unlock(data.idiot.left_fork);
	pthread_mutex_unlock(data.idiot.right_fork);
}

static
void	sleep_baka(t_data data)
{
	unsigned long long int	sleep;

	sleep = 0;
	if (data.idiot.alive == 1)
		log_sleeping(gettime(), data.idiot.idiot_number);
	while (data.idiot.alive == 1 && sleep < data.settings.time_to_sleep * 100)
	{
		sleep = sleep + 100;
		usleep(100);
	}
}

static
void	think_baka(t_data data)
{
	if (data.idiot.alive == 1)
		log_thinking(gettime(), data.idiot.idiot_number);
}

void	*life(void	*data)
{
	unsigned long long int	time_to_die;

	time_to_die = ((t_data *)data)->settings.time_to_die * 10;
	((t_data *)data)->idiot.time_left = time_to_die;
	((t_data *)data)->idiot.eaten = 0;
	while (((t_data *)data)->idiot.alive == 1)
	{
		eat_baka(*((t_data *)data));
		((t_data *)data)->idiot.time_left = time_to_die;
		((t_data *)data)->idiot.eaten += 1;
		sleep_baka(*((t_data *)data));
		think_baka(*((t_data *)data));
	}
	eat_baka(*((t_data *)data));
	return (NULL);
}
