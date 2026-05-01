#include "Harl.hpp"

int main(int argc, char **argv)
{
	(void)argc;

	Harl harl;
	if (argc > 1)
		harl.complain(argv[1]);
	else
		harl.complain("SOMETHING ELSE");
	return (0);
}
