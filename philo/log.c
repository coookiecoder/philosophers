/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/20 12:27:44 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
void	join(char *buffer, char *time, char *ID, char *end)
{
	int	cursor;
	int	cursor_buffer;

	cursor = 0;
	cursor_buffer = 0;
	while (*(time + cursor))
		*(buffer + cursor_buffer++) = *(time + cursor++);
	cursor = 0;
	*(buffer + cursor_buffer++) = ' ';
	while (*(ID + cursor))
		*(buffer + cursor_buffer++) = *(ID + cursor++);
	cursor = 0;
	while (*(end + cursor))
		*(buffer + cursor_buffer++) = *(end + cursor++);
	*(buffer + cursor_buffer) = 0;
	free(time);
}

void	log_fork(unsigned long long int time, char *id_str)
{
	char	*time_str;
	char	buffer[100];

	time_str = itoa(time);
	join(buffer, time_str, id_str, " has taken a fork\n");
	write(1, buffer, ft_strlen(buffer));
}

void	log_eating(unsigned long long int time, char *id_str)
{
	char	*time_str;
	char	buffer[100];

	time_str = itoa(time);
	join(buffer, time_str, id_str, " is eating\n");
	write(1, buffer, ft_strlen(buffer));
}

void	log_sleeping(unsigned long long int time, char *id_str)
{
	char	*time_str;
	char	buffer[100];

	time_str = itoa(time);
	join(buffer, time_str, id_str, " is sleeping\n");
	write(1, buffer, ft_strlen(buffer));
}

void	log_thinking(unsigned long long int time, char *id_str)
{
	char	*time_str;
	char	buffer[100];

	time_str = itoa(time);
	join(buffer, time_str, id_str, " is thinking\n");
	write(1, buffer, ft_strlen(buffer));
}
