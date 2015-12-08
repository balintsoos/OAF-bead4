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
	ofstream z("out.txt");
	
	Copying copy(&z);
	
	PairEnumerator pe("in1.txt", "in2.txt");
	
	copy.addEnumerator(&pe);
	copy.run();

	return 0;
}