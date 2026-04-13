/* ************************************************/
/*                                                */
/*   File:    main.c                              */
/*   Author:  Zain Orwa                           */
/*   Created: 2026/04/13 11:48:26                 */
/*   Updated: 2026/04/13 11:48:26                 */
/*                                                */
/* ************************************************/

#include <stdlib.h>
#include <unistd.h>
#include "string_view.h"

int main(void)
{
	t_string_v text;
	t_string_v word;
	char 			 *copy;
	int 			 end;

	text = string_to_string_v("   Hello World   ");
	text = string_v_trim_all(text);
	end  = string_v_find_char(text, ' ');
	word = string_v_slice(text, 0, end);
	write(1, word.data, word.size);
	write(1, "\n", 1);
	copy = string_v_to_string(word);
	if (copy)
	{
		write(1, copy, ft_strlen(copy));
		write(1, "\n", 1);
		free(copy);	
	}
	return (0);
}



