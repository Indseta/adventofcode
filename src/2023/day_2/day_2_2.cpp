#include <2023/day_2/day_2_2.h>


Day2_2::Day2_2() : Day(2023, 2, 2) {}


void Day2_2::main() {
    auto &lines = get_lines();

    int total_sum = 0;

    process_lines(lines, total_sum);

    std::cout << total_sum << '\n';
}


void Day2_2::process_lines(std::vector<std::string> &lines, int &sum) {
    for (int i = 0; i < lines.size(); ++i) {
        auto &line = lines[i];
        line = split(line, ':')[1];

        auto round_result = split(line, ';');

        Set largest(0, 0, 0);

        for (const auto &set_str : round_result) {
            Set set(0, 0, 0);

            for (auto &entry : split(set_str, ',')) {
                const auto &color_id = entry.back();

                if (color_id == 'd') {
                    set.red = std::stoi(extract_number(entry));
                }
                else if (color_id == 'n') {
                    set.green = std::stoi(extract_number(entry));
                }
                else if (color_id == 'e') {
                    set.blue = std::stoi(extract_number(entry));
                }
            }

            if (set.red > largest.red) {
                largest.red = set.red;
            }
            if (set.green > largest.green) {
                largest.green = set.green;
            }
            if (set.blue > largest.blue) {
                largest.blue = set.blue;
            }
        }

        sum += largest.red * largest.green * largest.blue;
    }
}


std::vector<std::string> Day2_2::split(const std::string &full_string, const char delimiter) const {
    std::vector<std::string> tokens;
    std::stringstream ss(full_string);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}


std::string Day2_2::extract_number(const std::string &full_string) const {
    int i = 0;

    if (full_string[0] == ' ') {
        i = 1;
    }

    for (; i < full_string.length(); ++i) {
        if (!isdigit(full_string[i])) {
            break;
        }
    }

    return full_string.substr(0, i);
}