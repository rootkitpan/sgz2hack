#include <iostream>
#include <iomanip>
#include <fstream>

#include <Windows.h>
#include "sgz2image.h"

using namespace std;

void Tile::Convert2Tile(unsigned char* buf)
{
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			unsigned char byte1 = buf[2 * y];
			unsigned char byte2 = buf[2 * y + 1];
			unsigned char v1 = GetBitFront(byte1, x);
			unsigned char v2 = GetBitFront(byte2, x);
			data[x][y] = v1 + v2 * 2;
		}
	}
}


unsigned char Tile::GetBitFront(unsigned char data, int i)
{
	int j = 7 - i;
	int k = 1 << j;
	unsigned char ret;

	ret = (unsigned char)(data & k);

	return (ret? 1 : 0);
}

unsigned char Tile::GetData(int i, int j)
{
	return data[i][j];
}


SGZ2Image::SGZ2Image(unsigned char* buf, int width, int height)
{
	int offset = 0;
	int index = 0;

	this->width = width;
	this->height = height;

	tiles = new Tile[width * height];

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			index = y * width + x;
			offset = index * 16;
			tiles[index].Convert2Tile(&buf[offset]);
		}
	}

	int data_width = width * 8;
	int data_height = height * 8;
	int data_offset = 0;
	int tile_x = 0;
	int tile_y = 0;
	int tile_offset = 0;
	int tile_inner_x = 0;
	int tile_inner_y = 0;
	data = new unsigned char[data_width * data_height];
	for (int data_y = 0; data_y < data_height; data_y++) {
		for (int data_x = 0; data_x < data_width; data_x++) {

			tile_x = data_x / 8;
			tile_y = data_y / 8;
			tile_offset = tile_y * width + tile_x;

			tile_inner_x = data_x % 8;
			tile_inner_y = data_y % 8;
			unsigned char value = tiles[tile_offset].GetData(tile_inner_x, tile_inner_y);

			data_offset = data_y * data_width + data_x;
			data[data_offset] = value;
		}
	}

	palette_index = new unsigned char[width * height];
	cdata = new unsigned short[data_width * data_height];
}


SGZ2Image::~SGZ2Image()
{
	delete tiles;
	delete data;
}


void SGZ2Image::Show() const
{
	int data_width = width * 8;
	int data_height = height * 8;
	int data_offset = 0;
	unsigned char val = 0;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr = 0;

	for (int data_y = 0; data_y < data_height; data_y++) {
		for (int data_x = 0; data_x < data_width; data_x++) {
			data_offset = data_y * data_width + data_x;
			val = data[data_offset];
			if (val == 0x00) {
				attr = BACKGROUND_BLUE;
			}
			else if (val == 0x01) {
				attr = BACKGROUND_GREEN;
			}
			else if (val == 0x02) {
				attr = BACKGROUND_RED;
			}
			else if (val == 0x03) {
				attr = BACKGROUND_INTENSITY;
			}
			else {
				attr = BACKGROUND_INTENSITY;
			}
			SetConsoleTextAttribute(handle, attr);

			cout << setw(2) << setfill('0') << hex << (int)val;
		}
		cout << endl;
	}

	SetConsoleTextAttribute(handle, 0);
}

unsigned short SGZ2Image::SwapBGR2RGB(unsigned short bgr)
{
	unsigned short rgb = 0;
	unsigned short v1 = (bgr & 0x7C00) >> 10;
	unsigned short v2 = (bgr & 0x03E0) >> 5;
	unsigned short v3 = bgr & 0x001F;

	rgb = (v1) | (v2 << 5) | (v3 << 10);

	return rgb;
}

void SGZ2Image::SetFileName(char* fn)
{
	memcpy(file_name, fn, strlen(fn) + 1);
}


void SGZ2Image::ToBMP() const
{
	BITMAPFILEHEADER header;

	/* 0x00 */
	header.bfType = 'MB';
	/* 0x02 */
	header.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + 32 * 40 * 2;		// 
	/* 0x06 */
	header.bfReserved1 = 0;
	/* 0x08 */
	header.bfReserved2 = 0;
	/* 0x0A */
	header.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);



	BITMAPINFOHEADER info;
	/* 0x0E */
	info.biSize = sizeof(BITMAPINFOHEADER);
	/* 0x12 */
	info.biWidth = width * 8;
	/* 0x16 */
	info.biHeight = -height * 8;
	/* 0x1A */
	info.biPlanes = 1;
	/* 0x1C */
	info.biBitCount = 16;
	/* 0x1E */
	info.biCompression = BI_RGB;
	/* 0x22 */
	info.biSizeImage = 0;
	/* 0x26 */
	info.biXPelsPerMeter = 0;
	/* 0x2A */
	info.biYPelsPerMeter = 0;
	/* 0x2D */
	info.biClrUsed = 0;
	/* 0x32 */
	info.biClrImportant = 0;

	// no palette for 16 colordeep

	// data
	/* 0x36 */
	for (int i = 0; i < 32 * 40; i++) {
		int x = i % (width * 8);
		int y = i / (width * 8);
		int tile_x = x / 8;
		int tile_y = y / 8;
		int tile_index = tile_y * width + tile_x;
		int pi = palette_index[tile_index];
		PALETTE p = palette_group->p[pi];
		unsigned short v = p.pc[data[i]].v;
		cdata[i] = v;

		cdata[i] = SGZ2Image::SwapBGR2RGB(cdata[i]);

	}

	char FileName[MAX_PATH];
	sprintf_s(FileName, "C:\\work\\sgz2\\src\\pic\\%s.bmp", file_name);
	ofstream of;
	of.open(FileName, ios::out | ios::binary);
	if (of.fail()) {
		cout << "errno = " << errno << endl;
		return;
	}
	of.write((char*)&header, sizeof(BITMAPFILEHEADER));
	of.write((char*)&info, sizeof(BITMAPINFOHEADER));
	of.write((char*)cdata, 32 * 40 * 2);
	of.close();


}

void SGZ2Image::SetPaletteGroup(PPALETTE_GROUP p)
{
	palette_group = p;
}

void SGZ2Image::SetPaletteIndex(unsigned char* p)
{
	memcpy(palette_index, p, height * width);
}

Portrait::Portrait(unsigned char* buf)
	: SGZ2Image(buf, 4, 5)
{
}

/*******************************************************************/


void Tile1bit::Convert2Tile(unsigned char* buf)
{
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			unsigned char byte = buf[y];
			data[x][y] = GetBitFront(byte, x);
		}
	}
}


unsigned char Tile1bit::GetBitFront(unsigned char data, int i)
{
	int j = 7 - i;
	int k = 1 << j;
	unsigned char ret;

	ret = (unsigned char)(data & k);

	return (ret ? 1 : 0);
}

unsigned char Tile1bit::GetData(int i, int j)
{
	return data[i][j];
}


SGZ2Image1bit::SGZ2Image1bit(unsigned char* buf, int width, int height)
{
	int offset = 0;
	int index = 0;

	this->width = width;
	this->height = height;

	tiles = new Tile1bit[width * height];

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			index = y * width + x;
			offset = index * 8;
			tiles[index].Convert2Tile(&buf[offset]);
		}
	}

	int data_width = width * 8;
	int data_height = height * 8;
	int data_offset = 0;
	int tile_x = 0;
	int tile_y = 0;
	int tile_offset = 0;
	int tile_inner_x = 0;
	int tile_inner_y = 0;
	data = new unsigned char[data_width * data_height];
	for (int data_y = 0; data_y < data_height; data_y++) {
		for (int data_x = 0; data_x < data_width; data_x++) {

			tile_x = data_x / 8;
			tile_y = data_y / 8;
			tile_offset = tile_y * width + tile_x;

			tile_inner_x = data_x % 8;
			tile_inner_y = data_y % 8;
			unsigned char value = tiles[tile_offset].GetData(tile_inner_x, tile_inner_y);

			data_offset = data_y * data_width + data_x;
			data[data_offset] = value;
		}
	}


}


SGZ2Image1bit::~SGZ2Image1bit()
{
	delete tiles;
	delete data;
}


void SGZ2Image1bit::Show() const
{
	int data_width = width * 8;
	int data_height = height * 8;
	int data_offset = 0;
	unsigned char val = 0;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr = 0;

	for (int data_y = 0; data_y < data_height; data_y++) {
		for (int data_x = 0; data_x < data_width; data_x++) {
			data_offset = data_y * data_width + data_x;
			val = data[data_offset];
			if (val == 0x00) {
				attr = BACKGROUND_BLUE;
			}
			else if (val == 0x01) {
				attr = BACKGROUND_GREEN;
			}
			else if (val == 0x02) {
				attr = BACKGROUND_RED;
			}
			else if (val == 0x03) {
				attr = BACKGROUND_INTENSITY;
			}
			else {
				attr = BACKGROUND_INTENSITY;
			}
			SetConsoleTextAttribute(handle, attr);

			cout << setw(2) << setfill('0') << hex << (int)val;
		}
		cout << endl;
	}

	SetConsoleTextAttribute(handle, 0);
}


CharDot::CharDot(unsigned char* buf)
	: SGZ2Image1bit(buf, 2, 2)
{

}




