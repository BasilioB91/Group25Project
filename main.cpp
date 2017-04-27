#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string myArray[2000];
	string temp;
	int i = 1;
	ifstream inFile("poker.txt");

		while (!inFile.eof()) 
	{
		getline(inFile, myArray[i]);
		//cout << myArray[i] << "\n";
		i++;
	}

	inFile.close();

	system("pause");
	return 0;
}