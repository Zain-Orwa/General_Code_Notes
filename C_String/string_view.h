/* ************************************************/
/*                                                */
/*   File:    string_view.h                       */
/*   Author:  Zain Orwa                           */
/*   Created: 2026/04/12 15:10:28                 */
/*   Updated: 2026/04/12 15:10:28                 */
/*                                                */
/* ************************************************/

#ifndef STRING_VIEW_H
#define STRING_VIEW_H

typedef struct s_string_v
{
	const	char *data;
	int  size;
} t_string_v;

int 				ft_strlen(const char *str);
t_string_v	string_to_string_v(const char *str);
t_string_v  string_v_slice(t_string_v v, int start, int len);
int 				string_v_find_char(t_string_v v, char c);
t_string_v 	string_v_trim_left(t_string_v v);
t_string_v 	string_v_trim_right(t_string_v v);
t_string_v 	string_v_trim_all(t_string_v v);
char 				*string_v_to_string(t_string_v v);

#endif
