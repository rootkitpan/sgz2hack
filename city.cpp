#include <iostream>
#include <iomanip>
#include "city.h"

using namespace std;

City::City()
{
	this->cities = new CITY[City::CITY_COUNT];
	for (int i = 0; i < City::CITY_COUNT; i++) {
		this->cities[i].no = i;
	}
}

City::~City()
{
	delete this->cities;
}

CITY& City::operator[](int i)
{
	if (i >= City::CITY_COUNT) {
		return this->cities[0];
	}

	return this->cities[i];
}

wostream& operator<<(wostream& os, City& g)
{
	int strlen = 0;

	for (int i = 0; i < City::CITY_COUNT; i++) {
		os << right << "[" << setw(2) << setfill(L'0') << g[i].no << "]";
		
		os << setw(3) << g[i].left << " ";
		os << setw(3) << g[i].bottom_left << " ";
		os << setw(3) << g[i].bottom_right << " ";
		os << setw(3) << g[i].top_left << " ";
		os << setw(3) << g[i].top_right << " ";
		os << setw(3) << g[i].right << " ";

		os << endl;
	}

	return os;
}

