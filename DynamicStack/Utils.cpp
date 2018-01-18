#include "stdafx.h"
#include "Utils.hpp"

namespace utils {

	bool isDigit(const char c) {
		return (c >= '0' && c <= '9');
	}

	bool isOperation(const char c) {
		return (c == 'f' || c == 'm' || c == 'l');
	}

	int fact(int number) {
		if (number == 0 || number == 1)
			return 1;
		else
			return number * fact(number - 1);
	}

	int f(int number) {
		return (number * number) % 10;
	}

	int l(int number) {
		return fact(number) % 10;
	}

	int m(int x, int y) {
		return x < y ? x : y;
	}

}
