#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

//for realise v1
class CharFreq {
public:
	char character;
	int frequency;

	CharFreq(char c, int f) : character(c), frequency(f){}
};

void solution(std::string& input) {
	std::cout << "[IN]: " << input << std::endl;

	std::unordered_map<char, int> char_freq;
	for (char c : input) {
		char_freq[c]++;
	}

	//realise v1
	std::vector<CharFreq> sorted;
	for (const auto& element : char_freq) sorted.emplace_back(element.first, element.second);
	std::sort(sorted.begin(), sorted.end(), 
				[](const CharFreq& a, const CharFreq& b) {
					return a.frequency > b.frequency; 
				});

	std::cout << "[OUT]:\n";
	for (const auto& element : sorted) std::cout << element.character << ": " << element.frequency << std::endl;

	//realise v2
	/*std::vector<std::pair<char, int>> sorted(char_freq.begin(), char_freq.end());
	std::sort(sorted.begin(), sorted.end(),
				[](const std::pair<char, int>& a, const std::pair<char, int>& b) {
					return a.second > b.second;
				});
	
	std::cout << "[OUT]:\n";
	for (const auto& pair : sorted) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}*/

}

int main() {
	std::string text = "Hello world!!";
	solution(text);

	return 0;
}