#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Game
{
	int id;
	char title[30];

	Game() :id(0) 
	{
		strcpy_s(title, "N/A");
	}
};

void addToGameUnbuffered(int N)
{
	fstream fs("gameDbUnbuffered.txt", ios::binary|ios::out);
	Game g;
	for (int i = 0; i < N; i++)
	{
		g.id = i;
		fs.write((char*)(&g), sizeof(Game));
	}
	fs.close();
}

void addToGameBuffered()
{
	ofstream ofs("gameDbBuffered.txt", ios::binary | ios::out);
	const int buff = 25000;
	const int N = 10000000;

	Game g[buff];
	int id = 1;
	for (int i = 0; i <= N/buff; i++)
	{
		for (int j = 0; j < buff; j++)
		{
			g[j].id = id;
			id++;
		}
		ofs.write((char*)(&g), sizeof(Game)*buff);
	}
	ofs.close();
}

void readGameUnbuffered()
{
	fstream ifs("gameDbUnbuffered.txt", ios::binary | ios::in);
	Game g;
	while (ifs.read((char*)(&g), sizeof(Game)))
	{
	}
	ifs.close();
}

void readGameBuffered()
{
	fstream ifs("gameDbBuffered.txt", ios::binary | ios::in);
	const int buffSize = 20;
	Game g[buffSize];
	while (ifs.read((char*)(&g), sizeof(Game)*buffSize))
	{
	}
	ifs.close();
}

int main()
{
	auto t1 = high_resolution_clock::now();

	readGameUnbuffered();

	auto t2 = high_resolution_clock::now(); 

	auto durationForUnbuffered = duration_cast<milliseconds>(t2 - t1).count();

	cout << "Duration for Unbuffered : " <<durationForUnbuffered;

	//-------------------------------------------------------------------------
	
	auto t3 = high_resolution_clock::now();

	readGameBuffered();

	auto t4 = high_resolution_clock::now(); 

	auto durationForBuffered = duration_cast<milliseconds>(t4 - t3).count();

	cout << "\nDuration for Buffered : " << durationForBuffered;



	cout << "\n";
	system("pause");
	return 0;
}