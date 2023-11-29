#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void enterIntoArray(vector<int>& arr) {
	int in;
	do {
		do {
			cout << "Введите значение: ";
			cin >> in;
			system("cls");
			if (cin.fail()) {
				std::cout << "Введите цифру!" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	vector<int> inArray;

	auto print = [](const int& n) { cout << n << ' '; };
	
	enterIntoArray(inArray);
	cout << "Входные данные: ";
	for_each(inArray.cbegin(), inArray.cend(), print);
	cout << endl;

	cout << "Выходные данные: ";
	std::for_each(inArray.begin(), inArray.end(), [](int& n) { if(n % 2) n *= 3; });
	for_each(inArray.cbegin(), inArray.cend(), print);
	cout << endl;
	inArray.clear();

	return 0;
}