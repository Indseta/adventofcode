#pragma once


#include <base/day.h>

#include <iostream>


class Day3_1 : public Day {
    public:
        Day3_1();

        void main() override;

    private:
        void process_lines(const std::vector<std::string> &lines, int &sum);
};