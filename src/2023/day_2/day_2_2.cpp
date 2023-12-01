#include <2023/day_2/day_2_2.h>


Day2_2::Day2_2() : Day(2023, 2, 2) {}


void Day2_2::main() {
    const auto &lines = get_lines();

    for (const auto &line : lines) {
        std::cout << line << '\n';
    }
}