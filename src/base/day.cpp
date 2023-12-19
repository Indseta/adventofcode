#include <base/day.h>


size_t Day::num_threads = 1; // std::thread::hardware_concurrency()


Day::Day(uint16_t year, uint8_t day_major, uint8_t day_minor) {
    // Open file
    std::string file_path = ("../src/resources/" + std::to_string(year) + "/day_" + std::to_string(day_major) + "_input.txt");

    std::ifstream file;
    file.open(file_path.c_str());

    if (!file.is_open()) {
        std::cerr << "Failed to open file " << file_path << '\n';
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    // Set label
    label = "Day " + std::to_string(day_major) + "." + std::to_string(day_minor);
}


std::vector<std::string>& Day::get_lines() {
    return lines;
}


const std::string& Day::get_label() const {
    return label;
}