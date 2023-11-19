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

void	log_fork(unsigned long long int time, int ID)
{
	char	*time_str;
	char	*ID_str;
	char	*buffer;

	time_str = itoa(time);
	ID_str = itoa(ID);
	buffer = malloc(ft_strlen(time_str) + ft_strlen(ID_str) + 19 + 1);
	if (!buffer)
		return ;
	join(buffer, time_str, ID_str, " has taken a fork\n");
	write(1, buffer, ft_strlen(buffer));
	free(buffer);
}

void	log_eating(unsigned long long int time, int ID)
{
	char	*time_str;
	char	*ID_str;
	char	*buffer;

	time_str = itoa(time);
	ID_str = itoa(ID);
	buffer = malloc(ft_strlen(time_str) + ft_strlen(ID_str) + 13 + 1);
	if (!buffer)
		return ;
	join(buffer, time_str, ID_str, " is eating\n");
	write(1, buffer, ft_strlen(buffer));
	free(buffer);
}

void	log_sleeping(unsigned long long int time, int ID)
{
	char	*time_str;
	char	*ID_str;
	char	*buffer;

	time_str = itoa(time);
	ID_str = itoa(ID);
	buffer = malloc(ft_strlen(time_str) + ft_strlen(ID_str) + 15 + 1);
	if (!buffer)
		return ;
	join(buffer, time_str, ID_str, " is sleeping\n");
	write(1, buffer, ft_strlen(buffer));
	free(buffer);
}

void	log_thinking(unsigned long long int time, int ID)
{
	char	*time_str;
	char	*ID_str;
	char	*buffer;

	time_str = itoa(time);
	ID_str = itoa(ID);
	buffer = malloc(ft_strlen(time_str) + ft_strlen(ID_str) + 15 + 1);
	if (!buffer)
		return ;
	join(buffer, time_str, ID_str, " is thinking\n");
	write(1, buffer, ft_strlen(buffer));
	free(buffer);
}
