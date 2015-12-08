#ifndef _COPYING_
#define _COPYING_

#include "library/summation.hpp"
#include "pair.hpp"

class Copying : public Summation<Pair, std::ofstream>
{
public:
	Copying(std::ofstream *u): Summation<Pair, std::ofstream>(u){}
protected:
	void add(const Pair& e)
	{
		*_result << e << std::endl;
	}
	
};

#endif