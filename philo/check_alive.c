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

void	check_alive(t_data *data)
{
	int idiot;
	int dead;
	int end;

	while(1)
	{
		idiot = 0;
		end = 0;
		while (idiot < *data.settings.nb_philo)
		{
			if (*(idiot + data).idiot.alive == -1)
				dead = 1;
			if (*(idiot + data).idiot.alive == 2)
				end = end + 2;
			idiot++;
		}
		if (dead || end == *data.settings.nb_philo * 2)
			break;
	}
}
