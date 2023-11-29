#include <iostream>
#include <vector>
#include <functional>
#include <math.h>
#include <algorithm>

using namespace std;

constexpr const double PI = 3.1415926;

void Sin(int angle) {
    cout << " sin : " << sin((angle * PI) / 180) << ' ';
}

void Cos(int angle) {
    cout << " cos : " << cos((angle * PI) / 180) << ' ';
}

void Tan(int angle) {
    cout << " tan : " << tan((angle * PI) / 180) << ' ';
}

vector<function<void(int)>> createFunctions() {
    vector<function<void(int)>> out;
    out.push_back(Sin);
    out.push_back(Cos);
    out.push_back(Tan);
    return out;
}

vector<int> convertToRadians(vector<int>& in) {
    vector<int> out;
    for (const auto& i : in) {
        out.push_back((i * PI) / 180);
    }
    return out;
}

void functionsOnAngles(vector <int> angles) {
    cout << "[Выходные данные] :" << endl;
    vector<function<void(int)>> functions = createFunctions();
    for (const auto& angle : angles) {
        std::cout << (angle * PI / 180) << ": ";
        //std::cout << angle << ":\t";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }
}

void printArrayOfAngles(vector<int>& angles) {
    int lastIndex = 0;
    cout << "[Входные данные]: ";
    for_each(angles.begin(), angles.end(), [&angles](int& n) { 
        if (n == angles.back()) cout << n << " * 3.1415926 / 180";
        else cout << n << " * 3.1415926 / 180, ";
        });
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> angles = { /*0, */30, 60, 90/*, 120, 150, 180, 210, 240, 270, 300, 330, 360*/};
    //vector<int> radians = convertToRadians(angles);
    printArrayOfAngles(angles);
    functionsOnAngles(angles);
	return 0;
}