#include<iostream>
#include<fstream>
#include<chrono>
using namespace std::chrono;
using namespace std;
struct Game {
	int id;
	char title[30];
	Game() :id(0) {
		strcpy_s(title, "N/A");
	}
};
void addToGameUnbuffered(int N) {
	fstream fs("gameDbUnbuffered.txt" , ios::binary | ios::out);
	Game g;
	for (int i = 1; i < N; i = i + 1) {
		g.id = i;
		fs.write((char *)(&g), sizeof(Game));
	}
	fs.close();
}
void addToGameBuffered() {
	ofstream ofs("gameDbBuffered.txt", ios::binary | ios::out);
	const int buff = 25000;
	const int N = 10000000;
	Game g[buff];
	int id = 1;
	for (int i = 1; i <= N / buff; i = i + 1) {
		for (int j = 0; j < buff; j = j + 1)
		{
			g[j].id = id;
			id = id + 1;
		}
		ofs.write((char *)(&g), sizeof(Game)*buff);
	}
	ofs.close();
}
void readGamesUnbuffered() {
	fstream ifs("gameDbUnbuffered.txt", ios::binary | ios::in);
	Game g;
	while(ifs.read((char *)(&g) , sizeof(Game))){}
	ifs.close();
}
void readGamesBuffered() {
	fstream ifs("gameDbBuffered.txt", ios::binary | ios::in);
	const int buffSize = 20;
	Game g[buffSize];
	while (ifs.read((char *)(&g), sizeof(Game) * buffSize)) {}
	ifs.close();
}
int main()
{
	auto start = high_resolution_clock::now();
//	readGamesUnbuffered();
	readGamesBuffered();
//	addToGameUnbuffered(10000000);
//	addToGameBuffered();
	auto end = high_resolution_clock::now();
	auto time_taken = duration_cast<milliseconds>(end - start);
	cout << time_taken.count();
	
	cout << "\n\n\n";
	return 0;
}