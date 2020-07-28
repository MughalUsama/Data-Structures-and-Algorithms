#include <iostream>
using namespace std;

void getSolution(int maze[][4],int n)
{
	int ** mazeSol = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mazeSol[i] = new int[n];
	}
	int lastCol=0,lastRow=0;
	mazeSol[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j]==1 && lastCol <= j && lastRow==i && maze[i][j-1]==1)
			{
				mazeSol[i][j] = 1;
				lastCol = j;
			}
			else if(maze[i][j] == 1 && lastRow <= i && lastCol == j && maze[i-1][j] == 1)
			{
				mazeSol[i][j] = 1;
				lastRow = i;
			}
			else if(i!=0 || j!=0)
			{
				mazeSol[i][j] = 0;
			}
		}
	}
	if (mazeSol[n-1][n-1]==0  )
	{

		cout << "no Sol\n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << mazeSol[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
}


int main()
{
	int maze[4][4] = {	{1,1,1,1},
						{1,1,0,1},
						{1,0,0,0},
						{1,1,1,1} };

	getSolution(maze,4);

	cout << "\n";
	return 0;
}