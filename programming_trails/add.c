#include <stdio.h>

/**
 *
 * First trail innusing the "maths.h" library
 * Return = 0
 */

int main(void)
{
  int i = 1;
  while (i <= 25)
    {

      int j = 1;
      while (j <= 25)
	{
	  printf("%d + %d = %d \n", i, j, i + j);
	  j++;
	}

      i++;
      printf("\n");
    }

 return(0);
}
