#include <2023/day_1/day_1_1.h>

#include <fstream>
#include <iostream>
#include <string>


void clear_terminal() {
    #ifdef _WIN32
    std::system("cls");
    #else
    std::system("clear");
    #endif
}


int main() {
    clear_terminal();

    Day1_1 day;
    day.main();

    return 0;
}