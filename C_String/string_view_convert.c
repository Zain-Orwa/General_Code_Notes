/* ************************************************/
/*                                                */
/*   File:    string_view_convert.c               */
/*   Author:  Zain Orwa                           */
/*   Created: 2026/04/12 18:16:28                 */
/*   Updated: 2026/04/12 18:16:28                 */
/*                                                */
/* ************************************************/

#include <stdlib.h>
#include "string_view.h"

char 	*string_v_to_string(t_string_v v)
{
	int  i;
	char *str;

	str = malloc((v.size + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	while (i < v.size)
	{
		str[i] = v.data[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
