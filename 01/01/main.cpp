#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(vector<int>& arr) {
	cout << "Входные данные: ";
	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;
}

void enterArray(vector<int>& arr) {
	int in;
	do {		
		do {		
			if (arr.size() != 0) printArray(arr);
			cout << "Введите значение: ";
			cin >> in;
			system("cls");
			if (cin.fail()) {
				cout << "Введите корректное значение!";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else if (in != 0) {
				arr.push_back(in);
				break; 
			}
			else { break; }
		} while (!isdigit(in));
	} while (in != 0);
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	system("chcp 1251");
	system("cls");
	vector<int> array;

	auto print = [](const int& n) { cout << n << ' '; };
	auto mult = [](int& n) { if (n % 2) n *= 3; };

	enterArray(array);
	cout << "Входные данные: ";
	for_each(array.cbegin(), array.cend(), print);
	cout << endl;

	cout << "Выходные данные: ";
	for_each(array.begin(), array.end(), mult);
	for_each(array.cbegin(), array.cend(), print);
	cout << endl;
	array.clear();

	return 0;
}