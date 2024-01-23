#include <iostream>
#include "smart_array.h"

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	system("chcp 1251");
	system("cls");
	
	try{
		/*smart_array arr(5);
		for (int i = 0; i < 5; i++) {
			arr.add_element(i);
		}
		arr.print();
		for (int i = 0; i < 6; i++) {
			arr.get_element(i);
		}*/

		/*smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;*/

		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.print();

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		new_array.print();

		arr = new_array;
		arr.print();

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}