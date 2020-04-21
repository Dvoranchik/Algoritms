#pragma once
#pragma once
class Predicats {
public:
	bool operator()(int a, int b) const {
		return a > b;
	}
	bool operator()(char a, char b) const {
		return a > b;
	}
};
	