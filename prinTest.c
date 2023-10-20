/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:33:45 by tgibert           #+#    #+#             */
/*   Updated: 2023/10/20 09:46:35 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tester.h"

int	global_ok = 1;

void	sep(void)
{
	printyellow("\n================================================================================\n\n");
}

void	fill_blank(char *str, int width, void (*f)(char *))
{
	int	i = strlen(str);
	int	j = (width - i) / 2;
	int	count = 0;
	
	while (count < j)
	{
		ft_printf(" ");
		count++;
	}
	if (i % 2)
		ft_printf(" ");
	f(str);
	count = 0;
	while (count < j)
	{
		ft_printf(" ");
		count++;
	}
}

void	cool_message(char *str)
{
	printgreen(FIRST_HALF);
	fill_blank(str, 40, printgreen);
	printgreen(LAST_HALF);
}
void	bad_message(char *str)
{
	printred(FIRST_HALF);
	fill_blank(str, 40, printred);
	printred(LAST_HALF);
}

void	title_message(char *str)
{
	printyellow(FIRST_HALF);
	fill_blank(str, 40, printyellow);
	printyellow(LAST_HALF);
}

void	subtestc(const char *str, char c, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, c);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, c);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	subtestc2(const char *str, char c, char d, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, c, d);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, c, d);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	testc(void)
{
	
	int	ok = 1;
	int	*ok_ptr;
	
	ok_ptr = &ok;
	subtestc("Insert in the middle : %c : of a string", 'a', ok_ptr);
	subtestc("%c : Insert at the beginning of a string", '*', ok_ptr);
	subtestc("Insert at the end of a string : %c", '[', ok_ptr);
	printf("Only the character :\n");
	subtestc("%c", 'x', ok_ptr);
	subtestc2("Multiple times here : %c : and at the end : %c", '+', 'w', ok_ptr);
	subtestc("%c : Multiple times at the beginning and here : %c : with only one argument", '$', ok_ptr);
	subtestc2("%c : Multiple times at the beginning and here : %c : in the middle", '$', 'f', ok_ptr);
	subtestc2("%c : Multiple times at the beginning, here : %c : and here : %c : with two arguments", '$', 'f', ok_ptr);
	if (ok)
		cool_message("%c is OK, Well Done !");
	else
	{
		bad_message("Already KO ? Smells bad for you !");
		global_ok = 0;
	}
}

void	subtests2(char *str, char *s1, char *s2, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, s1, s2);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, s1, s2);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	subtests(char *str, char *s, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, s);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, s);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	tests(void)
{
	int	ok = 1;
	int	*ok_ptr;
	char	*nullptr;
	char	bad_str[4] = {'4', '2', ' ', '!'};
	
	nullptr = NULL;
	ok_ptr = &ok;
	subtests("Insert in the middle : %s : of a string", "Salut 42", ok_ptr);
	subtests("%s : Insert at the beginning of a string", "Salut 42", ok_ptr);
	subtests("Insert at the end of a string : %s", "I'm in the end", ok_ptr);
	printf("Only the string :\n");
	subtests("%s", "x", ok_ptr);
	subtests("When char * is NULL : %s", nullptr, ok_ptr);
	subtests("When the string is empty, ther shoul be no spaces between these colons :%s:", "", ok_ptr);
	subtests2("Multiple times here : %s : and at the end : %s", "Salut", "42 !", ok_ptr);
	subtests2("%s : Multiple times at the beginning and here : %s : in the middle", "Salut", "42 !",ok_ptr);
	subtests("%s : Two times at the beginning and here : %s : with only one argument", "Salut 42 !",ok_ptr);
	subtests2("%s : Three times at the beginning, here : %s : and here : %s : with only two arguments", "Salut", "42 !",ok_ptr);
	subtests("What if the string is not null_terminated : %s", bad_str, ok_ptr);
	
	if (ok)
		cool_message("%s is OK, Well Done !");
	else
	{
		bad_message("%s is not working, try again !");
		global_ok = 0;
	}
}

void	subtestp2(char *str, void *ptr, void *ptr2, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, ptr, ptr2);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, ptr, ptr2);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}
void	subtestp(char *str, void *ptr, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, ptr);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, ptr);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	testp(void)
{
	
	int	ok = 1;
	int	*ok_ptr;
	char *s_ptr = "Where is this string ?";
	void	*n_ptr = NULL;
	
	ok_ptr = &ok;
	subtestp("Insert in the middle : %p : of a string", ok_ptr, ok_ptr);
	subtestp("%p : Insert at the beginning of a string", s_ptr, ok_ptr);
	subtestp("Insert at the end of a string : %p", s_ptr, ok_ptr);
	printf("Only the Address :\n");
	subtestp("%p", ok_ptr, ok_ptr);
	subtestp2("Multiple times here : %p : and at the end : %p", ok_ptr, s_ptr, ok_ptr);
	subtestp("%p : Two times at the beginning and here : %p : with only one argument", s_ptr, ok_ptr);
	subtestp2("%p : Three times at the beginning, here : %p : and here : %p : with two arguments", ok_ptr, s_ptr, ok_ptr);
	subtestp("What about a NULL pointer ? : %p", n_ptr, ok_ptr);
	if (ok)
		cool_message("%p is OK, Well Done !");
	else
	{
		bad_message("Ooops, there's a problem with the Address");
		global_ok = 0;
	}
}

void	subtestd2(char *str, int d, int d2, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, d, d2);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, d, d2);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	subtestd(char *str, int d, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, d);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, d);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}
void	testd(void)
{
	int	ok = 1;
	int	*ok_ptr;
		
	ok_ptr = &ok;
	subtestd("Insert in the middle : %d : of a string", 42, ok_ptr);
	subtestd("%d : Insert at the beginning of a string", -42, ok_ptr);
	subtestd("Insert at the end of a string : %d", 42, ok_ptr);
	printf("Only the Decimal :\n");
	subtestd("%d", -42, ok_ptr);
	subtestd2("Multiple times here : %d : and at the end : %d", 42, -42, ok_ptr);
	subtestd("%d : Two times at the beginning and here : %d : with only one argument", 42, ok_ptr);
	subtestd2("%d : Three times at the beginning, here : %d : and here : %d : with two arguments", 42, -42, ok_ptr);
	subtestd("What about a 0 ? : %d", 0, ok_ptr);
	subtestd("INT_MAX = %d", INT_MAX, ok_ptr);
	subtestd("INT_MIN = %d", INT_MIN, ok_ptr);
/* 	subtestd("LONG_MIN = %d", LONG_MIN, ok_ptr);
	subtestd("LONG_MAX = %d", LONG_MAX, ok_ptr);
	subtestd("UINT_MAX = %d", UINT_MAX, ok_ptr); */
	subtestd("333 base 8 = %d", '\333', ok_ptr);
	if (ok)
		cool_message("%d is OK, Well Done !");
	else
	{
		bad_message("Not OK for Decimals, wait for it, integers are next");
		global_ok = 0;
	}
}
void	subtesti2(char *str, int i, int i2, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, i, i2);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, i, i2);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	subtesti(char *str, int i, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, i);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, i);
	printf("\n");
	ft_printf("stdout : %i\nft_out : %i\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}
void	testi(void)
{
	int	ok = 1;
	int	*ok_ptr;
		
	ok_ptr = &ok;
	subtesti("Insert in the middle : %i : of a string", 42, ok_ptr);
	subtesti("%i : Insert at the beginning of a string", -42, ok_ptr);
	subtesti("Insert at the end of a string : %i", 42, ok_ptr);
	printf("Only the Decimal :\n");
	subtesti("%i", -42, ok_ptr);
	subtesti2("Multiple times here : %i : and at the end : %i", 42, -42, ok_ptr);
	subtesti("%i : Two times at the beginning and here : %i : with only one argument", 42, ok_ptr);
	subtesti2("%i : Three times at the beginning, here : %i : and here : %i : with two arguments", 42, -42, ok_ptr);
	subtesti("What about a 0 ? : %i", 0, ok_ptr);
	subtesti("INT_MAX = %i", INT_MAX, ok_ptr);
	subtesti("INT_MIN = %i", INT_MIN, ok_ptr);
/* 	subtesti("LONG_MIN = %i", LONG_MIN, ok_ptr);
	subtesti("LONG_MAX = %i", LONG_MAX, ok_ptr);
	subtesti("UINT_MAX = %i", UINT_MAX, ok_ptr); */
	subtesti("333 base 8 = %i", '\333', ok_ptr);
	if (ok)
		cool_message("%i is OK, Well Done !");
	else
	{
		bad_message("Not really familiar with numbers, are you ?");
		global_ok = 0;
	}
}

void	subtestx2(char *str, unsigned int x, unsigned int x2, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, x, x2);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, x, x2);
	printf("\n");
	ft_printf("stdout : %d\nft_out : %d\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	subtestx(char *str, unsigned int x, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, x);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, x);
	printf("\n");
	ft_printf("stdout : %d\nft_out : %d\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	testx(void)
{
	int	ok = 1;
	int	*ok_ptr;
		
	ok_ptr = &ok;
	subtestx("Insert in the middle : %x : of a string", 42, ok_ptr);
	subtestx("%x : Insert at the beginning of a string", -42, ok_ptr);
	subtestx("Insert at the end of a string : %x", 42, ok_ptr);
	printf("Only the Decimal :\n");
	subtestx("%x", -42, ok_ptr);
	subtestx2("Multiple times here : %x : and at the end : %x", 42, -42, ok_ptr);
	subtestx("%x : Two times at the beginning and here : %x : with only one argument", 42, ok_ptr);
	subtestx2("%x : Three times at the beginning, here : %x : and here : %x : with two arguments", 42, -42, ok_ptr);
	subtestx("What about a 0 ? : %x", 0, ok_ptr);
	subtestx("INT_MAX = %x", INT_MAX, ok_ptr);
	subtestx("INT_MIN = %x", INT_MIN, ok_ptr);
	/* subtestx("LONG_MIN = %x", LONG_MIN, ok_ptr);
	subtestx("LONG_MAX = %x", LONG_MAX, ok_ptr); */
	subtestx("UINT_MAX = %x", UINT_MAX, ok_ptr);
	subtestx("333 base 8 = %x", '\333', ok_ptr);
	if (ok)
		cool_message("%x is OK, Well Done !");
	else
	{
		bad_message("Ooops, there's a problem with the Address");
		global_ok = 0;
	}
}

void	subtestX2(char *str, unsigned int X, unsigned int X2, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, X, X2);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, X, X2);
	printf("\n");
	ft_printf("stdout : %d\nft_out : %d\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	subtestX(char *str, unsigned int X, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, X);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, X);
	printf("\n");
	ft_printf("stdout : %X\nft_out : %X\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}
void	testX(void)
{
	int	ok = 1;
	int	*ok_ptr;
		
	ok_ptr = &ok;
	subtestX("Insert in the middle : %X : of a string", 42, ok_ptr);
	subtestX("%X : Insert at the beginning of a string", -42, ok_ptr);
	subtestX("Insert at the end of a string : %X", 42, ok_ptr);
	printf("Only the Decimal :\n");
	subtestX("%X", -42, ok_ptr);
	subtestX2("Multiple times here : %X : and at the end : %X", 42, -42, ok_ptr);
	subtestX("%X : Two times at the beginning and here : %X : with only one argument", 42, ok_ptr);
	subtestX2("%X : Three times at the beginning, here : %X : and here : %X : with two arguments", 42, -42, ok_ptr);
	subtestX("What about a 0 ? : %X", 0, ok_ptr);
	subtestX("INT_MAX = %X", INT_MAX, ok_ptr);
	subtestX("INT_MIN = %X", INT_MIN, ok_ptr);
/* 	subtestX("LONG_MIN = %X", LONG_MIN, ok_ptr);
	subtestX("LONG_MAX = %X", LONG_MAX, ok_ptr); */
	subtestX("UINT_MAX = %X", UINT_MAX, ok_ptr);
	subtestX("333 base 8 = %X", '\333', ok_ptr);
	if (ok)
		cool_message("%X is OK, Well Done !");
	else
	{
		bad_message("Ooops, there's a problem with the Address");
		global_ok = 0;
	}
}


void	subtestu2(char *str, unsigned int u, unsigned int u2, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, u, u2);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, u, u2);
	printf("\n");
	ft_printf("stdout : %d\nft_out : %d\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	subtestu(char *str, unsigned int u, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str, u);
	printf("\nft_ : ");
	fflush(stdout);
	ft_ = ft_printf(str, u);
	printf("\n");
	ft_printf("stdout : %d\nft_out : %d\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	testu(void)
{
	int	ok = 1;
	int	*ok_ptr;
		
	ok_ptr = &ok;
	subtestu("Insert in the middle : %u : of a string", 42, ok_ptr);
	subtestu("%u : Insert at the beginning of a string", -42, ok_ptr);
	subtestu("Insert at the end of a string : %u", 42, ok_ptr);
	printf("Only the Decimal :\n");
	subtestu("%u", -42, ok_ptr);
	subtestu2("Multiple times here : %u : and at the end : %u", 42, -42, ok_ptr);
	subtestu("%u : Two times at the beginning and here : %u : with only one argument", 42, ok_ptr);
	subtestu2("%u : Three times at the beginning, here : %u : and here : %u : with two arguments", 42, -42, ok_ptr);
	subtestu("What about a 0 ? : %u", 0, ok_ptr);
	subtestu("INT_MAX = %u", INT_MAX, ok_ptr);
	subtestu("INT_MIN = %u", INT_MIN, ok_ptr);
	/* subtestu("LONG_MIN = %u", LONG_MIN, ok_ptr);
	subtestu("LONG_MAX = %u", LONG_MAX, ok_ptr); */
	subtestu("UINT_MAX = %u", UINT_MAX, ok_ptr);
	subtestu("333 base 8 = %u", '\333', ok_ptr);
	if (ok)
		cool_message("%u is OK, Well Done !");
	else
	{
		bad_message("Ooops, there's a problem with Unsigned");
		global_ok = 0;
	}
}

/* void	subtestnoparam(char *str, int *ok)
{
	int	std = 0;
	int	ft_ = 0;
	
	printf("std : ");
	std = printf(str);
	printf("\n");
	fflush(stdout);
	ft_printf("ft_ : ");
	ft_ = ft_printf(str);
	ft_printf("\n");
	ft_printf("stdout : %d\nft_out : %d\n", std, ft_);
	if (std != ft_)
	{
		printred("KO\n");
		*ok = 0;
	}
	else
		printgreen("OK\n");
}

void	testothers(void)
{
	int	ok = 1;
	int	*ok_ptr;
	void *ptr = NULL;
		
	ok_ptr = &ok;
	subtestnoparam("", ok_ptr);
	subtestnoparam("  \t luhbs \niysg\bedkc   \vci;du\rcvb ", ok_ptr);
	subtestnoparam((char *)ptr, ok_ptr);
} */

int	main(void)
{
	printyellow("////////////////////////////////////////////////////////////////////////////////\n\\\\                                  PrinTest                                  \\\\\n////////////////////////////////////////////////////////////////////////////////\n");
	printblue("\n     \\\\\\\\\\");
	fill_blank("Welcome to my own printf tester", 60, printblue);
	printblue("/////     \n");
	printblue("\n     /////");
	fill_blank("Beware : \"OK\" statement just checks the return values", 60, printblue);
	printblue("\\\\\\\\\\     \n");
	printblue("\n     \\\\\\\\\\");
	fill_blank("!!! You should of course use your own tester !!!", 60, printblue);
	printblue("/////     \n\n");
	title_message("%c : Character");
	testc();
	sep();
	title_message("%s : String");
	tests();
	sep();
	title_message("%p : Address");
	testp();
	sep();
	title_message("%d : Decimals");
	testd();
	sep();
	title_message("%i : Integers");
	testi();
	sep();
	title_message("%X : HEXADECIMALS");
	testX();
	sep();
	title_message("%x : hexadecimals");
	testx();
	sep();
	title_message("%u : Unsigned");
	testu();
	sep();
	title_message("WHERE THE FUCK COULD BE THE PROBLEM ???");
	//testothers();
	sep();
	if (global_ok)
		printgreen("Hip Hip Hip Hourra !");
	else
		printred("See you next time...");
}
