#ifndef _CITY_H_
#define _CITY_H_

#include <iostream>

using namespace std;

typedef struct _CITY {
	unsigned short no;

	/* city arround */
	unsigned char left;
	unsigned char bottom_left;
	unsigned char bottom_right;
	unsigned char top_left;
	unsigned char top_right;
	unsigned char right;


} CITY, *PCITY;


class City {
private:
	PCITY cities;
public:
	static const int CITY_COUNT = 41;
	City();
	~City();

	CITY& operator[](int i);
	friend wostream& operator<<(wostream& os, City& g);
};



#endif /* _CITY_H_ */

