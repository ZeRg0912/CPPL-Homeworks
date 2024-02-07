#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

template<typename T>
void solution() {
	T size;
	while(true) {
		std::cout << "Enter size of storage: ";
		std::cin >> size;
		system("cls");
		if (std::cin.fail() || size < 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Incorrect size, try again!\n";
		}
		else { break; }
	}
	

	std::vector<T> storage;
	for (size_t i = 0; i < size; i++) {
		std::cout << "Entering data: \n";
		if (!(storage.empty())) {
			std::cout << "Storage data: ";
			for (size_t i = 0; i < storage.size(); i++) {
				if (i != storage.size() - 1) std::cout << storage[i] << ", ";
				else std::cout << storage[i] << std::endl;
			}
		}
		T data;
		std::cout << "Put: ";
		std::cin >> data;
		storage.push_back(data);
		system("cls");
	}

	std::cout << "[IN]:\n";
	std::cout << size << std::endl;
	for (const auto& element : storage) {
		std::cout << element << std::endl;
	}

	std::sort(storage.begin(), storage.end(), std::greater<T>());
	auto last = std::unique(storage.begin(), storage.end());
	storage.erase(last, storage.end());

	storage.shrink_to_fit();

	std::cout << "[OUT]:\n";
	for (const auto& element : storage) {
		std::cout << element << std::endl;
	}
}

int main() {
	solution<double>();

	return 0;
}