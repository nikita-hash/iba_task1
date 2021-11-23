#include<iostream>
#include<vector>
#include<fstream>
#include<Windows.h>
using namespace std;
template<class T>
void readInfo(vector<T>& vec, string file);
int main() {
	vector<int>vecBeetles;
	readInfo(vecBeetles, "TaskIn1.txt");
	for (int i = 0; i < vecBeetles.size(); i++) {
		for (int j = 0; j < vecBeetles.size(); j++) {
			if(i==j){}
			else {
				if (vecBeetles[i] + vecBeetles[j] == 2020) {
					cout << i + 1 << ") " << vecBeetles[i] << " + " << vecBeetles[j] << " = 2020  ===>> " << vecBeetles[i] * vecBeetles[j] << endl;
					vecBeetles.erase(vecBeetles.begin() + i);
				}
			}
		}
	}
	cout << "end task 1 and start task 1.2" << endl;
	system("pause");
	vecBeetles.clear();
	readInfo(vecBeetles, "TaskIn1.txt");
	for (int i = 0; i < vecBeetles.size(); i++) {
		for (int j = 1; j < vecBeetles.size(); j++) {
			int sum = vecBeetles[i] + vecBeetles[j];
			for (int z = 0; z < vecBeetles.size(); z++) {
				if (sum + vecBeetles[z] == 2020) {
					cout<< vecBeetles[i] << " + " << vecBeetles[j] << " + " << vecBeetles[z] << " = 2020  ===>> " << endl;
					system("pause");
				}
				if (vecBeetles[z] != vecBeetles[i] && vecBeetles[z] != vecBeetles[j]) {
					if (vecBeetles[z] + sum == 2020) {
						cout << i + 1 << ") " << vecBeetles[i] << " + " << vecBeetles[j] << " + " << vecBeetles[z] << " = 2020  ===>> " << vecBeetles[i] * vecBeetles[j] * vecBeetles[z] << endl;
						vecBeetles.erase(vecBeetles.begin() + i);
					}
				}
			}
		}
	}
	system("pause");
}

template<class T>
void readInfo(vector<T>& vec, string file)
{
	ifstream file1;
	file1.open(file);
	if (file1.peek() == 0) {}
	else {
		while (!file1.eof()) {
			T obj;
			file1 >> obj;
			vec.push_back(obj);
		}
	}
	file1.close();
}
