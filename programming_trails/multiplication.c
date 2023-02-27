#include <stdio.h>

/**
 * This is a multiplication time table
 * Return = 0 if successfull
 *
 */

int main(void)
{
	int i = 1;
	while (i <= 100)
	{
		
		int j = 1;
		while (j <= 100)
		{
			printf("%d * %d = %d \n", i, j, i * j);
			j++;
		}
		
		i++;
		printf("\n");
	}
	
	return (0);
}
