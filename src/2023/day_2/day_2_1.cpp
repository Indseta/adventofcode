#include <2023/day_2/day_2_1.h>


Day2_1::Day2_1() : Day(2023, 2, 1) {}


void Day2_1::main() {
    const auto &lines = get_lines();

    for (const auto &line : lines) {
        std::cout << line << '\n';
    }
}