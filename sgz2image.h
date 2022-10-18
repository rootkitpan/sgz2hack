#ifndef _SGZ2IMAGE_H_
#define _SGZ2IMAGE_H_


class Tile {
private:
	unsigned char data[8][8];
	unsigned char GetBitFront(unsigned char data, int i);

public:
	void Convert2Tile(unsigned char* buf);
	unsigned char GetData(int i, int j);
};


typedef union _PALETTE_COLOR {
	unsigned short v;
	struct {
		unsigned short r : 5;
		unsigned short g : 5;
		unsigned short b : 5;
		unsigned short rsvd : 1;
	};
} PALETTE_COLOR, * PPALETTE_COLOR;

typedef union _PALETTE {
	PALETTE_COLOR pc[4];
} PALETTE, * PPALETTE;

typedef union _PALETTE_GROUP {
	PALETTE p[8];
} PALETTE_GROUP, * PPALETTE_GROUP;

#define PALETTE_GROUP_COUNT 8

class SGZ2Image {
private:
	Tile* tiles;
	unsigned char* data;

	PPALETTE_GROUP palette_group;
	unsigned char* palette_index;
	unsigned short* cdata;	// data + palette --> cdata

public:
	int width;		/* in tiles */
	int height;		/* in tiles */


	SGZ2Image(unsigned char* buf, int width, int height);
	~SGZ2Image();

	void Show() const;
	void ToBMP() const;

	void SetPaletteGroup(PPALETTE_GROUP p);
	void SetPaletteIndex(unsigned char* p);
};


class Portrait : public SGZ2Image {
public:
	static const int POITRAIT_COUNT = 256;
	Portrait(unsigned char* buf);
};

/* ******************************************************************* */

class Tile1bit {
private:
	unsigned char data[8][8];
	unsigned char GetBitFront(unsigned char data, int i);

public:
	void Convert2Tile(unsigned char* buf);
	unsigned char GetData(int i, int j);
};


class SGZ2Image1bit {
private:
	Tile1bit* tiles;
	unsigned char* data;

public:
	int width;		/* in tiles */
	int height;		/* in tiles */

	SGZ2Image1bit(unsigned char* buf, int width, int height);
	~SGZ2Image1bit();

	void Show() const;
};


class CharDot : public SGZ2Image1bit {
public:
	CharDot(unsigned char* buf);
};

/*
	¤Î	

*/

#endif /* _SGZ2IMAGE_H_ */

