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

void	life(void	*data)
{
	t_settings	settings;
	t_idiot		idiot;

	settings = *data;
	idiot = *(data + sizeof(t_settings));
	while (idiot->alive)
	{
		eat(settings);
		sleep(settings);
		think_baka();
		eated++;
	}
}
