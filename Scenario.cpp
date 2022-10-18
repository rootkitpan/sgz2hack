#include <iostream>
#include <iomanip>
#include "Scenario.h"

using namespace std;

Scenario::Scenario()
{
	this->scenarios = new SCENARIO[Scenario::SCENARIO_COUNT];
}

Scenario::~Scenario()
{
	delete this->scenarios;
}

SCENARIO& Scenario::operator[](int i)
{
	if (i >= Scenario::SCENARIO_COUNT) {
		return this->scenarios[0];
	}

	return this->scenarios[i];
}

wostream& operator<<(wostream& os, Scenario& g)
{
	int strlen = 0;

	for (int i = 0; i < Scenario::SCENARIO_COUNT; i++) {
#if 0
		strlen = (int)wcslen(g[i].name1_display);
		os << setw(6 - strlen);
		os << left << g[i].name1_display << ' ';
#endif

		os << setw(3) << g[i].start_year << " ";
		os << setw(3) << g[i].start_month << " ";
		os << setw(3) << g[i].country_count << " ";

		for (int j = 0; j < 1; j++) {
			os << "[";
			os << setw(2) << g[i].unknown[j] << " ";
			os << setw(2) << g[i].flag[j] << " ";
			os << "]";
		}

		os << setw(3) << g[i].max_player << " ";

		for (int j = 0; j < g[i].max_player + 1; j++) {
			if (g[i].lord[j] != 0xFFFE) {
				os << setw(6) << g[i].lord[j] << " ";
			}
		}

		os << endl;
	}

	return os;
}
