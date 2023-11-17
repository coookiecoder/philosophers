/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/17 18:34:49 by abareux          ###   ########.fr       */
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
		*(fork + idiot) = idiot + 1;
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
		(data + idiot)->idiot.idiot_number = idiot + 1;
		(data + idiot)->idiot.alive = 1;
		if (idiot == 1)
			(data + idiot)->idiot.left_fork = (fork + settings.nb_philo - 1);
		else
			(data + idiot)->idiot.left_fork = (fork + idiot - 1);
		if (idiot == (int) settings.nb_philo)
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

void	start_thread(t_settings settings, t_data *data, pthread_t *thread)
{
	int	idiot;
	idiot = 1;
	while (idiot <= (int) settings.nb_philo)
	{
		if (idiot % 2 == 1)
			pthread_create(thread + idiot, 0, life, data + idiot);
		idiot++;
	}
	idiot = 1;
	while (idiot <= (int) settings.nb_philo)
	{
		if (idiot % 2)
			pthread_create(thread + idiot, 0, life, data + idiot);
		idiot++;
	}
}

void	start_simulation(t_settings settings)
{
	t_data		*data;
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * settings.nb_philo);
	if (!thread)
		return ;
	data = create_data(settings);
	if (!data)
		return ;
	start_thread(settings, data, thread);
	//start_thread(settings, data);
	check_alive(data);
}
