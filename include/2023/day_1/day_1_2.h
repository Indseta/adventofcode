#pragma once


#include <base/day.h>

#include <ctype.h>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


class Day1_2 : public Day {
    public:
        Day1_2();

        void main() override;

    private:
        bool is_numeric(std::string str_in) const;
        int numeric_to_int(std::string str_in) const;
};