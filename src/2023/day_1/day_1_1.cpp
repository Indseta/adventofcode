#include <2023/day_1/day_1_1.h>


Day1_1::Day1_1() : Day(2023, 1, 1) {}


void Day1_1::main() {
    const auto &lines = get_lines();

    int sum = 0; 

    process_lines(lines, sum);

    std::cout << sum << '\n';
}


void Day1_1::process_lines(const std::vector<std::string> &lines, int &sum) { 
    for (const auto &line : lines) {
        std::vector<int> numbers;
        int number;

        for (const auto &c : line) {
            if (isdigit(c)) {
                number = c - '0';

                numbers.push_back(number);
            }
        }

        sum += std::stoi(std::to_string(numbers.front()) + std::to_string(numbers.back()));
    }
}