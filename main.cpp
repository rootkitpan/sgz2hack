#include <iostream>
#include <fstream>
#include "parse.h"

using namespace std;

#define ROM_SIZE (1024 * 1024)
static unsigned char rom[ROM_SIZE];


static void get_rom_binary(void)
{
	ifstream infile;

	infile.open("C:\\work\\sgz2\\sgz2.gbc", ios::in | ios::binary);
	if (infile.fail()) {
		cout << "errno = " << errno << endl;
		return;
	}

	infile.read((char*)rom, ROM_SIZE);

	infile.close();

	//cout << hex << (int)rom[0x3CF] << endl;
}


int main(int argc, char* argv[])
{
	get_rom_binary();

	Parse *p = new Parse(rom, ROM_SIZE);
	p->PerformParse();
	delete p;

	return 0;
}



