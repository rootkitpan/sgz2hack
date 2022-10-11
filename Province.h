#ifndef _PROVINCE_H_
#define _PROVINCE_H_

#include <iostream>

using namespace std;

typedef struct _PROVINCE {
	unsigned short no;

	unsigned char name1[3];			/* 文字 */
	wchar_t name1_display[2];		/* 文字 */

	unsigned char name2[4];			/* 平假名 */
	wchar_t name2_display[4];		/* 平假名 */
} PROVINCE, *PPROVINCE;


class Province {
private:
	PPROVINCE provinces;
public:
	static const int PROVINCE_COUNT = 14;
	Province();
	~Province();

	PROVINCE& operator[](int i);
	friend wostream& operator<<(wostream& os, Province& g);
};



#endif /* _PROVINCE_H_ */

