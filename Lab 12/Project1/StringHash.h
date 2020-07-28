#ifndef STRING_HASH
#define STRING_HASH

#include <string>
#include "SingleLinkedList.h"
using namespace std;
class Pair
{
public :
	string key;
	string value;
	Pair(string& k, string& v)
	{
		key = k;
		value = v;
	}
		
};

class StringHash
{
private:
	SinglyLinkedList<Pair> HashTable[256];
	int noOfElements;
	int getHash(const string&);
	int getHashHelper(int);
	string convertToBinary(int);
	int convertToDecimal(string& str);
public:
	StringHash();
	bool insert(const string& key, const string& value);
	bool remove(const string& key);
	bool find(const string& value);
	bool empty();
	bool clear();
	int size();
	~StringHash();
	string& operator[] (const string& key);
};

int StringHash::getHash(const string& key)
{
	int size = key.length();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += key[i];
	}
	int sum1 = 0;
	int sum2 = sum;
	int maxBits = 255;

	while (sum2 > 256)
	{
		sum = sum2;
		sum2 = 0;
		while (sum!=0)
		{
			sum1 = sum;
			sum2 += sum1 & maxBits;
			sum = sum >> 8;
		}
	}
	char calcKey = ~sum2;
	return calcKey;
}
int StringHash::getHashHelper(int sum)
{

}
string StringHash::convertToBinary(int num)
{
	string str;
	while (num>0)
	{
		str.push_back((num % 2)+'0');
		num /= 2;
	}
	return str;
}
int StringHash::convertToDecimal(string& str)
{

	return 0;
}
StringHash::StringHash()
{
	this->noOfElements = 0;
}
   
bool StringHash::insert(const string& key, const string& value)
{
	int index = getHash(key);
	Node <Pair>* head = HashTable[index].getHead();
	if (head==nullptr)
	{
		HashTable[index].getHead()->value.key = key;
		HashTable[index].getHead()->value.value = value;
	}
	else
	{
		while (head!=nullptr)
		{

		}
	}
	return false;
}

bool StringHash::remove(const string& key)
{
	return false;
}

bool StringHash::find(const string& value)
{
	return false;
}

bool StringHash::empty()
{
	return (noOfElements==0);
}

bool StringHash::clear()
{
	for (int i = 0; i < 256; i++)
	{
		HashTable[i].~SinglyLinkedList();
		noOfElements = 0;
	}
	return false;
}

int StringHash::size()
{
	return 0;
}


StringHash::~StringHash()
{
	this->noOfElements = 0;
}

string& StringHash::operator[](const string& key)
{
	// TODO: insert return statement here
}
#endif