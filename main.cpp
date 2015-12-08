//
// main.cpp
// OAF - 4. beadando - 7. feladat
//
// Soos Balint
// HDX9MU
//

#include <iostream>
#include "pairenumerator.hpp"
#include "copying.hpp"

using namespace std;

int main()
{
	ofstream z("z.txt");
	
	Copying copy(&z);
	
	PairEnumerator pe("input.txt", "input2.txt");
	
	copy.addEnumerator(&pe);
	copy.run();

	return 0;
}