#include <2023/day_3/day_3_1.h>


Day3_1::Day3_1() : Day(2023, 3, 1) {}


void Day3_1::main() {
    auto &lines = get_lines();

    int total_sum = 0;

    process_lines(lines, total_sum);

    std::cout << total_sum << '\n';
}


void Day3_1::process_lines(const std::vector<std::string> &lines, int &sum) {
    for (const auto &line : lines) {}
}