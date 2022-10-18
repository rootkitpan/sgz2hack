#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <iostream>

using namespace std;

typedef struct _GENERAL {

	unsigned char name1[7];			/* 文字 */
	wchar_t name1_display[4];		/* 文字 */

	unsigned char name2[8];			/* 平假名 */
	wchar_t name2_display[8];		/* 平假名 */

	unsigned char intelligence;
	unsigned char war;
	unsigned char charm;

	unsigned char duty;			/*  TODO */
	unsigned char virtue;		/*  TODO */
	unsigned char ambition;		/*  TODO */
	unsigned char affinity;
	unsigned short family_code;
	unsigned char birth_year;
	unsigned char portrait;		/* auto-join */

	unsigned char loyalty[6];	/* init loyalty */

	unsigned char appear_year;
	unsigned char auto_join;
	unsigned char appear_city[6];
	unsigned short no;
	unsigned short next[6];
	unsigned char lord_flag[6];
	unsigned char advisor_flag[6];
	unsigned char hide_flag[6];
	unsigned char governor_flag[6];
	unsigned char last_flag[6];
	unsigned char first_flag[6];
	unsigned char end_flag[6];



}GENERAL, *PGENERAL;

class General {
private:
	GENERAL* generals;
public:
	static const int GENERAL_COUNT = 352;
	General();
	~General();

	GENERAL& operator[](int i);
	//friend ostream& operator<<(ostream& os, const GENERAL& g);
	friend wostream& operator<<(wostream& os, General& g);
};

#endif /* _GENERAL_H_ */

