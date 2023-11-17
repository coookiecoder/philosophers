/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/17 18:45:06 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <time.h>

// if you sature this type you are a mad man (THAT'S A WARNING)

typedef struct s_settings {
	unsigned long long int	nb_philo;
	unsigned long long int	time_to_die;
	unsigned long long int	time_to_eat;
	unsigned long long int	time_to_sleep;
	unsigned long long int	required_eating;
}	t_settings;

// structure of the idiot (i mean it, this asshole can die while sleeping 
// and while eating... yes while EATING)

typedef struct s_idiot {
	int		idiot_number;
	int		*left_fork;
	int		*right_fork;
	int		alive;
}	t_idiot;

// main struct for data mangement

typedef struct s_data {
	t_settings	settings;
	t_idiot		idiot;
}	t_data;

// ft_ullatoi.c

unsigned long long int	ft_ullatoi(char *str);

// simulation.c

void					start_simulation(t_settings settings);

// life.c

void					life(void *data);

#endif
