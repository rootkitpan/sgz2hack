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


class SGZ2Image {
private:
	Tile* tiles;
	unsigned char* data;

public:
	int width;		/* in tiles */
	int height;		/* in tiles */

	SGZ2Image(unsigned char* buf, int width, int height);
	~SGZ2Image();

	void Show() const;
};


class Portrait : public SGZ2Image {
public:
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


#endif /* _SGZ2IMAGE_H_ */

