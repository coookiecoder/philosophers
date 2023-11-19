/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/17 18:29:23 by abareux          ###   ########.fr       */
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
void	log_death(t_data *data)
{
	printf("%llu %i died\n", gettime(), (data)->idiot.idiot_number);
}

static
void	update_state(t_data *data)
{
	int idiot;

	idiot = 0;
	while (idiot < (int) data->settings.nb_philo)
	{
		data->idiot.time_left -= 1;
		if (data->idiot.time_left == 0)
		{
			data->idiot.alive = -1;
			log_death(data + idiot);
			return ;
		}
		if (data->settings.required_eating)
			if (data->idiot.eaten == data->settings.required_eating)
				data->idiot.alive = 2;
		data++;
		idiot++;
	}
}

void	check_alive(t_data *data)
{
	int idiot;
	int dead;
	int end;

	while(1)
	{
		idiot = 0;
		dead = 0;
		end = 0;
		update_state(data);
		while (idiot < (int) data->settings.nb_philo)
		{
			if ((idiot + data)->idiot.alive == -1)
				dead = 1;
			if ((idiot + data)->idiot.alive == 2)
				end = end + 2;
			idiot++;
		}
		if (dead || end == (int) data->settings.nb_philo * 2)
			break;
		usleep(1000);
	}
	usleep(10000);
}
