/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/20 13:01:17 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
unsigned long long int	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (1000 * tv.tv_sec + tv.tv_usec / 1000);
}

static
void	eat_baka(t_data data)
{
	unsigned long long int	eating;

	if (data.idiot.alive == 1)
	{
		pthread_mutex_lock(data.idiot.left_fork);
		log_fork(gettime(), data.idiot.idiot_number_str);
		pthread_mutex_lock(data.idiot.right_fork);
		log_fork(gettime(), data.idiot.idiot_number_str);
		eating = 0;
		if (data.idiot.alive == 1)
			log_eating(gettime(), data.idiot.idiot_number_str);
	}
	while (data.idiot.alive == 1 && eating < data.settings.time_to_eat * 1000)
	{
		eating = eating + 1000;
		usleep(1000);
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
		log_sleeping(gettime(), data.idiot.idiot_number_str);
	while (data.idiot.alive == 1 && sleep < data.settings.time_to_sleep * 1000)
	{
		sleep = sleep + 1000;
		usleep(1000);
	}
	if (data.idiot.alive == 1)
		log_thinking(gettime(), data.idiot.idiot_number_str);
}

void	*life(void	*data)
{
	unsigned long long int	time_to_die;

	time_to_die = ((t_data *)data)->settings.time_to_die * 10;
	((t_data *)data)->idiot.time_left = time_to_die;
	((t_data *)data)->idiot.eaten = 0;
	if (((t_data *)data)->idiot.idiot_number % 2 == 0)
		usleep(1000);
	while (((t_data *)data)->idiot.alive == 1)
	{
		eat_baka(*((t_data *)data));
		((t_data *)data)->idiot.time_left = time_to_die;
		((t_data *)data)->idiot.eaten += 1;
		sleep_baka(*((t_data *)data));
	}
	eat_baka(*((t_data *)data));
	return (NULL);
}
