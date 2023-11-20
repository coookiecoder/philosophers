/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/20 12:55:37 by abareux          ###   ########.fr       */
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
	while (idiot < (int) data->settings.nb_philo)
	{
		data->idiot.alive = -1;
		data++;
		idiot++;
	}
}

static
int	update_state(t_data *data)
{
	t_data	*buffer;
	int		idiot;

	buffer = data;
	idiot = 0;
	while (idiot < (int) data->settings.nb_philo)
	{
		data->idiot.time_left -= 1;
		if (data->idiot.time_left == 0)
		{
			log_death(gettime(), data->idiot.idiot_number_str);
			genocide_idiot(buffer);
			return (1);
		}
		if (data->settings.required_eating)
			if (data->idiot.eaten == data->settings.required_eating)
				data->idiot.alive = 2;
		data++;
		idiot++;
	}
	return (0);
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
		if (update_state(data))
			break ;
		while (idiot < (int) data->settings.nb_philo)
		{
			if ((idiot + data)->idiot.alive == -1)
				dead = 1;
			if ((idiot + data)->idiot.alive == 2)
				end = end + 2;
			idiot++;
		}
		if (dead || end == (int) data->settings.nb_philo * 2)
			break ;
		usleep(100);
	}
	usleep(1000);
}
