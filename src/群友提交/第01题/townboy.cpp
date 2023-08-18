#include <vector>
#include <functional>
#include <iostream>

std::vector<int> &operator|(std::vector<int> &a, const std::function<void(const int&)> &b) {
	for (auto &ia : a)
		b(ia);
	return a;
}

std::vector<int> &operator|(std::vector<int> &a, const std::function<void(int&)> &b) {
	for (auto &ia : a)
		b(ia);
	return a;
}

int main() {
    std::vector<int> v{1, 2, 3};
    std::function f {[](const int& i) {std::cout << i << ' '; } };
    auto f2 = [](int& i) {i *= i; };
    v | f2 | f;
}
