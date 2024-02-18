#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class BigInt {
private:
	std::string value;
public:
	// Constructors
#if 0
	BigInt(const std::string& num) {
		value = "";
		if (!num.empty() && num.find_first_not_of("0123456789") == std::string::npos) value = num;
		else throw ("ERROR! not number");
	}
#endif

	BigInt(unsigned long long num) {
		value = "";
		if (num == 0) {
			value = "0";
			return;
		}

		while (num != 0) {
			value = char('0' + (num % 10)) + value;
			num /= 10;
		}
	}

	BigInt(const BigInt& other) {
		value = other.value;
	}

	BigInt(BigInt&& other) noexcept {
		value = std::move(other.value);
	}

	// Заработало когда убрал (- '0') в value.push_back(num[i] - '0');
#if 1 
	BigInt(const std::string& num) {
		value = "";
		for (int i = 0; i < num.size(); i++) {
			if (!isdigit(num[i])) throw ("ERROR! not number");
			value.push_back(num[i]);
		}
	}
#endif

	// Getters
	std::string getValue() const {
		return value;
	}

	// Operators
	bool operator==(const BigInt& other) const {
		return value == other.value;
	}

	bool operator!=(const BigInt& other) const {
		return value != other.value;
	}

	bool operator<(const BigInt& other) const {
		if (value.size() != other.value.size()) {
			return value.size() < other.value.size();
		}
		else {
			return value < other.value;
		}
	}

	bool operator>(const BigInt& other) const {
		if (value.size() != other.value.size()) {
			return value.size() > other.value.size();
		}
		else {
			return value > other.value;
		}
	}

	BigInt& operator=(BigInt&& other) noexcept {
		if (this != &other) {
			value = std::move(other.value);
		}
		return *this;
	}

	BigInt& operator=(BigInt& other) {
		if (this != &other) {
			value = other.value;
		}
		return *this;
	}

	BigInt& operator=(const std::string& string) {
		if (value != string) {
			value = string;
		}
		return *this;
	}

	BigInt operator+(const BigInt& other) const {
		std::string result;
		int carry = 0;
		int left = value.size() - 1;
		int right = other.value.size() - 1;

		// Continue while there are digits in both numbers or there's a carryover
		while (left >= 0 || right >= 0 || carry) {
			// Calculate sum of current digits and carryover
			int sum = carry;
			if (left >= 0) {
				sum += value[left] - '0';
				left--;
			}
			if (right >= 0) {
				sum += other.value[right] - '0';
				right--;
			}

			// Add units place to result
			result.insert(result.begin(), (sum % 10) + '0');
			carry = sum / 10;
		}

		return BigInt(result);
	}

	BigInt operator*(const BigInt& other) const {
		std::string result(value.size() + other.value.size(), '0');

		for (int i = value.size() - 1; i >= 0; i--) {
			int carry = 0;
			for (int j = other.value.size() - 1; j >= 0; j--) {
				int product = (value[i] - '0') * (other.value[j] - '0') + (result[i + j + 1] - '0') + carry;
				result[i + j + 1] = product % 10 + '0';
				carry = product / 10;
			}
			result[i] += carry;
		}

		// Delete zero before
		size_t start_pos = result.find_first_not_of('0');
		if (start_pos != std::string::npos) {
			return BigInt(result.substr(start_pos));
		}
		else {
			return BigInt("0");
		}
	}
};

std::ostream& operator<<(std::ostream& os, const BigInt& bigint) {
	os << bigint.getValue();
	return os;
}

template<typename T>
void Mult(const T& num1, const T& num2) {
	std::cout << "Mmultiply : " << num1 << " * " << num2 << " = " << num1 * num2 << '\n';
	//return num1 * num2;
}

template<typename T>
void Sum(const T& num1, const T& num2) {
	std::cout << "Sum: " << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
	//return num1 * num2;
}

template<typename T>
void Check(const T& num1, const T& num2) {
	if (num1 == num2) std::cout << num1 << " = " << num2 << '\n';
	else if (num1 > num2) std::cout << num1 << " > " << num2 << '\n';
	else std::cout << num1 << " < " << num2 << '\n';

	//return num1 * num2;
}

int main() {
	try {
		auto number1 = BigInt("114575");
		auto number2 = BigInt("78524");
		std::cout << "\033[32mBase section:\033[0m\n";
		std::cout << "Consttructor with string: number1 = " << number1 << std::endl;
		std::cout << "Consttructor with string: number2 = " << number2 << std::endl;
		auto result = number1 + number2;
		std::cout << "Result of sum: " << result << std::endl; // 193099
		result = number1 * number2;
		std::cout << "Result of mult: " << result << std::endl; // 8996887300
		std::cout << std::string(70, '-') << "\n";

		Sum(number1, number2);
		Mult(number1, number2);
		std::cout << std::string(70, '=') << "\n";

		std::cout << "\033[32mConsttructor with num:\033[0m\n";
		auto number3 = BigInt(5555534534534);
		std::cout << "number3 = " << number3 << std::endl;
		std::cout << std::string(70, '=') << "\n";

		std::cout << "\033[32mBool check section:\033[0m\n";
		Check(number1, number2);
		Check(number2, number1);
		Check(number3, number1);
		Check(number2, number3);
		Check(number3, number3);
		std::cout << std::string(70, '=') << "\n";

		std::cout << "\033[32mAssignment w/o move: \033[0m\n";
		std::cout << "before assignment: number1 = "
			<< number1
			<< " & number2 = "
			<< number2
			<< std::endl;
		number1 = number2;
		std::cout << "After assignment: number1 = " 
			<< number1
			<< " & number2 = "
			<< number2
			<< std::endl;

		std::cout << std::string(70, '-') << "\n";
		number1 = "114575";
		number2 = BigInt(number1); 
		std::cout << "\033[32mAfter number1 = string(114575)) & number2 = BigInt(number1):\033[0m\n"
			<< "number1 = "
			<< number1
			<< " & number2 = "
			<< number2
			<< std::endl;
		std::cout << std::string(70, '=') << "\n";		

		number2 = 78524;

		std::cout << "\033[32mAssignment with move: \033[0m\n";
		std::cout << "before move assignment: number1 = "
			<< number1
			<< " & number2 = "
			<< number2
			<< std::endl;
		number1 = BigInt(std::move(number2));
		std::cout << "After move assignment: number1 = "
			<< number1
			<< " & number2 = "
			<< number2
			<< std::endl;
		std::cout << std::string(70, '=') << "\n";

		std::cout << "\033[32mAssignment with move: \033[0m\n";
		std::cout << "before move assignment: number1 = "
			<< number1
			<< " & number2 = "
			<< number2
			<< std::endl;
		number1 = BigInt(std::move(number2));
		std::cout << "After move assignment: number1 = "
			<< number1
			<< " & number2 = "
			<< number2
			<< std::endl;
		std::cout << std::string(70, '=') << "\n";

	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
