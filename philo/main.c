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

t_settings	init_arg_without_end(char **argv)
{
	t_settings	settings;

	settings.nb_philo = ft_ullatoi(*(argv + 1));
	settings.time_to_die = ft_ullatoi(*(argv + 2));
	settings.time_to_eat = ft_ullatoi(*(argv + 3));
	settings.time_to_sleep = ft_ullatoi(*(argv + 4));
	settings.required_eating = 0;
	return (settings);
}

t_settings	init_arg_with_end(char **argv)
{
	t_settings	settings;

	settings.nb_philo = ft_ullatoi(*(argv + 1));
	settings.time_to_die = ft_ullatoi(*(argv + 2));
	settings.time_to_eat = ft_ullatoi(*(argv + 3));
	settings.time_to_sleep = ft_ullatoi(*(argv + 4));
	settings.required_eating = ft_ullatoi(*(argv + 5));
	return (settings);
}

_Bool	check_settings(t_settings settings)
{
	if (settings.nb_philo == 0)
		return (0);
	if (settings.time_to_die == 0)
		return (0);
	if (settings.time_to_eat == 0)
		return (0);
	if (settings.time_to_sleep == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_settings	settings;

	if (argc == 5)
		settings = init_arg_without_end(argv);
	if (argc == 6)
		settings = init_arg_with_end(argv);
	if (argc != 5 && argc != 6)
		return (write(1, "Error in the argument\n", 23), (void) settings, 1);
	if (!check_settings(settings))
		return (write(1, "Error in the argument or protection\n", 37), 1);
	if (argc == 6 && settings.required_eating == 0)
		return (write(1, "nothing happenend, what did you except ?\n", 42), 0);
	start_simulation(settings);
	return (0);
}
