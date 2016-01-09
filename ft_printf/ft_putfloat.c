#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

double ft_power(double num, int pow)
{
   if (pow < 0)
      return (1 / ft_power(num, pow));
   else if (pow == 0)
      return (1);
   else
      return (num * ft_power(num, pow -1));
}

char	*ft_putfloat(double to_print, int accuracy)
{
   char *final;
   int	k;
   long double i;

   i = 1.0;
   k = 0;
   final = (char*)malloc(sizeof(char) * 200);
   while (i < to_print)
      i *= 10;
   while ((i = i / 10) >= 1)
   {
      final[k++] = (int)(to_print / i) + 48;
      to_print = (double)((int)to_print % (int)i) + to_print - (int)to_print;
   }
   if (accuracy > 0)
   {
      final[k++] = ',';
      while (accuracy-- > 0)
      {
	 to_print *= 10;
	 final[k++] = (int)to_print + 48;
	 to_print = to_print - (int)to_print;
      }
   }
   final[k] = '\0';
   return (final);
}

int main()
{
   char *str = ft_putfloat(3.1415, 3);
   printf("%s\n", str);
   str = ft_putfloat(2, 0);
   printf("%s\n", str);

   str = ft_putfloat(3.1415, 5);
   printf("%s\n", str);
   str = ft_putfloat(3.1415, 0);
   printf("%s\n", str);
   return (0);
}
