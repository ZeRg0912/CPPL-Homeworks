#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

size_t enter_size() {
	int size;
	while (true) {
		std::cout << "Enter size of storage: ";
		std::cin >> size;
		system("cls");
		if (!std::cin.fail() && (size < std::numeric_limits<size_t>::max() && size >= 0)) {
			break;
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Incorrect size, try again!\n";
		}
	}
	return static_cast<size_t>(size);
}

template<typename T>
void fill_vector(std::vector<T>& storage) {
	size_t size = enter_size();
	T data;
	for (size_t i = 0; i < size; i++) {
		while (true) {
			std::cout << "Entering data: \n";
			if (!(storage.empty())) {
				std::cout << "Storage data: ";
				for (size_t i = 0; i < storage.size(); i++) {
					if (i != storage.size() - 1) std::cout << storage[i] << ", ";
					else std::cout << storage[i] << std::endl;
				}
			}
			std::cout << "Put: ";
			std::cin >> data;
			system("cls");
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cerr << "Incorrect data, try again!\n";
			}
			else {
				storage.push_back(data);
				break;
			}
		}
	}
}

template<typename T>
void unique_with_sort(std::vector<T>& storage) {
	std::sort(storage.begin(), storage.end(), std::greater<T>());
	auto last = std::unique(storage.begin(), storage.end());
	storage.erase(last, storage.end());
	storage.shrink_to_fit();
}

template<typename T>
void print(std::vector<T>& storage) {
	for (const auto& element : storage) {
		std::cout << element << std::endl;
	}
}

template<typename T>
void solution() {
	std::vector<T> storage;
	fill_vector(storage);
	std::cout << "[IN]:\n";
	std::cout << storage.size() << std::endl;
	print(storage);
	unique_with_sort(storage);
	std::cout << "[OUT]:\n";
	print(storage);
}

int main() {
	solution<int>();
#if 0
	std::cout << std::string(30, '=') << std::endl;
	solution<std::string>();
#endif

	return 0;
}