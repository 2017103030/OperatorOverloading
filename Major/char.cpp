#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
typedef unsigned char BYTE;

int main() {
	ifstream img("./CHJ.jpg", ios::binary);
	vector<BYTE> ImgByte;
	
	while (img) {
		BYTE data;
		img >> data;
		cout << (int)data << " ";
		ImgByte.push_back(data);
	}
	ofstream wrt("Imade.jpg");
	for (int i = 0; i < ImgByte.size(); i++) wrt << ImgByte[i];

}