#include <iostream>
#include <getopt.h>

#define no_argument 0
#define required_argument 1
#define optional_argument 2


int main(int argc, char * argv[])
{

	const struct option longopts[] = 
	{
		{"version", no_argument, 0, 'v'},
		{"help", no_argument, 0, 'h'},
		{"list", no_argument, 0, 'l'},
		{"number", required_argument, 0, 'n'},
		{"option", optional_argument, 0, 'o'},
		{0, 0, 0, 0}
	};

	int index;
	int iarg = 0;

	opterr = 1;
	
	bool duplicates[] = {false, false, false, false, false};

	while(iarg != -1)
	{
		
		iarg = getopt_long(argc, argv, "vhln:o:", longopts, &index);

		switch (iarg)
		{
			case 'h':
				if (!duplicates[0])
				{
					std::cout << "Arg: Help" << std::endl;
					duplicates[0] = true;
				}
				break;

			case 'v':
				if (!duplicates[1])
				{
					std::cout << "Arg: Version" << std::endl;
					duplicates[1] = true;
				}
				break;

			case 'l':
				if (!duplicates[2])
				{
					std::cout << "Arg: List" << std::endl;
					duplicates[2] = true;
				}
				break;
			case 'n':
				if (!duplicates[3])
				{
					std::cout << "Arg: Number. Value: " << optarg << std::endl;
					duplicates[3] = true;
				}
				break;
			case 'o':
				if (!duplicates[4])
				{
					std::cout << "Arg: Option. Value: " << optarg << std::endl;
					duplicates[4] = true;
				}
				break;
		}
		
	}

	return 0;

}
