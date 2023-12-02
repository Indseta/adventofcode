#include <2023/day_3/day_3_2.h>


Day3_2::Day3_2() : Day(2023, 3, 2) {}


void Day3_2::main() {
    auto &lines = get_lines();

    int total_sum = 0;

    process_lines(lines, total_sum);

    std::cout << total_sum << '\n';
}


void Day3_2::process_lines(const std::vector<std::string> &lines, int &sum) {
    for (const auto &line : lines) {}
}