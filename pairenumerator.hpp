#ifndef _PAIRENUMERATOR_
#define _PAIRENUMERATOR_

#include "library/seqinfileenumerator.hpp"
#include "pointsummation.hpp"
#include "pair.hpp"

class PairEnumerator : public Enumerator<Pair>
{
protected:
	SeqInFileEnumerator<Pair> *_x;
	SeqInFileEnumerator<Pair> *_y;
	Pair _current;
	bool _end;
public:
	PairEnumerator(const std::string& str1, const std::string& str2)
	{
		_x = new SeqInFileEnumerator<Pair>(str1);
		_y = new SeqInFileEnumerator<Pair>(str2);
	}
	~PairEnumerator()
	{
		delete _x;
		delete _y;
	}
	void first()
	{
		_x->first();
		_y->first();
		next();
	}
	void next()
	{
		if( (_end = _x->end())) return;

		_current = _x->current();

		PointSummation ps(_current);
		ps.addEnumerator(_y);
		ps.run();

		if(ps.result() > 40 && _current.jegy > 1 && _current.jegy < 5)
		{
			_current.jegy++;	
		}
		_x->next();
	}
	bool end() const {return _end;}
	Pair current() const {return _current;}
};

#endif