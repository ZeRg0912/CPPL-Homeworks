#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class BigInt {
private:
	std::string value;
public:
	BigInt(const std::string& num) : value(num) {}
	BigInt(std::string&& num) : value(std::move(num)) {}

	BigInt& operator=(std::string&& num) {
		if (value != num) {
			value = std::move(num);
		}
		return *this;
	}

	BigInt operator+(const BigInt& other) const {
		std::string result;
		int carry = 0;
		size_t left = value.size() - 1;
		size_t right = other.value.size() - 1;

		while (left >= 0 || right >= 0 || carry) {
			int sum = carry;
			if (left >= 0) {
				sum += value[left--] - '0';
			}
			if (right >= 0) {
				sum += other.value[right--] - '0';
			}
			carry = sum / 10;
			sum %= 10;

			result.insert(result.begin(), sum + '0');
		}
		return BigInt(std::move(result));
	}

	BigInt operator*(int mult) const {
		std::string result;
		int carry = 0;

		for (size_t i = value.size() - 1; i >= 0 || carry; i--) {
			int temp = carry;
			if (i >= 0) temp += (value[i] - '0') * mult;
			carry = temp / 10;
			temp %= 10;
			result.insert(result.begin(), temp + '0');
		}
		return BigInt(std::move(result));
	}

	friend std::ostream& operator<<(std::ostream& os, const BigInt& big_int) {
		os << big_int.value;
		return os;
	}
};

int main() {
	auto number1 = BigInt("114575");
	auto number2 = BigInt("78524");
	auto result = number1 + number2;

	std::cout << result; // 193099

	return 0;
}