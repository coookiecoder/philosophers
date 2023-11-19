/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_ullatoi.c                                       :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/17 15:17:40 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

_Bool	is_sign_digit(char c)
{
	if (c == '+')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

unsigned long long int	ft_ullatoi(char *str)
{
	unsigned long long int	result;

	result = 0;
	while (!is_sign_digit(*str) && *str != '-' && *str)
		str++;
	if (!*str || *str == '-')
		return (result);
	while (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
		result = (result * 10) + *(str++) - '0';
	return (result);
}
