#ifndef TESTER_H
# define TESTER_H
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "ft_printf.h"
# define YELLOW "\x1b[93m"
# define RED "\x1b[91m"
# define GREEN "\x1b[92m"
# define BLUE "\x1b[96m"
# define STD_COL "\x1b[0m"
# define FIRST_HALF "                   +----------------------------------------+                   \n                   |                                        |                   \n                   |"
# define LAST_HALF "|                   \n                   |                                        |                   \n                   +----------------------------------------+                    \n\n"

void	printgreen(char *str)
{
	ft_printf("%s%s%s", GREEN, str, STD_COL);
}

void	printyellow(char *str)
{
	ft_printf("%s%s%s", YELLOW, str, STD_COL);
}

void	printred(char *str)
{
	ft_printf("%s%s%s", RED, str, STD_COL);
}

void	printblue(char *str)
{
	ft_printf("%s%s%s", BLUE, str, STD_COL);
}
#endif //TESTER_H
