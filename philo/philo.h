/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/17 15:21:27 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>

// if you sature this type you are a mad man (THAT'S A WARNING)

typedef struct s_settings {
	unsigned long long int	nb_philo;
	unsigned long long int	time_to_die;
	unsigned long long int	time_to_eat;
	unsigned long long int	time_to_sleep;
	unsigned long long int	required_eating;
}	t_settings;

// ft_ullatoi.c

unsigned long long int	ft_ullatoi(char *str);

// simulation.c

void					start_simulation(t_settings settings);

#endif
