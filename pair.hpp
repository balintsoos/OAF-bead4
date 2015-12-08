#ifndef _PAIR_
#define _PAIR_

struct Pair
{
	std::string neptun;
	int jegy;

	friend std::ifstream& operator>>(std::ifstream&, Pair&);
	friend std::ofstream& operator<<(std::ofstream&, const Pair&);
};

std::ifstream& operator>>(std::ifstream& f, Pair& df)
{
	f >> df.neptun >> df.jegy;
	return f;
}

std::ofstream& operator<<(std::ofstream& f, const Pair& df)
{
	f << df.neptun << " " << df.jegy;
	return f;
}

#endif