#include <iostream>

void	print_uppercase(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		std::cout << *str;
		str++;
	}
}

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (++i < argc)
			print_uppercase(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}