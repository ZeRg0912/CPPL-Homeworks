#include "smart_array.h"

smart_array::smart_array(int init_size) : data(new int[init_size] {}), size(init_size) {}

smart_array::~smart_array() {
	delete[] data;
}

void smart_array::add_element(int element) {
	if (current_index < size) {
		data[current_index] = element;
		current_index++;
	}
	else {
		throw std::overflow_error("Массив заполнен! Не удалось добавить элемент\n");
	}
}

int smart_array::get_element(int index) {
	if (index < size) {
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
		current_index = other.current_index;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}