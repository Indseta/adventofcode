#include <base/day.h>


Day::Day(uint16_t year, uint8_t day_major, uint8_t day_minor) {
    const char *file_path = std::format("../src/resources/{}/day_{}_{}_input.txt", year, day_major, day_minor).c_str();

    std::ifstream file;
    file.open(file_path);

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
}