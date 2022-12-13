#include "Header.hpp"
#include <iostream>

namespace lab {

	void Summa(char *a, char *b) {
		int length;
		if (a.length() > b.length()) {
			length = a.length() + 1;
		}
		else {
			length = b.length() + 1;
		}
		for (int i = 0; i < length; i++) {
			b[i] += a[i];
			b[i + 1] += (b[i] / 10);
			b[i] %= 10;
		}
		if (b[length - 1] == 0)
			length--;
	}

	void Multi(char a[1000], char b[1000]) {

	}

	void printResult(std::string a) {
		for (int i = a.length() - 1; i >= 0; i--) {
			std::cout << a[i];
		}
	}
}