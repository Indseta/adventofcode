#include <2023/day_3/day_3_1.h>


Day3_1::Day3_1() : Day(2023, 3, 1) {}


void Day3_1::main() {
    auto &lines = get_lines();

    int total_sum = 0;

    process_lines(lines, total_sum);

    std::cout << total_sum << '\n';
}


void Day3_1::process_lines(std::vector<std::string> &lines, int &sum) {
    std::vector<std::vector<int>> symbol_locations;

    for (int line_i = 0; line_i < lines.size(); ++line_i) {
        auto &line = lines[line_i];

        for (int char_i = 0; char_i < line.size(); ++char_i) {
            const char &c = line[char_i];
            if (is_approved_symbol(c)) {
                symbol_locations.push_back({char_i, line_i});
            }
        }
    }

    for (int line_i = 0; line_i < lines.size(); ++line_i) {
        auto &line = lines[line_i];

        int number = 0;
        int start_index = 0;

        for (int char_i = 0; char_i < line.size(); ++char_i) {
            const char &c = line[char_i];
            if (isdigit(c)) {
                if (number == 0) {
                    start_index = char_i;
                }
                number = number * 10 + (c - '0');
            } else {
                if (number) {
                    if (is_adjacent(symbol_locations, start_index, line_i, char_i - start_index)) {
                        sum += number;
                    }
                    number = 0;
                }
            }
        }

        if (number) {
            if (is_adjacent(symbol_locations, start_index, line_i, line.size() - start_index)) {
                sum += number;
            }
        }
    }
}


bool Day3_1::is_approved_symbol(const char &c) {
    if (c == '.' && c != '-') {
        return false;
    }
    else if (isdigit(c)) {
        return false;
    }
    else {
        return true;
    }
}


bool Day3_1::is_adjacent(const std::vector<std::vector<int>> &symbol_locations, int x_location, int y_location, int x_size) {
    for (int y = -1; y <= 1; ++y) {
        for (int x = -1; x <= x_size; ++x) {
            int current_x = x_location + x;
            int current_y = y_location + y;

            for (const auto &location : symbol_locations) {
                if (location[0] == current_x && location[1] == current_y) {
                    return true;
                }
            }
        }
    }
    return false;
}