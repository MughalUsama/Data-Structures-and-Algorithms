#include <iostream>
#include <Windows.h>

using namespace std;

void fillColor(int arr[][10], int N, int pixelX, int pixelY,int color,int prevColor)
{
	if (pixelX >= 0 && pixelX < N && pixelY >= 0 && pixelY < N && arr[pixelX][pixelY] == prevColor && prevColor!=color)
	{
		arr[pixelX][pixelY] = color;
		fillColor(arr, N, pixelX + 1, pixelY, color, prevColor);
		fillColor(arr, N, pixelX - 1, pixelY, color, prevColor);
		fillColor(arr, N, pixelX, pixelY - 1, color, prevColor);
		fillColor(arr, N, pixelX, pixelY + 1, color, prevColor);
	}
}



int main()
{
	int arr[10][10] = {
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,1,1,1,0,0,0,0},
						{0,0,1,0,0,0,1,0,0,0},
						{0,1,0,0,0,0,0,1,0,0},
						{0,1,0,0,0,0,0,1,0,0},
						{0,1,0,0,0,0,0,1,0,0},
						{0,1,0,0,0,0,0,1,0,0},
						{0,0,1,0,0,0,1,0,0,0},
						{0,0,0,1,1,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
												};
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n\n";

	fillColor(arr, 10, 3, 4, 9, 0);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j]<<" ";
			//Sleep(50);
		}
		cout << "\n";
	}
	cout << "\n";
	return 0;
}