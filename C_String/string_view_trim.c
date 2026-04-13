/* ************************************************/
/*                                                */
/*   File:    string_view_trim.c                  */
/*   Author:  Zain Orwa                           */
/*   Created: 2026/04/12 16:34:06                 */
/*   Updated: 2026/04/12 16:34:06                 */
/*                                                */
/* ************************************************/

#include "string_view.h"

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

t_string_v string_v_trim_left(t_string_v v)
{
	int i;

	i = 0;
	while (i < v.size && is_space(v.data[i]))
		i++;
	return (string_v_slice(v, i, v.size - i));
}

t_string_v string_v_trim_right(t_string_v v)
{
	int i;

	i = v.size;
	while (i >= 0 && is_space(v.data[i - 1]))
		i--;
	return (string_v_slice(v, 0, i));
}

t_string_v string_v_trim_all(t_string_v v)
{
	v = string_v_trim_left(v);
	v = string_v_trim_right(v);
	return (v);
}

