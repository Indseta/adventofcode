#pragma once


#include <base/day.h>

#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>


class Day1_2 : public Day {
    public:
        Day1_2();

        void main() override;

    private:
        void process_lines(const std::vector<std::string> &lines, int &sum);
        bool is_numeric(const std::string &compare_target) const;
        int numeric_to_int(const std::string &compare_target) const;
};