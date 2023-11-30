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
	return (1000 * tv.tv_sec + tv.tv_usec / 1000);
}

static
void	genocide_idiot(t_data *data)
{
	int	idiot;

	idiot = 0;
	while (idiot < (int) data->settings.nb_philo - 1)
	{
		data->idiot.alive = -1;
		data->idiot.time_left = 1;
		data++;
		idiot++;
	}
	data->idiot.alive = -1;
	data->idiot.time_left = 1;
}

static
void	update_state(t_data *data)
{
	int		idiot;

	idiot = 0;
	while (idiot < (int) data->settings.nb_philo)
	{
		data->idiot.time_left -= 1;
		if (data->idiot.time_left == 0)
		{
			data->idiot.alive = -1;
			log_death(gettime(), data->idiot.idiot_number_str);
			return ;
		}
		if (data->settings.required_eating)
			if (data->idiot.eaten == data->settings.required_eating)
				data->idiot.alive = 2;
		idiot++;
		if (idiot < (int) data->settings.nb_philo)
			data++;
	}
	return ;
}

static
void	every_ms(t_data *data)
{
	static unsigned long long int	last = 0;

	if (!last)
		last = gettime();
	if (last - gettime() >= 1000)
	{
		update_state(data);
		last = gettime();
	}
}

void	check_alive(t_data *data)
{
	int	idiot;
	int	dead;
	int	end;

	while (1)
	{
		idiot = 0;
		dead = 0;
		end = 0;
		every_ms(data);
		while (idiot < (int) data->settings.nb_philo)
		{
			if ((idiot + data)->idiot.alive == -1)
				dead = 1;
			if ((idiot + data)->idiot.alive == 2)
				end = end + 2;
			idiot++;
		}
		if (dead)
			genocide_idiot(data);
		if (dead || end == (int) data->settings.nb_philo * 2)
			break ;
	}
}
