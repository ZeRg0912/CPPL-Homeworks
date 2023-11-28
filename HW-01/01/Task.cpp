#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printArray(vector<int>& arr) {
	int lastIndex = 0;
	for (auto num : arr) {
		cout << num;
		if (lastIndex != arr.size() - 1) cout << ", ";
		lastIndex++;
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	vector<int> inArray;
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
			else if (in != 0){
				inArray.push_back(in);
				break;
			}
			else { break; }
		} while (!isdigit(in));
	} while (in != 0);

	printArray(inArray);

	inArray.clear();

	return 0;
}