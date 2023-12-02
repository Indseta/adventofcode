#pragma once


#include <base/day.h>

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>


class Day2_1 : public Day {
    struct Set {
        Set(unsigned int red, unsigned int green, unsigned int blue) : red(red), green(green), blue(blue) {}

        unsigned int red;
        unsigned int green;
        unsigned int blue;
    };

    public:
        Day2_1();

        void main() override;

    private:
        void process_lines(std::vector<std::string> &lines, int &sum);

        std::vector<std::string> split(const std::string &full_string, const char delimiter) const;
        std::string extract_number(const std::string &full_string) const;
};