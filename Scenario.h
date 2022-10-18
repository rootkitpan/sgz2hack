#ifndef _SCENARIO_H_
#define _SCENARIO_H_

#include <iostream>

using namespace std;

typedef struct _SCENARIO {
	unsigned char name1[7];			/* ���� */
	wchar_t name1_display[4];		/* ���� */

	unsigned short start_year;
	unsigned char start_month;
	unsigned char country_count;
	unsigned char flag[16];
	unsigned char unknown[16];		/* TODO */

	unsigned char max_player;		/* ��༸����Ϸ */
	unsigned short lord[16];		/* ���籾������Щ���� */
}SCENARIO, * PSCENARIO;

class Scenario {
private:
	PSCENARIO scenarios;
public:
	static const int SCENARIO_COUNT = 6;
	Scenario();
	~Scenario();

	SCENARIO& operator[](int i);
	//friend ostream& operator<<(ostream& os, const GENERAL& g);
	friend wostream& operator<<(wostream& os, Scenario& g);
};


#endif /* _SCENARIO_H_ */
