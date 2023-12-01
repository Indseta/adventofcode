#pragma once


#include <base/day.h>

#include <iostream>
#include <string>
#include <thread>
#include <vector>


class Day1_1 : public Day {
    public:
        Day1_1();

        void main() override;

    private:
        void process_lines(const std::vector<std::string> &lines, int &sum);
};