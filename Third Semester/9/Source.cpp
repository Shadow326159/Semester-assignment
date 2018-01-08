#include <iostream>
#include <cstdio>
#include <windows.h>
using namespace std;

class RWImage
{
public:
	BITMAPFILEHEADER bmpfh;
    BITMAPINFOHEADER bmpih;
    unsigned char *R, *G, *B;
    RWImage()
	{
        R = NULL;
        G = NULL;
        B = NULL;
	}

	void ReadImageFromFile(char* filename)
	{
		FILE *file = fopen(filename, "rb");
		fread(&bmpfh, sizeof(BITMAPFILEHEADER), 1, file);
		fread(&bmpih, 40, 1, file);;
		fseek(file, bmpfh.bfOffBits, SEEK_SET);
        if (R != NULL || G != NULL || B != NULL)
		{
            delete[] R;
            delete[] G;
            delete[] B;
            R = NULL;
            G = NULL;
            B = NULL;
        }
		int i, j, k;
		char ch;
        int w = bmpih.biWidth;
        int h = bmpih.biHeight;
		R = new unsigned char [w*h];
        G = new unsigned char [w*h];
        B = new unsigned char [w*h];
        for (i=0; i<h; i++)
		{
            for (j=0; j<w; j++)
			{
				fread(B + i*w + j, 1, 1, file);
				fread(G + i*w + j, 1, 1, file);
				fread(R + i*w + j, 1, 1, file);
            }
			for (k = (3 * w) % 4; k != 0; k = (k + 1) % 4)
				fread(&ch, 1, 1, file);
        }
        fclose(file);
	}
	
	void WriteImage(char* filename)
	{
		FILE *file = fopen(filename, "wb");
		fwrite(&bmpfh, sizeof(BITMAPFILEHEADER), 1, file);
		fwrite(&bmpih, sizeof(BITMAPINFOHEADER), 1, file);
		int w = bmpih.biWidth;
        int h = bmpih.biHeight;
        int i, j, k;
        char ch = 0;
        for (i=0; i<h; i++) {
            for (j=0; j<w; j++)
			{
				fwrite(B + i*w + j, 1, 1, file);
				fwrite(G + i*w + j, 1, 1, file);
				fwrite(R + i*w + j, 1, 1, file);
            }
			for (k = (3 * w) % 4; k != 0; k = (k + 1) % 4)
				fwrite(&ch, 1, 1, file);
        }
        if(ftell(file)<bmpfh.bfSize)
		{
			for (i = bmpfh.bfSize - ftell(file); i > 0; i--)
				fwrite(&ch, 1, 1, file);
        }
        fclose(file);
    }
    
    void GetSize(int* h, int* w)
	{
		*h = bmpih.biHeight;
        *w = bmpih.biWidth;
    }
};

int main()
{
	int w,h;
	RWImage a;
    FILE* fout;
	a.ReadImageFromFile("input.bmp");
	a.GetSize(&h, &w);
	fout = fopen("out.txt", "w");
    fprintf(fout, "Размер первого файла %d x %d\n", h, w);
    a.WriteImage("out.bmp");
    a.ReadImageFromFile("second_pic.bmp");
    a.GetSize(&h,&w);
	fprintf(fout, "Размер второго файла %d x %d\n", h, w);
    fclose(fout);
    a.WriteImage("out2.bmp");
}