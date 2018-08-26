#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>


class Map_Generation {
public:
	Map_Generation();
	int randomGenerator(int lower_limit, int upper_limit);
private:
	std::uniform_int_distribution<int> dist;
	std::mt19937_64 the_generator;
	std::random_device ran_dev;
};
Map_Generation::Map_Generation() {
	the_generator.seed(ran_dev());
}
int Map_Generation::randomGenerator(int lower_limit, int upper_limit) {
	std::uniform_int_distribution<int>::param_type parameters(lower_limit, upper_limit);
	dist.param(parameters);
	return dist(the_generator);
}

void output_to_console(int n, int *numbers) {
	for (int i = 0; i < n; ++i) {
		std::cout<<numbers[i] << std::endl;
	}
}

void output_to_file(int n, int *numbers) {
	std::ofstream output;
	output.open("data.txt");
	for (int i = 0; i < n; ++i) {
		output << numbers[i] << std::endl;
	}
	output.close();
}

int main() {
	int n,lower_limit,upper_limit;	//All limits are inclusive, so 1 lower limit and 10 upper limit will give 1 and 10 as results
	Map_Generation m;
	//Call m.randomGenerator(lower_limit, upper_limit) to use
	std::cout << "Input amount of numbers to generate\n";
	std::cin >> n;
	std::cout << "Lower limit: ";
	std::cin >> lower_limit;
	std::cout << "Upper limit: ";
	std::cin >> upper_limit;
	int *numbers = new int[n];
	for (int i = 0; i < n; ++i) {
		numbers[i] = m.randomGenerator(lower_limit, upper_limit);
	}
	output_to_console(n, numbers);
	output_to_file(n, numbers);
	std::cout << "Input anything to exit: ";
	std::cin >> n;
}