/* ************************************************/
/*                                                */
/*   File:    Array_SegFault.c                    */
/*   Author:  Zain Orwa                           */
/*   Created: 2026/04/14 15:24:09                 */
/*   Updated: 2026/04/14 15:24:09                 */
/*                                                */
/* ************************************************/

#include <stdio.h>

int main(void)
{
	//             0  1  2  3
	int data[4] = {1, 2, 3, 4};
	int index = 0;

	printf("index: ");
	scanf("%d", &index);

	printf("%d\n", data[index]);

	return (0);
}
