/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/17 17:02:35 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*create_fork(t_settings settings)
{
	int	*fork;
	int	idiot;

	fork = malloc(sizeof(int) * settings.nb_philo);
	if (!fork)
		return (NULL);
	idiot = 0;
	while (idiot < (int) settings.nb_philo)
	{
		*(fork + idiot) = idiot;
		idiot++;
	}
	return (fork);
}

void	set_data(t_settings settings, t_data *data, int *fork)
{
	int	idiot;

	idiot = 0;
	while (idiot < (int) settings.nb_philo)
	{
		(data + idiot)->settings = settings;
		(data + idiot)->idiot.idiot_number = idiot;
		(data + idiot)->idiot.alive = 1;
		if (idiot == 0)
			(data + idiot)->idiot.left_fork = (fork + settings.nb_philo - 1);
		else
			(data + idiot)->idiot.left_fork = (fork + idiot - 1);
		if (idiot == (int) settings.nb_philo - 1)
			(data + idiot)->idiot.right_fork = (fork);
		else
			(data + idiot)->idiot.right_fork = (fork + idiot + 1);
		idiot++;
	}
}

t_data	*create_data(t_settings settings)
{
	t_data	*data;
	int		*fork;

	data = malloc(sizeof(t_data) * settings.nb_philo);
	if (!data)
		return (NULL);
	fork = create_fork(settings);
	if (!fork)
		return (free(data), NULL);
	set_data(settings, data, fork);
	return (data);
}

void	start_simulation(t_settings settings)
{
	t_data	*data;
	int		idiot;

	data = create_data(settings);
	idiot = 0;
	while (idiot < (int) settings.nb_philo)
	{
		printf("idiot number : %i created ", (data + idiot)->idiot.idiot_number);
		printf("left fork : %i assigned ", *(data + idiot)->idiot.left_fork);
		printf("right fork : %i assigned\n", *(data + idiot++)->idiot.right_fork);
	}
}
