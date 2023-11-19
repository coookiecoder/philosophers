/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/17 18:46:23 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
unsigned long long int gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (1000000 * tv.tv_sec + tv.tv_usec);
}

static
void	eat_baka(t_data data)
{
	unsigned long long int	eating;

	pthread_mutex_lock(data.idiot.left_fork);
	//printf("%llu %i has taken a fork\n", gettime(), data.idiot.idiot_number);
	pthread_mutex_lock(data.idiot.right_fork);
	//printf("%llu %i has taken a fork\n", gettime(), data.idiot.idiot_number);
	eating = 0;
	if (data.idiot.alive == 1)
		printf("%llu %i is eating\n", gettime(), data.idiot.idiot_number);
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
	unsigned long long int	sleeping;

	sleeping = 0;
	if (data.idiot.alive == 1)
		printf("%llu %i is sleeping\n", gettime(), data.idiot.idiot_number);
	while (data.idiot.alive == 1 && sleeping < data.settings.time_to_sleep * 1000)
	{
		sleeping = sleeping + 1000;
		usleep(1000);
	}
}

static
void	think_baka(t_data data)
{
	if (data.idiot.alive)
		printf("%llu %i is thinking\n", gettime(), data.idiot.idiot_number);
}

void	*life(void	*data)
{
	unsigned long long int	time_to_die;

	time_to_die = ((t_data *)data)->settings.time_to_die;
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
	return (NULL);
}
