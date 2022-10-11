#ifndef _PARSE_H_
#define _PARSE_H_

#include "General.h"
#include "sgz2image.h"
#include "Province.h"

class Parse {
private:
	unsigned char* rom;
	static const int ROM_SIZE = 1024 * 1024;

	class General general;
	class Portrait* portrait[256];
	class Province province;
	class CharDot* chardot[419];

	void parse_5C250_5CEB0();
	void parse_5CEB0_5E350();
	void parse_64000_67460();
	void parse_6DADE_6DB40();
	void parse_6DB40_6E380();
	void parse_6E380_6E7A0();
	void parse_84000_87C00();
	void parse_88000_8BC00();
	void parse_8C000_8FC00();
	void parse_90000_93C00();
	void parse_94000_97C00();
	void parse_98000_99400();


	void parse_sentense(int start, int end);

public:
	Parse(unsigned char* buf, int size);
	~Parse();
	void PerformParse();
};


#endif /* _PARSE_H_ */