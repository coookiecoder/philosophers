/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/20 16:16:28 by abareux          ###   ########.fr       */
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

void	log_fork(unsigned long long int time, t_data *data)
{
	char	*time_str;
	char	buffer[100];
	int		len;

	time_str = itoa(time);
	join(buffer, time_str, data->idiot.idiot_number_str, " has taken a fork\n");
	len = ft_strlen(buffer);
	if (data->idiot.alive == 1)
		write(1, buffer, len);
}

void	log_eating(unsigned long long int time, t_data *data)
{
	char	*time_str;
	char	buffer[100];
	int		len;

	time_str = itoa(time);
	join(buffer, time_str, data->idiot.idiot_number_str, " is eating\n");
	len = ft_strlen(buffer);
	if (data->idiot.alive == 1)
		write(1, buffer, len);
}

void	log_sleeping(unsigned long long int time, t_data *data)
{
	char	*time_str;
	char	buffer[100];
	int		len;

	time_str = itoa(time);
	join(buffer, time_str, data->idiot.idiot_number_str, " is sleeping\n");
	len = ft_strlen(buffer);
	if (data->idiot.alive == 1)
		write(1, buffer, len);
}

void	log_thinking(unsigned long long int time, t_data *data)
{
	char	*time_str;
	char	buffer[100];
	int		len;

	time_str = itoa(time);
	join(buffer, time_str, data->idiot.idiot_number_str, " is thinking\n");
	len = ft_strlen(buffer);
	if (data->idiot.alive == 1)
		write(1, buffer, len);
}
