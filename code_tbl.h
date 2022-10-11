#ifndef _CODE_TBL_H_
#define _CODE_TBL_H_


// https://uic.jp/charset/show/shiftjis2004

typedef struct _CODE_ITEM2 {
	unsigned char code1;
	unsigned char code2;
	wchar_t word;
	unsigned int counter;
} CODE_ITEM2;


typedef struct _CODE_ITEM1 {
	unsigned char code1;
	wchar_t word;
	unsigned int counter;
} CODE_ITEM1;


class CodeTbl {
private:
	static wchar_t Convert2Shiftjis(unsigned char code1, unsigned char code2);

public:
	static wchar_t Convert2Shiftjis(unsigned char code1);
	static void ConvertGeneralName1(unsigned char* name1, wchar_t* name1_disp);
	static void ConvertGeneralName2(unsigned char* name1, wchar_t* name1_disp);

	static void ConvertProvinceName1(unsigned char* name1, wchar_t* name1_disp);
	static void ConvertProvinceName2(unsigned char* name1, wchar_t* name1_disp);
};


#endif /* _CODE_TBL_H_ */

