/* ************************************************/
/*                                                */
/*   File:    string_view_utils.c                 */
/*   Author:  Zain Orwa                           */
/*   Created: 2026/04/12 16:04:34                 */
/*   Updated: 2026/04/12 16:04:34                 */
/*                                                */
/* ************************************************/

#include "string_view.h"

int 	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_string_v 	string_to_string_v(const char *str)
{
	t_string_v 	v;

	v.data = str;
	v.size = ft_strlen(str);
	return (v);
}

t_string_v string_v_slice(t_string_v v, int start, int len)
{
	t_string_v new_v;

	new_v.data = v.data + start;
	new_v.size = len;
	return (new_v);
}

int 	string_v_find_char(t_string_v v, char c)
{
	int i;

	i = 0;
	while (i < v.size)
	{
		if (v.data[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

