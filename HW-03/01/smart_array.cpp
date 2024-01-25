#include "smart_array.h"

void smart_array::add_element(int element) {
	if (last_index < size) {
		data[last_index] = element;
		last_index++;
	}
	else {
		throw std::overflow_error("Массив заполнен! Не удалось добавить элемент\n");
	}
}

int smart_array::get_element(int index) {
	if (index < size && index > 0) {
		return data[index];
	}
	else {
		throw std::out_of_range("Выход за пределы массива! Указанного индекса не существует!\n");
	}
}

void smart_array::print() {
	std::cout << "Массив: ";
	for (int i = 0; i < size; i++) {
		if (i != size - 1) std::cout << data[i] << ", ";
		else std::cout << data[i] << std::endl;
	}
}

smart_array& smart_array::operator=(const smart_array& other) {
	if (this != &other) {
		delete[] data;
		size = other.size;
		last_index = other.last_index;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}