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

void	log_death(unsigned long long int time, char *id_str)
{
	char	*time_str;
	char	buffer[100];

	time_str = itoa(time);
	join(buffer, time_str, id_str, " has died\n");
	write(1, buffer, ft_strlen(buffer));
}
