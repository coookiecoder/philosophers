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

unsigned long long int gettime(void)
{
	struct timeval	tv;

	gettimeofday(tv, NULL);
	return (tv->tv_usec);
}

void	think_baka(void)
{
	prinft("%llu %i is sleeping", gettime(), data.idiot.idiot_number);
	usleep(1000);
}

void	eat(t_data data)
{
	pthread_mutex_lock();
	pthread_mutex_lock();
	pthread_mutex_unlock();
	pthread_mutex_unlock();
	prinft("%llu %i is eating", gettime(), data.idiot.idiot_number);
}

void	life(void	*data)
{
	int	eating;
	int	sleeping;

	while (idiot->alive)
	{
		eat(settings, &eating);
		sleep(settings, &sleeping);
		think_baka();
		eated++;
	}
}
