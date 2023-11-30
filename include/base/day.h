#pragma once


#include <format>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>


class Day {
    public:
        Day(uint16_t year, uint8_t day_major, uint8_t day_minor);

        virtual void main() = 0;

    protected:
        std::vector<std::string> lines;
};