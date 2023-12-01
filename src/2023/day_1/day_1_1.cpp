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
        size_t line_length = line.length();

        std::string number = "";

        for (int i = 0; i < line_length; ++i) {
            const auto &c = line[i];

            if (isdigit(c)) {
                number += c;
                break;
            }
        }

        for (int i = line_length - 1; i >= 0; --i) {
            const auto &c = line[i];

            if (isdigit(c)) {
                number += c;
                break;
            }
        }

        sum += std::stoi(number);
    }
}