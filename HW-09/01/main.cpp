#include <iostream>
#include <vector>

template<typename T>
void Print(const std::vector<T>& vec) {
	if ((vec.size()) == 0) std::cout << "Vec is empty!\n";
	else {
		for (const auto& element : vec) {		
			if (vec.back() == element) std::cout << element << std::endl;
			else std::cout << element << ", ";		
		}
	}
}

template<typename T>
void MoveVectors(std::vector<T>& lhs, std::vector<T>& rhs) {
	std::vector<T> temp = std::move(lhs);
	lhs = std::move(rhs);
	rhs = std::move(temp);
}

int main() {
	// Check strings;
	std::vector<std::string> one = { "test_string1", "test_string2" };
	std::vector<std::string> two;

	std::cout << "Before:\n";
	std::cout << "One: ";
	Print(one);
	std::cout << "Two: ";
	Print(two);

	MoveVectors(one, two);

	std::cout << "After:\n";
	std::cout << "One: ";
	Print(one);
	std::cout << "Two: ";
	Print(two);

	MoveVectors(one, two);

	std::cout << "After second move:\n";
	std::cout << "One: ";
	Print(one);
	std::cout << "Two: ";
	Print(two);
	std::cout << std::endl;

	// Check int
	std::vector<int> three = { 0,5,10,15,20 };
	std::vector<int> four;

	std::cout << "Before:\n";
	std::cout << "three: ";
	Print(three);
	std::cout << "four: ";
	Print(four);

	MoveVectors(three, four);

	std::cout << "After:\n";
	std::cout << "three: ";
	Print(three);
	std::cout << "four: ";
	Print(four); 
	
	MoveVectors(three, four);

	std::cout << "After second move:\n";
	std::cout << "One: ";
	Print(three);
	std::cout << "Two: ";
	Print(four);
	std::cout << std::endl;

	return 0;
}