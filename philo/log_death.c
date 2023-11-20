/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   log_death.c                                        :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/20 11:09:22 by abareux          ###   ########.fr       */
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
	free(ID);
}

void	log_death(unsigned long long int time, int ID)
{
	char	*time_str;
	char	*id_str;
	char	*buffer;

	time_str = itoa(time);
	id_str = itoa(ID);
	buffer = malloc(ft_strlen(time_str) + ft_strlen(id_str) + 11 + 1);
	if (!buffer)
		return ;
	join(buffer, time_str, id_str, " has died\n");
	write(1, buffer, ft_strlen(buffer));
	free(buffer);
}
