#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Image
{
	int* points;
	int mx;
	int my;
};

void CreateImage(Image* img, int tmx, int tmy)
{
	img -> mx = tmx;
	img -> my = tmy;
	img -> points = new int[tmx * tmy]{ 1 };
}

void SetPointImage(Image* img, int x, int y, int color)
{
	img -> points[(y * img -> mx + x)] = color;
}

int GetPointImage(Image* img, int x, int y)
{
	return img -> points[(y * img -> mx + x)];
}

void ShowImage(Image* img)
{
	for (int i = 0; i < img -> my; i++)
	{
		for (int j = 0; j < img -> mx; j++)
		{
			cout << img -> points[i * img->mx + j] << " ";
		}
		cout << endl;
	}
}

void SaveToPnmFile(Image* img, string fileName)
{
	fstream out;
	out.open(fileName, fstream::out);
	out << "Picture" << endl;
	out << img -> mx << " " << img -> my << endl;

	for (int i = 0; i < img -> my; i++)
	{
		for (int j = 0; j < img -> mx; j++)
		{
			out << img -> points[i * img->mx + j] << " ";
		}
		out << endl;
	}
	out.close();
}

bool TestCreateImage()
{
	Image* pict = new Image;
	CreateImage(pic, 4, 7);

	if (pic -> pixels[0] == 0 && pic -> pixels[14] == 0 && pic -> mx == 4 && pic -> my == 7)
		return 0;
	return -1;
}

bool TestSetPointImage()
{
	Image* pict = new Image;
	CreateImage(pic, 1, 3);
	SetPointImage(pic, 7, 0, 267);
	SetPointImage(pic, 0, 3, 255);

	if (GetPointImage(pic, 7, 0) == 267 && GetPointImage(pic, 0, 3) == 255)
		return 0;
	return -1;
}

bool TestGetPointImage()
{
	Image* pict = new Image;
	CreateImage(pic, 1, 3);
	pic->points[2] = 255;
	if (GetPointImage(pic, 1, 2) == 255 && GetPointImage(pic, 1, 1) == 0)
		return 0;
	return -1;
}

bool TestShowImage()
{
	Image* pict = new Image;
	CreateImage(pic, 1, 2);
	SetPointImage(pic, 1, 1, 255);
	GetPointImage(pic, 1, 1);
	ShowImage(pic);
	if (pic->points[1 * pic->mx + 1] == 255)
		return 0;
	return -1;
}

bool TestSaveToPnmFile()
{
	Image* pict = new Image;
	CreateImage(pic, 1, 2);
	SetPointImage(pic, 1, 1, 255);
	GetPointImage(pic, 1, 1);
	ShowImage(pic);
	SaveToPnmFile(pic, "Test");
	if ("Test" == NULL)
		return -1;
	return 0;
}

void runTest(bool (*testFunction)(), const string& testName)
{
	if (testFunction())
		cout << "Test " << testName << " - ok" << endl;
	else
		cout << "Test " << testName << " - error " << endl;
}

int main()
{
	runTest(TestCreateImage, "TestCreateImage");
	runTest(TestGetPointImage, "TestGetPointImage");
	runTest(TestSetPointImage, "TestSetPointImage");
	runTest(TestShowImage, "TestShowImage");
	runTest(TestSaveToPnmFile, "TestSveToPnmFile");
}
