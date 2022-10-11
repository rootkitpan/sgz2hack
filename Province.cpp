#include <iostream>
#include <iomanip>
#include "Province.h"

using namespace std;

Province::Province()
{
	this->provinces = new PROVINCE[Province::PROVINCE_COUNT];
	for (int i = 0; i < Province::PROVINCE_COUNT; i++) {
		this->provinces[i].no = i + 1;
	}
}

Province::~Province()
{
	delete this->provinces;
}

PROVINCE& Province::operator[](int i)
{
	if (i >= Province::PROVINCE_COUNT) {
		return this->provinces[0];
	}

	return this->provinces[i];
}

wostream& operator<<(wostream& os, Province& g)
{
	int strlen = 0;

	for (int i = 0; i < Province::PROVINCE_COUNT; i++) {
		os << right << "[" << setw(2) << setfill(L'0') << g[i].no << "]";
		os << setfill(L' ');

		os << left << g[i].name1_display << ' ';

		os << endl;
	}

	return os;
}

