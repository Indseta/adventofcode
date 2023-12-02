#include <base/day.h>


size_t Day::num_threads = 1; // std::thread::hardware_concurrency()


Day::Day(uint16_t year, uint8_t day_major, uint8_t day_minor) {
    // Open file
    const char *file_path = std::format("../src/resources/{}/day_{}_input.txt", year, day_major).c_str();

    std::ifstream file;
    file.open(file_path);

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    // Set label
    label = std::format("Day {}.{}", day_major, day_minor);
}


std::vector<std::string>& Day::get_lines() {
    return lines;
}


const std::string& Day::get_label() const {
    return label;
}