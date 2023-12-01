#include <2023/day_1/day_1_2.h>


Day1_2::Day1_2() : Day(2023, 1, 1) {}


void Day1_2::main() {
    const auto &lines = get_lines();

    int sum = 0;

    for (const auto &line : lines) {
        size_t line_size = line.size();

        std::vector<int> numbers;

        for (int i_start = 0; i_start < line_size; ++i_start) {
            std::string str_conc;

            for (int i = i_start; i < line_size; ++i) {
                const auto &c = line[i];
                str_conc += c;
                if (is_numeric(str_conc)) {
                    numbers.push_back(numeric_to_int(str_conc));
                }
            }
        }

        sum += std::stoi(std::to_string(numbers.front()) + std::to_string(numbers.back()));
    }

    std::cout << sum << '\n';
}


bool Day1_2::is_numeric(std::string str_in) const {
    if (str_in == "0" || str_in == "zero") {
        return true;
    }
    else if (str_in == "1" || str_in == "one") {
        return true;
    }
    else if (str_in == "2" || str_in == "two") {
        return true;
    }
    else if (str_in == "3" || str_in == "three") {
        return true;
    }
    else if (str_in == "4" || str_in == "four") {
        return true;
    }
    else if (str_in == "5" || str_in == "five") {
        return true;
    }
    else if (str_in == "6" || str_in == "six") {
        return true;
    }
    else if (str_in == "7" || str_in == "seven") {
        return true;
    }
    else if (str_in == "8" || str_in == "eight") {
        return true;
    }
    else if (str_in == "9" || str_in == "nine") {
        return true;
    }
    else {
        return false;
    }
}


int Day1_2::numeric_to_int(std::string str_in) const {
    if (str_in == "0" || str_in == "zero") {
        return 0;
    }
    else if (str_in == "1" || str_in == "one") {
        return 1;
    }
    else if (str_in == "2" || str_in == "two") {
        return 2;
    }
    else if (str_in == "3" || str_in == "three") {
        return 3;
    }
    else if (str_in == "4" || str_in == "four") {
        return 4;
    }
    else if (str_in == "5" || str_in == "five") {
        return 5;
    }
    else if (str_in == "6" || str_in == "six") {
        return 6;
    }
    else if (str_in == "7" || str_in == "seven") {
        return 7;
    }
    else if (str_in == "8" || str_in == "eight") {
        return 8;
    }
    else if (str_in == "9" || str_in == "nine") {
        return 9;
    }
    else {
        std::cerr << "std::string \"" << str_in << "\" is not numeric" << '\n';
        return 0;
    }
}