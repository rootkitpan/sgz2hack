#ifndef _SGZ2IMAGE_H_
#define _SGZ2IMAGE_H_


/* one color */
typedef union _PALETTE_COLOR {
	unsigned short v;
	struct {
		unsigned short r : 5;
		unsigned short g : 5;
		unsigned short b : 5;
		unsigned short rsvd : 1;
	};
} PALETTE_COLOR, * PPALETTE_COLOR;

/* one palette consists of 4 colors */
typedef union _PALETTE {
	PALETTE_COLOR pc[4];
} PALETTE, * PPALETTE;

/* one palette group consists of 8 palettes */
typedef union _PALETTE_GROUP {
	PALETTE p[8];
} PALETTE_GROUP, * PPALETTE_GROUP;

#define PALETTE_GROUP_COUNT 8


class Tile {
private:
	unsigned char data[8][8];
	unsigned char GetBitFront(unsigned char data, int i);
	PALETTE palette;

public:
	static const int TILE_WIDTH = 8;
	static const int TILE_HEIGHT = 8;
	Tile();
	void setData(unsigned char* buf);		/* 16bytes ==> data[8][8]*/
	unsigned char getData(int x, int y) const;
	void setPalette(PPALETTE p);
	unsigned short getcData(int x, int y) const;

	void show() const;
};



class SGZ2Image {
private:
	int width;				/* width in tiles */
	int height;				/* height in tiles */

	int pixel_width;		/* width in pixels = width * 8 */
	int pixel_height;		/* height in pixels = height * 8 */

	char file_name[260];	/* used for bmp file name */

	Tile* tiles;			/* tiles[width * height] <= = > tiles[width][height] */

	int getTileIndex(int x, int y) const;


public:
	SGZ2Image(int width, int height);
	~SGZ2Image();

	void setData(int tile_index, unsigned char* d);
	void setData(int tile_x, int tile_y, unsigned char* d);
	void setData(unsigned char* d);

	unsigned char getData(int x, int y) const;
	unsigned short getcData(int x, int y) const;

	void setFileName(const char* fn);

	void setPalette(int tile_index, PPALETTE p);

	void show() const;
	void toBMP() const;

	static unsigned short SwapBGR2RGB(unsigned short bgr);
};


class Portrait : public SGZ2Image {
public:
	static const int POITRAIT_COUNT = 256;
	Portrait();
};

class Map
{
private:
	int width;		/* in tiles */
	int height;		/* in tiles */

	unsigned char tile_index[20][14];

	char file_name[260];		// used for bmp

	PALETTE palette;

	Tile base_tile[66];			// 0x35-0x76  0x42ÖÖ

	unsigned short cdata[160][112];		// data + color --> cdata

public:
	Map();
	void setTileIndex(unsigned char* ti);
	void setBaseTile(unsigned char* buf);
	void toBMP();
};


class SmallFlag : public SGZ2Image {
public:
	static const int SMALL_FLAG_COUNT = 16;
	SmallFlag();
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
	

*/

#endif /* _SGZ2IMAGE_H_ */

