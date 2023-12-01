#include <base/day.h>


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
    label = std::format("{}, day {}.{}", year, day_major, day_minor);
}


const std::vector<std::string>& Day::get_lines() const {
    return lines;
}


const std::string& Day::get_label() const {
    return label;
}