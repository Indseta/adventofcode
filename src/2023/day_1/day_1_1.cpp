#include <2023/day_1/day_1_1.h>


Day1_1::Day1_1() : Day(2023, 1, 2) {}


void Day1_1::main() {
    const auto &lines = get_lines();

    int sum = 0; 

    for (const auto &line : lines) {
        std::vector<int> numbers;

        for (const auto &c : line) {
            if (isdigit(c)) {
                int number = c - '0';

                numbers.push_back(number);
            }
        }

        sum += std::stoi(std::to_string(numbers.front()) + std::to_string(numbers.back()));
    }

    std::cout << sum << '\n';
}