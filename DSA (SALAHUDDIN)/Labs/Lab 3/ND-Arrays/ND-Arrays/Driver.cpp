#include<iostream>
using namespace std;
class ND_Arrays
{
	private:
		int dimenssion;
		int * dimenssionSize;
		int * arrayData;
	public:
		ND_Arrays() {
			this->dimenssion = 0;
			this->dimenssionSize = NULL;
			this->arrayData = NULL;
		}
		ND_Arrays(int dimenssion, int * dimenssionSize) {
			if (dimenssion > 0) {
				bool isSizePositive = true;
				for (int i = 0; (i < dimenssion)&&(isSizePositive==true); i = i + 1)
				{
					if (dimenssionSize[i] <= 0)
						isSizePositive = false;
				}
				if (isSizePositive == true) {
					this->dimenssion = dimenssion;
					this->dimenssionSize = new int[this->dimenssion];
					for (int i = 0; i < this->dimenssion; i = i + 1)
						this->dimenssionSize[i] = dimenssionSize[i];
					int arraySize = 1;
					for (int i = 0; i < this->dimenssion; i = i + 1)
						arraySize = arraySize * this->dimenssionSize[i];
					this->arrayData = new int[arraySize];
				}
			}
		}
		int getArraySize() {
			if (this->dimenssion != 0) {
				int arraySize = 1;
				for (int i = 0; i < this->dimenssion; i = i + 1)
					arraySize = arraySize * this->dimenssionSize[i];
				return arraySize;
			}
			return 0;
		}
		void setValue(int * indexSet, int value) {
			if (this->dimenssion == 1) {
				if (indexSet[0] >= 0 && indexSet[0] < this->dimenssionSize[0])
					this->arrayData[indexSet[0]] = value;
				else
					cout << "Invalid Index...\n";
			}
			else if (this->dimenssion == 2) {
				if (indexSet[0] >= 0 && indexSet[0] < this->dimenssionSize[0]
					&& indexSet[1] >= 0 && indexSet[1] < this->dimenssionSize[1])
					this->arrayData[indexSet[0] * this->dimenssionSize[1] + indexSet[1]] = value;
				else
					cout << "Invalid Indexes...\n";
			}
			else {
				bool areIndexesValid = true;
				for (int i = 0; (i < this->dimenssion) && (areIndexesValid == true); i = i + 1) {
					if (indexSet[i] < 0 || indexSet[i] > this->dimenssionSize[i])
						areIndexesValid = false;
				}
				if (areIndexesValid == true) {
					int reqIndex, helper = 1;
					for (int i = 0; i < this->dimenssion; i = i + 1) {
						if (i != 0)
							helper = helper*this->dimenssionSize[i];
					}
					helper = helper * indexSet[0];
					reqIndex = helper + (this->dimenssionSize[this->dimenssion - 2] * indexSet[this->dimenssion - 2])
						+ indexSet[this->dimenssion - 1];
					this->arrayData[reqIndex] = value;
				}
				else
					cout << "Invalid Index...\n";
			}

			
		}
		int getValue(int * indexSet) {
			if (this->dimenssion == 1) {
				if (indexSet[0] >= 0 && indexSet[0] < this->dimenssionSize[0])
					return this->arrayData[indexSet[0]];
				else
					cout << "Invalid Index...\n";
			}
			else if (this->dimenssion == 2) {
				if (indexSet[0] >= 0 && indexSet[0] < this->dimenssionSize[0]
					&& indexSet[1] >= 0 && indexSet[1] < this->dimenssionSize[1])
					return this->arrayData[indexSet[0] * this->dimenssionSize[1] + indexSet[1]];
				else
					cout << "Invalid Indexes...\n";
			}
			else {
				bool areIndexesValid = true;
				for (int i = 0; (i < this->dimenssion) && (areIndexesValid == true); i = i + 1) {
					if (indexSet[i] < 0 || indexSet[i] > this->dimenssionSize[i])
						areIndexesValid = false;
				}
				if (areIndexesValid == true) {
					int reqIndex, helper = 1;
					for (int i = 0; i < this->dimenssion; i = i + 1) {
						if (i != 0)
							helper = helper*this->dimenssionSize[i];
					}
					helper = helper * indexSet[0];
					reqIndex = helper + (this->dimenssionSize[this->dimenssion - 2] * indexSet[this->dimenssion - 2])
						+ indexSet[this->dimenssion - 1];
					return this->arrayData[reqIndex];
				}
				else
					cout << "Invalid Index...\n";
			}
		}
		void displayArray() {
			int count = 1, elementsInEachDim = 1;
			for (int i = 0; i < this->dimenssion; i = i + 1) {
				if (i != 0)
					elementsInEachDim = elementsInEachDim*this->dimenssionSize[i];
			}
			for (int i = 0; (i < this->getArraySize()); i = i + 1) {
				cout << this->arrayData[i] << " ";
				if (count == elementsInEachDim) {
					cout << "\n";
					count = 1;
				}
				else
					count = count + 1;
			}
		}
};
int main()
{
	int dimSize[1] = { 3 };
	ND_Arrays array(1, dimSize);

/*
//                                              Indexes to test 1-D Array
	int indexSet1[1] = { 0 };
	int indexSet2[1] = { 1 };
	int indexSet3[1] = { 2 };

//                                              Set value to test 1-D Array
	array.setValue(indexSet1, 18);
	array.setValue(indexSet2, 19);
	array.setValue(indexSet3, 20);
*/

/*
//                                              Indexes to test 2-D Array
	int indexSet1[3] = { 0,0 };                 
	int indexSet2[3] = { 0,1 };
	int indexSet3[3] = { 0,2 };
	int indexSet4[3] = { 1,0 };
	int indexSet5[3] = { 1,1 };
	int indexSet6[3] = { 1,2 };
	int indexSet7[3] = { 2,0 };
	int indexSet8[3] = { 2,1 };
	int indexSet9[3] = { 2,2 };

	//                                              Set value to test 2-D Array
	array.setValue(indexSet1, 14);
	array.setValue(indexSet2, 15);
	array.setValue(indexSet3, 16);
	array.setValue(indexSet4, 17);
	array.setValue(indexSet5, 18);
	array.setValue(indexSet6, 19);
	array.setValue(indexSet7, 20);
	array.setValue(indexSet8, 21);
	array.setValue(indexSet9, 22);
*/

/*
//                                              Indexes to test 3-D Array
	int indexSet1[3] = { 0,0,0 };
	int indexSet2[3] = { 0,0,1 };
	int indexSet3[3] = { 0,0,2 };
	int indexSet4[3] = { 0,1,0 };
	int indexSet5[3] = { 0,1,1 };
	int indexSet6[3] = { 0,1,2 };
	int indexSet7[3] = { 0,2,0 };
	int indexSet8[3] = { 0,2,1 };
	int indexSet9[3] = { 0,2,2 };
	int indexSet10[3] = { 1,0,0 };
	int indexSet11[3] = { 1,0,1 };
	int indexSet12[3] = { 1,0,2 };
	int indexSet13[3] = { 1,1,0 };
	int indexSet14[3] = { 1,1,1 };
	int indexSet15[3] = { 1,1,2 };
	int indexSet16[3] = { 1,2,0 };
	int indexSet17[3] = { 1,2,1 };
	int indexSet18[3] = { 1,2,2 };
	int indexSet19[3] = { 2,0,0 };
	int indexSet20[3] = { 2,0,1 };
	int indexSet21[3] = { 2,0,2 };
	int indexSet22[3] = { 2,1,0 };
	int indexSet23[3] = { 2,1,1 };
	int indexSet24[3] = { 2,1,2 };
	int indexSet25[3] = { 2,2,0 };
	int indexSet26[3] = { 2,2,1 };
	int indexSet27[3] = { 2,2,2 };

//                                              Set value to test 3-D Array
	array.setValue(indexSet1, 14);
	array.setValue(indexSet2, 15);
	array.setValue(indexSet3, 16);
	array.setValue(indexSet4, 17);
	array.setValue(indexSet5, 18);
	array.setValue(indexSet6, 19);
	array.setValue(indexSet7, 20);
	array.setValue(indexSet8, 21);
	array.setValue(indexSet9, 22);
	array.setValue(indexSet10, 23);
	array.setValue(indexSet11, 24);
	array.setValue(indexSet12, 25);
	array.setValue(indexSet13,26);
	array.setValue(indexSet14, 27);
	array.setValue(indexSet15, 28);
	array.setValue(indexSet16, 29);
	array.setValue(indexSet17, 30);
	array.setValue(indexSet18, 31);
	array.setValue(indexSet19, 32);
	array.setValue(indexSet20, 33);
	array.setValue(indexSet21, 34);
	array.setValue(indexSet22, 35);
	array.setValue(indexSet23, 36);
	array.setValue(indexSet24, 37);
	array.setValue(indexSet25, 38);
	array.setValue(indexSet26, 39);
	array.setValue(indexSet27, 40);
*/
	array.displayArray();
//	cout << array.getValue(indexSet1);
	cout << "\n\n\n";
	return 0;
}