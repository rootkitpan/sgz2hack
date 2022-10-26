#include <iostream>
#include <iomanip>
#include <fstream>

#include <Windows.h>
#include "sgz2image.h"

using namespace std;



Tile::Tile()
{
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			data[x][y] = 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		palette.pc[i].v = 0;
	}
}

void Tile::setData(unsigned char* buf)
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

unsigned char Tile::getData(int x, int y) const
{
	if (x > 7) {
		cout << "[Tile][error] getData x > 7" << endl;
	}
	if (y > 7) {
		cout << "[Tile][error] getData y > 7" << endl;
	}

	unsigned char v = 0;
	v = data[x][y];

	if (v > 0x03) {
		cout << "[Tile][error] getData > 0x03" << endl;
	}
	return v;
}

void Tile::setPalette(PPALETTE p)
{
	for (int i = 0; i < 4; i++) {
		palette.pc[i].v = p->pc[i].v;
	}
}

unsigned short Tile::getcData(int x, int y) const
{
	unsigned char data = getData(x, y);
	unsigned short cdata = 0;

	cdata = palette.pc[data].v;

	return cdata;
}

void Tile::show() const
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle == INVALID_HANDLE_VALUE) {
		cout << "[error] GetStdHandle" << endl;
		return;
	}

	CONSOLE_SCREEN_BUFFER_INFO info;
	if (GetConsoleScreenBufferInfo(handle, &info) == FALSE) {
		cout << "[error] GetConsoleScreenBufferInfo" << endl;
		return;
	}

	WORD old_attr = info.wAttributes;

	WORD attr = 0;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			unsigned char val = data[x][y];
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
				cout << "[Tile][error] value over 0x03" << endl;
			}
			SetConsoleTextAttribute(handle, attr);

			cout << setw(2) << setfill('0') << hex << (int)val;
		}
		cout << endl;
	}

	SetConsoleTextAttribute(handle, old_attr);
}








SGZ2Image::SGZ2Image(int width, int height)
{
	this->width = width;
	this->height = height;
	this->pixel_width = width * 8;
	this->pixel_height = height * 8;
	memset(file_name, 0, 260);

	tiles = new Tile[width * height];
}

SGZ2Image::~SGZ2Image()
{
	delete tiles;
}

void SGZ2Image::setData(int tile_index, unsigned char* d)
{
	tiles[tile_index].setData(d);
}

void SGZ2Image::setData(int tile_x, int tile_y, unsigned char* d)
{
	int tile_index = 0;

	tile_index = tile_y * width + tile_x;
	tiles[tile_index].setData(d);
}

void SGZ2Image::setData(unsigned char* d)
{
	int offset = 0;
	int tile_index = 0;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			tile_index = y * width + x;
			offset = tile_index * 16;
			tiles[tile_index].setData(&d[offset]);
		}
	}
}

int SGZ2Image::getTileIndex(int x, int y) const
{
	int tile_x = x / 8;
	int tile_y = y / 8;
	int tile_index = tile_y * width + tile_x;

	return tile_index;
}

unsigned char SGZ2Image::getData(int x, int y) const
{
	int tile_index = getTileIndex(x, y);
	int x_in_tile = x % 8;
	int y_in_tile = y % 8;

	unsigned char v;
	v = tiles[tile_index].getData(x_in_tile, y_in_tile);

	return v;
}

unsigned short SGZ2Image::getcData(int x, int y) const
{
	int tile_index = getTileIndex(x, y);
	int x_in_tile = x % 8;
	int y_in_tile = y % 8;

	unsigned short v;
	v = tiles[tile_index].getcData(x_in_tile, y_in_tile);

	return v;
}

void SGZ2Image::setFileName(const char* fn)
{
	memcpy(file_name, fn, strlen(fn) + 1);
}

void SGZ2Image::setPalette(int tile_index, PPALETTE p)
{
	tiles[tile_index].setPalette(p);
}

void SGZ2Image::show() const
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr = 0;

	for (int y = 0; y < pixel_height; y++) {
		for (int x = 0; x < pixel_width; x++) {
			unsigned char val = getData(x, y);
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
				cout << "[SGZ2Image][error] value over 0x03" << endl;
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

void SGZ2Image::toBMP() const
{
	BITMAPFILEHEADER header;

	/* 0x00 */
	header.bfType = 'MB';
	/* 0x02 */
	header.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + pixel_width * pixel_height * 2;
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
	info.biWidth = pixel_width;
	/* 0x16 */
	info.biHeight = -pixel_height;
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


	/* data + palette ==> cdata, used for bmp file */
	unsigned short* cdata;	/* cdata[pixel_width * pixel_height] <==> cdata[pixel_width][pixel_height] */
	cdata = new unsigned short[pixel_width * pixel_height];

	// data
	/* 0x36 */
	for (int i = 0; i < pixel_width * pixel_height; i++) {
		int x = i % pixel_width;
		int y = i / pixel_width;
		cdata[i] = getcData(x, y);
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
	of.write((char*)cdata, pixel_width * pixel_height * 2);
	of.close();

	delete cdata;
}


Portrait::Portrait()
	: SGZ2Image(4, 5)
{
}


Map::Map()
{
	width = 20;
	height = 14;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			tile_index[i][j] = 0;
		}
	}

	char fn[] = "map";
	memcpy(file_name, fn, strlen(fn) + 1);

	palette.pc[0].v = 0x7F95;
	palette.pc[1].v = 0x322C;
	palette.pc[2].v = 0x0120;
	palette.pc[3].v = 0x0080;

	for (int i = 0; i < 160; i++) {
		for (int j = 0; j < 112; j++) {
			cdata[i][j] = 0;
		}
	}
}

void Map::setTileIndex(unsigned char* ti)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			tile_index[j][i] = *(ti + i * width + j) - 0x35;
		}
	}

#if 0
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << hex << (int)(tile_index[j][i] + 0x35);
		}
		cout << endl;
	}
#endif
}

void Map::setBaseTile(unsigned char* buf)
{
	int offset = 0;

	for (int i = 0; i < 66; i++) {
		offset = i * 16;
		base_tile[i].setData(&buf[offset]);
	}
}

void Map::toBMP()
{
	BITMAPFILEHEADER header;

	/* 0x00 */
	header.bfType = 'MB';
	/* 0x02 */
	header.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + 160 * 112 * 2;
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
	for (int y = 0; y < 112; y++) {
		for (int x = 0; x < 160; x++) {
			int tile_x = x / 8;
			int tile_y = y / 8;
			int ti = tile_index[tile_x][tile_y];
			int x_in_tile = x % 8;
			int y_in_tile = y % 8;
			unsigned char data = base_tile[ti].getData(x_in_tile, y_in_tile);

			unsigned short v = palette.pc[data].v;
			cdata[x][y] = SGZ2Image::SwapBGR2RGB(v);
		}
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
	for (int y = 0; y < 112; y++) {
		for (int x = 0; x < 160; x++) {
			of.write((char*) & cdata[x][y], 2);
		}
	}
	of.close();
}


SmallFlag::SmallFlag()
	: SGZ2Image(1, 1)
{
	setFileName("small_flag");
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

