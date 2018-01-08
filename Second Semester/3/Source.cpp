#include <iostream>
#include <Windows.h>
void main()
{
	BITMAPFILEHEADER fh;
	BITMAPINFOHEADER ih;
	FILE* pin = fopen("in.bmp", "rb");
	fread(&fh, sizeof(fh), 1, pin);
	fread(&ih, sizeof(ih), 1, pin);
	FILE* pout = fopen("out.bmp", "wb");
	fwrite(&fh, sizeof(fh), 1, pout);
	fwrite(&ih, sizeof(ih), 1, pout);
	for (int i = 0; i < ih.biHeight; i++)
	{
		unsigned char r, g, b;
		for (int j = 0; j < ih.biWidth; j++)
		{
			fread(&r, 1, 1, pin);
			fread(&g, 1, 1, pin);
			fread(&b, 1, 1, pin);
			b = g = r = (b + g + r) / 3;
			fwrite(&r, 1, 1, pout);
			fwrite(&g, 1, 1, pout);
			fwrite(&b, 1, 1, pout);
		}
	}
	if (ih.biWidth % 4)
	{
		unsigned char t[3];
		fread(&t, 4 - (3 * ih.biWidth) % 4, 1, pin);
		fwrite(&t, 4 - (3 * ih.biWidth) % 4, 1, pout);
	}
	fclose(pin);
	fclose(pout);
}