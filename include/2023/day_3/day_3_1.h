#pragma once


#include <base/day.h>

#include <ctype.h>
#include <iostream>
#include <string>
#include <unordered_map>


class Day3_1 : public Day {
    public:
        Day3_1();

        void main() override;

    private:
        void process_lines(std::vector<std::string> &lines, int &sum);

        bool is_approved_symbol(const char &c);
        bool is_adjacent(const std::vector<std::vector<int>> &symbol_locations, int x_location, int y_location, int x_size);
};