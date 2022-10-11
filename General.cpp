#include <iostream>
#include <iomanip>
#include "General.h"

using namespace std;

General::General()
{
	this->generals = new GENERAL[this->GENERAL_COUNT];
	for (int i = 0; i < this->GENERAL_COUNT; i++) {
		this->generals[i].no = i + 1;
	}
}

General::~General()
{
	delete this->generals;
}

GENERAL& General::operator[](int i)
{
	if (i >= this->GENERAL_COUNT) {
		return this->generals[0];
	}

	return this->generals[i];
}

wostream& operator<<(wostream& os, General& g)
{
	int strlen = 0;

	for (int i = 0; i < General::GENERAL_COUNT; i++) {
		os << right << "[" << setw(3) << setfill(L'0') << g[i].no << "]";
		os << setfill(L' ');

		strlen = (int)wcslen(g[i].name1_display);
		os << setw(6-strlen);
		os << left << g[i].name1_display << ' ';

#if 0
		strlen = wcslen(g[i].name2_display);
		os << setw(14 - strlen);
		os << g[i].name2_display << ' ';
#endif

		os << setw(3) << g[i].intelligence << " ";
		os << setw(3) << g[i].war << " ";
		os << setw(3) << g[i].charm << " ";

		os << setw(3) << g[i].duty << " ";
		os << setw(3) << g[i].virtue << " ";
		os << setw(3) << g[i].ambition << " ";
		os << setw(3) << g[i].affinity << " ";
		os << setw(4) << hex << g[i].family_code << " " << dec;
		os << setw(3) << g[i].birth_year << " ";
		os << setw(3) << g[i].portrait << " ";

		for (int j = 0; j < 6; j++) {
			os << setw(3) << g[i].loyalty[j] << " ";
		}


		os << endl;
	}
	
	return os;
}
