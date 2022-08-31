#include <fstream>
#include <iostream>
using namespace std;
#include <windows.h>

int main() {
	ifstream fin;
	ofstream fout("c:\\data\\res.txt");

	char filename[20];
	char name[20];
	char addr[20];
	double height;

	cout << "오픈 할 파일명을 입력하시오 : ";
	cin >> filename;
	fin.open(filename);
	if (fin.fail()) {
		cout << filename << "file open error!!!" << endl;
		system("pause");
		return 0;
	}
	while (1) {
		fin.getline(name, sizeof(name));
		if (fin.eof()) { break; }
		fin.getline(addr, sizeof(addr));
		fin >> height;
		fin.get();
		cout << name << " " << addr << " " << height << endl;
	}

	fin.clear();
	fin.seekg(0);

	while (1) {
		fin.getline(name, sizeof(name));
		if (fin.eof()) { break; }
		fin.getline(addr, sizeof(addr));
		fin >> height;
		fin.get();
		fout << name << " " << addr << " " << height << endl;
	}
	fin.close();
	fout.close();
}