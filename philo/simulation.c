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
pthread_mutex_t	*create_fork(t_settings settings)
{
	pthread_mutex_t	*fork;
	int				idiot;

	fork = malloc(sizeof(pthread_mutex_t) * settings.nb_philo);
	if (!fork)
		return (NULL);
	idiot = 0;
	while (idiot < (int) settings.nb_philo)
	{
		pthread_mutex_init(fork + idiot, NULL);
		idiot++;
	}
	return (fork);
}

static
void	set_data(t_settings settings, t_data *data, pthread_mutex_t *fork)
{
	int	idiot;

	idiot = 0;
	while (idiot < (int) settings.nb_philo)
	{
		(data + idiot)->settings = settings;
		(data + idiot)->idiot.idiot_number = idiot + 1;
		(data + idiot)->idiot.idiot_number_str = itoa(idiot + 1);
		(data + idiot)->idiot.alive = 1;
		(data + idiot)->idiot.time_left = 10;
		if (idiot == 0)
			(data + idiot)->idiot.left_fork = (fork);
		else
			(data + idiot)->idiot.left_fork = (fork + idiot);
		if (idiot == (int) settings.nb_philo - 1)
			(data + idiot)->idiot.right_fork = (fork);
		else
			(data + idiot)->idiot.right_fork = (fork + idiot + 1);
		idiot++;
	}
}

static
t_data	*create_data(t_settings settings)
{
	pthread_mutex_t	*fork;
	t_data			*data;

	data = malloc(sizeof(t_data) * settings.nb_philo);
	if (!data)
		return (NULL);
	fork = create_fork(settings);
	if (!fork)
		return (free(data), NULL);
	set_data(settings, data, fork);
	return (data);
}

static
void	start_thread(t_settings settings, t_data *data, pthread_t *thread)
{
	int	idiot;

	idiot = 1;
	while (idiot < (int) settings.nb_philo)
	{
		pthread_create(thread + idiot, NULL, &life, data + idiot);
		idiot += 2;
	}
	usleep(1000);
	idiot = 0;
	while (idiot < (int) settings.nb_philo)
	{
		pthread_create(thread + idiot, NULL, &life, data + idiot);
		idiot += 2;
	}
}

void	start_simulation(t_settings settings)
{
	int			idiot;
	t_data		*data;
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * settings.nb_philo);
	if (!thread)
		return ;
	data = create_data(settings);
	if (!data)
		return ;
	start_thread(settings, data, thread);
	check_alive(data);
	idiot = 0;
	while (idiot < (int) settings.nb_philo)
	{
		pthread_join(*(thread + idiot), NULL);
		free((data + idiot)->idiot.idiot_number_str);
		idiot++;
	}
	free((data + settings.nb_philo - 1)->idiot.right_fork);
	free(data);
	free(thread);
}
