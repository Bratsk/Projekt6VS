#pragma once


#include "Cycle.h"
/**
*/
class MetropolisHastings
{
	public:
		MetropolisHastings(PointSet const* set, double delta_beta);

		~MetropolisHastings(void);

		/* reorder edges between vertices*/
		Cycle * newCycle(void);

		void process(void);

	protected:
		PointSet const * set;
		double beta;
		double delta_beta;
		Cycle * cycle_prim;
		Cycle * cycle_bis;
};