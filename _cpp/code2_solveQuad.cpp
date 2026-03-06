#include <iostream>
#include <utility>
#include <cmath>

std::pair<bool, std::pair<float, float>> solveQuadratic(int a, int b, int c) {
	float des = std::pow(b,2) - 4*a*c;
	if (des < 0) {
		return {false, {0,0}};
	} else {
		return {true, {(-b - std::sqrt(des))/(2*a),(-b + std::sqrt(des))/(2*a)}};
	}
}
int main() {
	struct quadEq {
		int a, b, c;
	};
	quadEq eq1 {3, -5, 2};
	// std::pair<bool, std::pair<float, float>> result = solveQuadratic(eq1.a, eq1.b, eq1.c);
	auto result = solveQuadratic(eq1.a, eq1.b, eq1.c);
	if (result.first) {
		std::cout << "Roots: " << result.second.first << "; " << result.second.second;
	} else {
		std::cout << "Imaginary roots";
	}
	return 0;
}