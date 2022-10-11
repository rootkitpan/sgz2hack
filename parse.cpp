#include <iostream>
#include "parse.h"
#include "code_tbl.h"


using namespace std;

Parse::Parse(unsigned char* buf, int size)
{
	rom = (unsigned char*)new char[this->ROM_SIZE];
	if (rom == NULL) {
		cout << "allocate buffer for rom failed" << endl;
	}
	memcpy(rom, buf, size);

	setlocale(LC_ALL, "");
}

Parse::~Parse()
{
	delete rom;
}

void Parse::PerformParse()
{
	parse_5C250_5CEB0();
	parse_5CEB0_5E350();
	// parse_5E350_60000(); all 0

	//parse_sentense(0x6397F, 0x63CB7);
	//parse_63CB8_64000(); all 0
	parse_64000_67460();

	parse_6DADE_6DB40();
	parse_6DB40_6E380();
	parse_6E380_6E7A0();
	//parse_6E7A0_70000(); all 0

	parse_84000_87C00();
	//parse_87C00_88000(); all 0
	parse_88000_8BC00();
	//parse_8BC00_8C000(); all 0
	parse_8C000_8FC00();
	//parse_8FC00_90000(); all 0
	parse_90000_93C00();
	//parse_93C00_94000(); all 0
	parse_94000_97C00();
	//parse_97C00_98000(); all 0
	parse_98000_99400();
	//parse_99400_9A000(); all 0

	//wcout << general;
	//portrait[255]->Show();
	//wcout << province;
	//chardot[0]->Show();
	chardot[418]->Show();

}

void Parse::parse_5C250_5CEB0()
{
	int start = 0x5C250;
	int offset = 0;

	for (int i = 0; i < General::GENERAL_COUNT; i++) {
		offset = start + i * 9;
		general[i].duty = rom[offset];
		general[i].virtue = rom[offset + 1];
		general[i].ambition = rom[offset + 2];
		general[i].affinity = rom[offset + 3];
		general[i].family_code = *(unsigned short*) & rom[offset + 4];
		general[i].birth_year = rom[offset + 6];
		general[i].portrait = rom[offset + 7];
	}
}

void Parse::parse_5CEB0_5E350()
{
	int start = 0x5CEB0;
	int offset1 = 0;
	int offset2 = 0;

	for (int i = 0; i < General::GENERAL_COUNT; i++) {
		offset1 = start + i * 15;
		memcpy( general[i].name1, &rom[offset1], 7);

		offset2 = offset1 + 7;
		memcpy(general[i].name2, &rom[offset2], 8);

		CodeTbl::ConvertGeneralName1(
			general[i].name1,
			general[i].name1_display);

		CodeTbl::ConvertGeneralName2(
			general[i].name2,
			general[i].name2_display);
	}
}

void Parse::parse_64000_67460()
{
	int start = 0x64000;
	int offset = 0;

	for (int i = 0; i < 419; i++) {
		offset = start + i * 32;
		chardot[i] = new CharDot(&rom[offset]);
	}
}

void Parse::parse_6DADE_6DB40()
{
	int start = 0x6DADE;
	int offset1 = 0;
	int offset2 = 0;

	for (int i = 0; i < Province::PROVINCE_COUNT; i++) {
		offset1 = start + i * 7;
		memcpy(province[i].name1, &rom[offset1], 3);

		offset2 = offset1 + 3;
		memcpy(province[i].name2, &rom[offset2], 4);

		CodeTbl::ConvertProvinceName1(
			province[i].name1,
			province[i].name1_display);

		CodeTbl::ConvertProvinceName2(
			province[i].name2,
			province[i].name2_display);
	}
}

void Parse::parse_6DB40_6E380()
{
	int start = 0x6DB40;
	int offset = 0;

	for (int i = 0; i < General::GENERAL_COUNT; i++) {
		offset = start + i * 6;
		general[i].loyalty[0] = rom[offset];
		general[i].loyalty[1] = rom[offset + 1];
		general[i].loyalty[2] = rom[offset + 2];
		general[i].loyalty[3] = rom[offset + 3];
		general[i].loyalty[4] = rom[offset + 4];
		general[i].loyalty[5] = rom[offset + 5];
	}
}

void Parse::parse_6E380_6E7A0()
{
	int start = 0x6E380;
	int offset = 0;

	for (int i = 0; i < General::GENERAL_COUNT; i++) {
		offset = start + i * 3;
		general[i].intelligence = rom[offset];
		general[i].war = rom[offset + 1];
		general[i].charm = rom[offset + 2];	
	}
}

void Parse::parse_84000_87C00()
{
	int start = 0x84000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i] = new Portrait(&rom[offset]);
	}
}

void Parse::parse_88000_8BC00()
{
	int start = 0x88000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i+48] = new Portrait(&rom[offset]);
	}
}

void Parse::parse_8C000_8FC00()
{
	int start = 0x8C000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i + 96] = new Portrait(&rom[offset]);
	}
}

void Parse::parse_90000_93C00()
{
	int start = 0x90000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i + 48 * 3] = new Portrait(&rom[offset]);
	}
}

void Parse::parse_94000_97C00()
{
	int start = 0x94000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i + 48 * 4] = new Portrait(&rom[offset]);
	}
}

void Parse::parse_98000_99400()
{
	int start = 0x98000;
	int offset = 0;

	for (int i = 0; i < 16; i++) {
		offset = start + i * 320;
		portrait[i + 48 * 5] = new Portrait(&rom[offset]);
	}
}


void Parse::parse_sentense(int start, int end)
{
	unsigned char data;
	wchar_t c;


	for (int i = start; i < end; i++) {
		data = rom[i];
		if (data == 0) {
			wcout << endl;
		}
		else {
			c = CodeTbl::Convert2Shiftjis(data);
			wcout << c;
		}
	}

}


