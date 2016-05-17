#include "MetropolisHastings.h"
#include <random>
#include <iomanip>


MetropolisHastings::MetropolisHastings(PointSet const* set, double delta_beta) :
	set(set), 
	beta(0), 
	delta_beta(delta_beta),
	cycle_prim(new Cycle(set)),
	cycle_bis(nullptr)
{
}

MetropolisHastings::~MetropolisHastings()
{
	delete cycle_prim;
}

Cycle * MetropolisHastings::newCycle(void)
{
	return cycle_prim->swapEdges(set);
}

void MetropolisHastings::process(void)
{
	//set up random number generator
	std::random_device rand_dev;
	std::default_random_engine  generator(rand_dev());
	std::uniform_real_distribution<double> distribution(0.0, 1.0);

	int no_new_cycle_found_control = 0;
	//while there is any change after n times
	while(no_new_cycle_found_control < 1000)
	{
		//std::cout << "beta : " << beta << std::endl;
		//for - how many times we use 2-opt
		for(int i = 0; i < set->getSize(); i++)
		{
			//generate new cycle
			cycle_bis = newCycle();
			bool accept_cycle;
			//calculate difference between the length of the two cycles
			double delta_length = cycle_bis->getLength() - cycle_prim->getLength();
			//if new length is smaller than accept
			if(delta_length < 0)
				accept_cycle = true;
			else
			{
				//calculate probability
				double probability = exp(- beta * delta_length);
				//generate random number
				double random = distribution(generator);
				//if smaller than the given probability then accept longer length
				//probability goes to zerof
				accept_cycle = random < probability ? true : false;
			}
			if(accept_cycle)
			{
				delete cycle_prim; //delete od cycle
				cycle_prim = cycle_bis; //copy new cycle
				cycle_bis = nullptr;
				no_new_cycle_found_control = 0; //set control to zero
				
			}
			else //reject
			{
				delete cycle_bis;
				cycle_bis = nullptr;
				no_new_cycle_found_control++;
			}
			//std::cout << "current length : " << cycle_prim->getLength() << std::endl;
		}
		beta += delta_beta;
		std::cout 
			<< "no new cycle found : " 
			<< std::setw(6) << no_new_cycle_found_control
			<< "   current length : " 
			<< std::setw(5) << cycle_prim->getLength() 
			<< std::endl;
	}
	std::cout << "\n" << "beta:" << beta << "\n" 
		<< "the shortest path is :\n"
		<< *cycle_prim << std::endl;
}
