#include "globalHeader.h"

/*NAME :
 *ID:
 *
 * This project solves in several ways the problem of the minimum distances
 * from a single origin to a single destination in directed graphs,
 * according to several algorithms and also calculates the runtimes of the various solutions.*/

using namespace std;



int main(int argc, char* argv[])
{
	Engine e;

	if (argv[1] != nullptr && argv[2] != nullptr)
	{
		//e.run(argv[1], argv[2]);
        e.run(argv[1], argv[2]);
	}

	else
	{
		cout << "Invalid argument\n";
	}

	return 0;
}