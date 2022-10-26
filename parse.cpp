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

	for (int i = 0; i < Portrait::POITRAIT_COUNT; i++) {
		portrait[i] = new Portrait();

		char file_name[260];
		sprintf_s(file_name, "potrait%03d", i);
		portrait[i]->setFileName(file_name);
	}
}

Parse::~Parse()
{
	delete rom;

	for (int i = 0; i < Portrait::POITRAIT_COUNT; i++) {
		delete portrait[i];
	}
}

void Parse::PerformParse()
{
	parse_598CD_5990D();

	parse_5C250_5CEB0();
	parse_5CEB0_5E350();
	// parse_5E350_60000(); all 0

	//parse_sentense(0x6397F, 0x63CB7);
	//parse_63CB8_64000(); all 0
	parse_64000_67460();
	//parse_67460_68000(); all 0

	parse_6C000_6C078();

	parse_6DADE_6DB40();
	parse_6DB40_6E380();
	parse_6E380_6E7A0();
	//parse_6E7A0_70000(); all 0

	parse_7445B_74573();

	parse_7981B_7B65B();

	parse_7B693_7B789();

	parse_7B7D9_7B7DF();
	parse_7B7DF_7B84B();

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
	parse_9A000_9B400();
	//parse_9B400_9C000();
	parse_9C000_9C420();
	parse_9C420_9C520();



	//wcout << general;
	//portrait[255]->Show();
	//wcout << province;
	for (int i = 160; i < 170; i++) {
		//chardot[i]->Show();
	}
	//chardot[0]->Show();
	//chardot[418]->Show();
	//wcout << scenario;
	//wcout << city;
	//portrait[0]->Show();
#if 0
	unsigned short v = pg[7].p[6].pc[1].v;
	unsigned short r = pg[7].p[6].pc[1].r;
	unsigned short g = pg[7].p[6].pc[1].g;
	unsigned short b = pg[7].p[6].pc[1].b;
	unsigned short rsvd = pg[7].p[6].pc[1].rsvd;
#endif

	

	//portrait[0]->show();
	//portrait[0]->toBMP();
	portrait[1]->toBMP();
	for (int i = 0; i < Portrait::POITRAIT_COUNT; i++) {
		portrait[i]->toBMP();
	}

	//map.toBMP();




}

void Parse::parse_598CD_5990D()
{
	int start = 0x598CD;

	memcpy(&pg[7], &rom[start], sizeof(PALETTE_GROUP));

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

void Parse::parse_6C000_6C078()
{
	int start = 0x6C000;
	int offset = 0;

	for (int i = 0; i < 6; i++) {
		offset = start + i * 20;
		scenario[i].start_year = (rom[offset + 1] << 8) + rom[offset];
		scenario[i].start_month = rom[offset + 2];
		scenario[i].country_count = rom[offset + 3];
		for (int j = 0; j < 16; j++) {
			scenario[i].unknown[j] = rom[offset + 4 + j] >> 4;
			scenario[i].flag[j] = rom[offset + 4 + j] & 0xF;
		}
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

void Parse::parse_7445B_74573()
{
	int start = 0x7445B;
	
	map.setTileIndex(&rom[start]);
}

void Parse::parse_7981B_7B65B()
{
	int start = 0x7981B;
	int offset = 0;

	for (int i = 0; i < General::GENERAL_COUNT; i++) {
		offset = start + i * 22;
		general[i].appear_year = rom[offset];
		general[i].auto_join = rom[offset + 1];
		for (int j = 0; j < Scenario::SCENARIO_COUNT; j++) {
			general[i].appear_city[j] = rom[offset + 2 + j];
		}
		general[i].no = rom[offset + 8] + rom[offset + 9] * 256;
		for (int j = 0; j < Scenario::SCENARIO_COUNT; j++) {
			unsigned char next = rom[offset + 10 + j * 2];
			unsigned char flag = rom[offset + 11 + j * 2];

			general[i].next[j] = next + (flag & 0x01) * 256;
			general[i].lord_flag[j] = (flag >> 7) & 0x01;
			general[i].advisor_flag[j] = (flag >> 6) & 0x01;
			general[i].hide_flag[j] = (flag >> 5) & 0x01;
			general[i].governor_flag[j] = (flag >> 4) & 0x01;
			general[i].last_flag[j] = (flag >> 3) & 0x01;
			general[i].first_flag[j] = (flag >> 2) & 0x01;
			general[i].end_flag[j] = (flag >> 1) & 0x01;
		}
	}
}

void Parse::parse_7B693_7B789()
{
	int start = 0x7B693;
	int offset = 0;

	for (int i = 0; i < City::CITY_COUNT; i++) {
		offset = start + i * 6;
		city[i].left = rom[offset];
		city[i].bottom_left = rom[offset + 1];
		city[i].bottom_right = rom[offset + 2];
		city[i].top_left = rom[offset + 3];
		city[i].top_right = rom[offset + 4];
		city[i].right = rom[offset + 5];
	}
}

void Parse::parse_7B7D9_7B7DF()
{
	int start = 0x7B7D9;
	
	for (int i = 0; i < Scenario::SCENARIO_COUNT; i++) {
		scenario[i].max_player = rom[start + i];
	}
}

void Parse::parse_7B7DF_7B84B()
{
	int start = 0x7B7DF;
	int end = 0x7B84B;
	int s = 0;
	int j = 0;
	int new_scenario = 0;

	for (int i = start; i < end; i += 2) {
		if ((rom[i] == 0xFE) && (rom[i + 1] == 0xFF)) {
			scenario[s].lord[j] = 0xFFFE;
			s++;
			j = 0;
		}
		else {
			scenario[s].lord[j] = rom[i + 1] * 256 + rom[i];
			j++;
		}
	}
}

void Parse::parse_84000_87C00()
{
	int start = 0x84000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i]->setData(&rom[offset]);
	}
}

void Parse::parse_88000_8BC00()
{
	int start = 0x88000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i+48]->setData(&rom[offset]);
	}
}

void Parse::parse_8C000_8FC00()
{
	int start = 0x8C000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i + 96]->setData(&rom[offset]);
	}
}

void Parse::parse_90000_93C00()
{
	int start = 0x90000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i + 48 * 3]->setData(&rom[offset]);
	}
}

void Parse::parse_94000_97C00()
{
	int start = 0x94000;
	int offset = 0;

	for (int i = 0; i < 48; i++) {
		offset = start + i * 320;
		portrait[i + 48 * 4]->setData(&rom[offset]);
	}
}

void Parse::parse_98000_99400()
{
	int start = 0x98000;
	int offset = 0;

	for (int i = 0; i < 16; i++) {
		offset = start + i * 320;
		portrait[i + 48 * 5]->setData(&rom[offset]);
	}
}

void Parse::parse_9A000_9B400()
{
	int start = 0x9A000;
	int offset = 0;
	int palette_index = 0;

	for (int i = 0; i < Portrait::POITRAIT_COUNT; i++) {
		for (int j = 0; j < 20; j++) {
			offset = start + i * 20 + j;
			palette_index = rom[offset];
			portrait[i]->setPalette(j, &pg[7].p[palette_index]);
		}
	}
}

void Parse::parse_9C000_9C420()
{
	int start = 0x9C000;

	map.setBaseTile(&rom[start]);
}

void Parse::parse_9C420_9C520()
{
	int start = 0x9C420;
	int offset = 0;

	for (int i = 0; i < SmallFlag::SMALL_FLAG_COUNT; i++) {
		offset = start + i * 16;
		sflag[i].setData(&rom[offset]);
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


