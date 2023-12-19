#pragma once


#include <fstream>
#include <cstdint>
#include <string>
#include <thread>
#include <vector>


class Day {
    public:
        Day(uint16_t year, uint8_t day_major, uint8_t day_minor);

        virtual void main() = 0;

        const std::string& get_label() const;

    protected:
        std::vector<std::string>& get_lines();

        static size_t num_threads;

    private:
        std::vector<std::string> lines;
        std::string label;
};