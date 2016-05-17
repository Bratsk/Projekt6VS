#include "Main.h"

int main()
{
	std::cout << "Choose an action:" << std::endl;
	unsigned option;
	PointSet * pointset = new PointSet(100);
	pointset->readVerticesFromFile();
	pointset->calculateDistances();
	do
	{
		std::cout
			<< "1	: Print starting cycle\n"
			<< "2	: Metropolis-Hastings Algorithm\n"
			//<< "3	: \n"
			//<< "4	: \n"
			//<< "5	: \n"
			//<< "6	: \n"
			<< "0	: end program\n" << std::endl;
		std::cin >> option;
		std::cout << std::endl;
		switch (option)
		{
		case 1:;
		{
			Cycle * c = new Cycle(pointset);
			Cycle * c1 = nullptr;
			for(int i = 0; i < 1; i++)
			{
				c1 = c->swapEdges(pointset);
				std::cout << "cycle length: " << *c1;
				delete c;
				c = c1;
			}
			delete c1;
			break;
		}

		case 2:;
		{
			MetropolisHastings * metropolis_hastings 
				= new MetropolisHastings(pointset, 0.001);
			auto begin = std::chrono::high_resolution_clock::now();
			metropolis_hastings->process();
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
			std::cout << duration << " seconds total" << std::endl;
			delete metropolis_hastings;
			break;
		}
		case 3:;
		{

			break;
		}
		case 4:;
		{
			
			break;
		}
		case 5:;
		{

			break;
		}
		case 6:;
		{
			break;
		}
		default: option = 0; break;
		}
		std::cout << std::endl;
	} while (option);
	delete pointset;
	return 0;

}