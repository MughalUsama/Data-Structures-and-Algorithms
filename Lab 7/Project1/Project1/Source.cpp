#include <iostream>
using namespace std;


int countpix=0;
void fillColor(int **arr, int m, int n, int pixelX, int pixelY, int color)
{
	if (pixelX >= 0 && pixelX < m && pixelY >= 0  && pixelY < n && arr[pixelX][pixelY]!=color)
	{
		int prevColor = arr[pixelX][pixelY];
		arr[pixelX][pixelY] = color;
		if (pixelX+1 < m && (prevColor== arr[pixelX+1][pixelY]) )
		{			   
			fillColor(arr, m, n, pixelX + 1, pixelY, color);
		}
		
		if (pixelX-1 >= 0 && prevColor == arr[pixelX - 1][pixelY] )
		{

			fillColor(arr, m, n, pixelX - 1, pixelY, color);
		}
		if (pixelY+1 < n && prevColor == arr[pixelX ][pixelY+1] )
		{

			fillColor(arr, m, n, pixelX , pixelY+1, color);
		}
		if (pixelY-1 >= 0 && arr[pixelX][pixelY] == arr[pixelX][pixelY-1] )
		{

			fillColor(arr, m, n, pixelX , pixelY-1, color);
		}
	}
}
void fillCount(int **arr, int m, int n, int pixelX, int pixelY, int color)
{
	if (pixelX >= 0 && pixelX < m && pixelY >= 0 && pixelY < n && arr[pixelX][pixelY] != color)
	{
		int prevColor = arr[pixelX][pixelY];
		arr[pixelX][pixelY] = color;
		countpix++;
		if (pixelX + 1 < m && (prevColor == arr[pixelX + 1][pixelY]))
		{
			fillColor(arr, m, n, pixelX + 1, pixelY, color);
		}

		if (pixelX - 1 >= 0 && prevColor == arr[pixelX - 1][pixelY])
		{
			arr[pixelX][pixelY] = color;

			fillColor(arr, m, n, pixelX - 1, pixelY, color);
		}
		if (pixelY + 1 < n && prevColor == arr[pixelX][pixelY + 1])
		{
			arr[pixelX][pixelY] = color;

			fillColor(arr, m, n, pixelX, pixelY + 1, color);
		}
		if (pixelY - 1 >= 0 && arr[pixelX][pixelY] == arr[pixelX][pixelY - 1])
		{
			arr[pixelX][pixelY] = color;

			fillColor(arr, m, n, pixelX, pixelY - 1, color);
		}
	}
}

int main()
{
	int arr1[7][7] = {
						{0,0,0,0,0,0,0},
						{0,1,1,1,1,1,0},
						{0,1,0,1,0,1,0},
						{0,1,1,1,1,1,0},
						{0,1,2,2,2,1,0},
						{0,1,1,1,1,1,0},
						{0,1,0,0,0,0,0},
					};
	int m = 7, n = 7;
	int **arr=new int*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j]=arr1[i][j];
		}

	}
	cout << "\n\n";

	fillColor(arr, 7,7, 1, 1, 3);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
	//cout << countpix;
	return 0;
}