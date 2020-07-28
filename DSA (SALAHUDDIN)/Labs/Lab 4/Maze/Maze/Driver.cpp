#include<iostream>
#include"Stack.h"
using namespace std;
bool areIndexesValid(int size, int row, int column) {
	if (row < 0 || column < 0 || row >= size || column >= size)
		return false;
	return true;
}
bool isPathSafe(int ** maze, int size, int row, int column) {
	if (areIndexesValid(size, row, column) == true && maze[row][column] == 1)
		return true;
	else
		return false;
}
bool findSolutionPath(int ** maze, int ** solution , int size ,int row , int column) {
	if (areIndexesValid(size, row, column) == true) {
		if (row == size - 1 && column == size - 1) {
			solution[row][column] = 1;
			return true;
		}
		if (isPathSafe(maze, size, row, column) == true) {
			solution[row][column] = 1;
			if (findSolutionPath(maze, solution, size, row, column + 1) == true)
				return true;
			if (findSolutionPath(maze, solution, size, row + 1, column) == true)
				return true;
			solution[row][column] = 0;
			return false;
		}
	}
	return false;
}
void displaySolution(int ** solution, int size) {
	for (int i = 0; i < size; i = i + 1) {
		cout << "\n{ ";
		for (int j = 0; j < size; j = j + 1) {
			cout << solution[i][j];
			if (j != size - 1)
				cout << " , ";
		}
		cout << "}\n";
	}
}
void playRatMaze() {
	int N;
	cin >> N;
	int ** maze = new int*[N];
	for (int i = 0; i < N; i = i + 1) {
		maze[i] = new int[N];
	}
	int ** solutionPath = new int*[N];
	for (int i = 0; i < N; i = i + 1) {
		solutionPath[i] = new int[N];
	}
	for (int i = 0; i < N; i = i + 1) {
		for (int j = 0; j < N; j = j + 1) {
			cin >> maze[i][j];
		}
	}
	for (int i = 0; i < N; i = i + 1) {
		for (int j = 0; j < N; j = j + 1) {
			solutionPath[i][j] = 0;
		}
	}
	findSolutionPath(maze, solutionPath, N, 0, 0);
	displaySolution(solutionPath, N);

}
int main()
{
	playRatMaze();
	cout << "\n\n\n";
	return 0;
}