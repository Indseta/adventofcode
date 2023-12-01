#include <2023/day_1/day_1_2.h>


Day1_2::Day1_2() : Day(2023, 1, 2) {}


void Day1_2::main() {
    const auto& lines = get_lines();

    std::vector<std::thread> threads(num_threads);
    std::vector<int> thread_sums(num_threads, 0);

    size_t lines_per_thread = lines.size() / num_threads;

    for (size_t i = 0; i < num_threads; ++i) {
        size_t start = i * lines_per_thread;
        size_t end = (i + 1 == num_threads) ? lines.size() : start + lines_per_thread;
        std::vector<std::string> thread_lines(lines.begin() + start, lines.begin() + end);

        threads[i] = std::thread(&Day1_2::process_lines, this, thread_lines, std::ref(thread_sums[i]));
    }

    for (auto &thread : threads) {
        thread.join();
    }

    int total_sum = 0;
    for (const auto &sum : thread_sums) {
        total_sum += sum;
    }

    std::cout << total_sum << '\n';
}


void Day1_2::process_lines(const std::vector<std::string> &lines, int &sum) {
    for (const auto &line : lines) {
        size_t line_length = line.length();

        std::string number = "";

        for (int i_start = 0; i_start < line_length; ++i_start) {
            std::string str_conc = "";

            int max_word_index = std::min(i_start + 5, (int) line_length);
            for (int i = i_start; i < max_word_index; ++i) {
                str_conc += line[i];

                if (is_numeric(str_conc)) {
                    number += std::to_string(numeric_to_int(str_conc));
                    goto find_last_digit;
                }
            }
        }

        find_last_digit:
        for (int i_start = line_length - 1; i_start >= 0; --i_start) {
            std::string str_conc = "";

            int max_word_index = std::max(i_start - 4, 0);
            for (int i = i_start; i >= max_word_index; --i) {
                str_conc = line[i] + str_conc;

                if (is_numeric(str_conc)) {
                    number += std::to_string(numeric_to_int(str_conc));
                    goto calculate_sum;
                }
            }
        }

        calculate_sum:
        sum += std::stoi(number);
    }
}


bool Day1_2::is_numeric(const std::string &compare_target) const {
    if (compare_target == "0" || compare_target == "zero") {
        return true;
    }
    else if (compare_target == "1" || compare_target == "one") {
        return true;
    }
    else if (compare_target == "2" || compare_target == "two") {
        return true;
    }
    else if (compare_target == "3" || compare_target == "three") {
        return true;
    }
    else if (compare_target == "4" || compare_target == "four") {
        return true;
    }
    else if (compare_target == "5" || compare_target == "five") {
        return true;
    }
    else if (compare_target == "6" || compare_target == "six") {
        return true;
    }
    else if (compare_target == "7" || compare_target == "seven") {
        return true;
    }
    else if (compare_target == "8" || compare_target == "eight") {
        return true;
    }
    else if (compare_target == "9" || compare_target == "nine") {
        return true;
    }
    else {
        return false;
    }
}


int Day1_2::numeric_to_int(const std::string &compare_target) const {
    if (compare_target == "0" || compare_target == "zero") {
        return 0;
    }
    else if (compare_target == "1" || compare_target == "one") {
        return 1;
    }
    else if (compare_target == "2" || compare_target == "two") {
        return 2;
    }
    else if (compare_target == "3" || compare_target == "three") {
        return 3;
    }
    else if (compare_target == "4" || compare_target == "four") {
        return 4;
    }
    else if (compare_target == "5" || compare_target == "five") {
        return 5;
    }
    else if (compare_target == "6" || compare_target == "six") {
        return 6;
    }
    else if (compare_target == "7" || compare_target == "seven") {
        return 7;
    }
    else if (compare_target == "8" || compare_target == "eight") {
        return 8;
    }
    else if (compare_target == "9" || compare_target == "nine") {
        return 9;
    }
    else {
        std::cerr << "std::string \"" << compare_target << "\" is not numeric" << '\n';
        return -1;
    }
}