#ifndef _POINTSUMMATION_
#define _POINTSUMMATION_

#include "library/summation.hpp"
#include "pair.hpp"

class PointSummation : public Summation<Pair, int>
{
public:
	PointSummation(const Pair& p):Summation<Pair, int>()
	{
		neptun = p.neptun;
	}
protected:
	std::string neptun;
	void first() {}
	void init()
	{
		*Summation<Pair, int>::_result = 0;
	}
	void add(const Pair& e)
	{
		*Summation<Pair, int>::_result += e.jegy;
	}
	bool whileCond(const Pair& current) const
	{
		return current.neptun == neptun;
	}
};

#endif