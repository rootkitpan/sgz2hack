#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <iostream>

using namespace std;

typedef struct _GENERAL {
	unsigned short no;

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

