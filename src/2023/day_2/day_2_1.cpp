#include <2023/day_2/day_2_1.h>


Day2_1::Day2_1() : Day(2023, 2, 1) {}


void Day2_1::main() {
    auto &lines = get_lines();

    int total_sum = 0;

    process_lines(lines, total_sum);

    std::cout << total_sum << '\n';
}


void Day2_1::process_lines(std::vector<std::string> &lines, int &sum) {
    const Set max(12, 13, 14);

    for (int i = 0; i < lines.size(); ++i) {
        auto &line = lines[i];
        line = split(line, ':')[1];

        auto round_result = split(line, ';');

        bool max_exceeded = false;

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

            if (set.red > max.red) {
                max_exceeded = true;
            }
            else if (set.green > max.green) {
                max_exceeded = true;
            }
            else if (set.blue > max.blue) {
                max_exceeded = true;
            }
        }

        if (!max_exceeded) {
            sum += i + 1;
        }
    }
}


std::vector<std::string> Day2_1::split(const std::string &full_string, const char delimiter) const {
    std::vector<std::string> tokens;
    std::stringstream ss(full_string);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}


std::string Day2_1::extract_number(const std::string &full_string) const {
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