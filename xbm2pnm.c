#include <stdio.h>
#define xstr(x) #x
#define str(x) xstr(x)
#include str(XBM_FILE.xbm)

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte) \
	(byte & 0x01 ? 1 : 0), \
	(byte & 0x02 ? 1 : 0), \
	(byte & 0x04 ? 1 : 0), \
	(byte & 0x08 ? 1 : 0), \
	(byte & 0x10 ? 1 : 0), \
	(byte & 0x20 ? 1 : 0), \
	(byte & 0x40 ? 1 : 0), \
	(byte & 0x80 ? 1 : 0)

const char *xbm_bits = &XBM_BITS;
const int xbm_width = XBM_WIDTH;
const int xbm_height = XBM_HEIGHT;

int main()
{
	printf("P1\n%d %d\n", xbm_width, xbm_height);

	unsigned int pixelnum = 0;
	for (unsigned int i = 0; i<XBM_ARR_SIZE; i++)
	{
		char tmp[10];
		sprintf(tmp, BYTETOBINARYPATTERN, BYTETOBINARY(xbm_bits[i]));

		// discard extra bits in last byte of each row
		//int pixelnum = i * 8;
		int nextpixelnum = pixelnum + 8;
		const int nextrownum = nextpixelnum / xbm_width;
		const int rownum = pixelnum / xbm_width;
		const int colnum = pixelnum - (rownum * xbm_width);
		if (nextrownum > rownum)
		{
			const int extrabits = 8 - (xbm_width - colnum);
			nextpixelnum -= extrabits;
			tmp[8-extrabits] = '\n';
			tmp[8-extrabits+1] = '\0';
		}
		printf("%s", tmp);
		pixelnum = nextpixelnum;
	}
}
