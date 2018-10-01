#include "CRYPTION.h"

CRYPTION::CRYPTION(std::string message, std::string key) {
	M = message;
	K = key;
	S = 0; 
}

CRYPTION::CRYPTION(std::string message, std::string key, int shift) {
	M = message;
	K = key;
	S = shift; 
}

CRYPTION::~CRYPTION() {}

// private functions 
char CRYPTION::e(char m, char k) {

	// ++++++++++++++++++++++++++++
	// new line handler
	// ++++++++++++++++++++++++++++
	int s = int(k) - N + S;

	if ((int(m) + s) <= X)
		return int(m) + s;
	else
		return (int(m) + s) - (X + 1 - N);
}

char CRYPTION::d(char m, char k) {
	// ++++++++++++++++++++++++++++
	// new line handler
	// ++++++++++++++++++++++++++++

	int s = int(k) - N + S;

	if ((int(m) - s) >= N)
		return int(m) - s;
	else
		return int(m) - s + X + 1 - N;
}

std::string CRYPTION::c(bool v = true) {
	std::string c;
	c.resize(M.length());
	int i = 0;
	int j = 0;

	for (auto m : M) {
		if (j == K.length()) { j = 0; }

		if (v) { c[i] += e(m, K[j]); }
		else { c[i] += d(m, K[j]); }

		j++;
		i++;
	}
	return c;
}

// public functions 
std::string CRYPTION::encrypt() { return c(true); }
std::string CRYPTION::decrypt() { return c(false); }
