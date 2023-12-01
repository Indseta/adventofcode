#include <base/day.h>
#include <2023/day_1/day_1_1.h>
#include <2023/day_1/day_1_2.h>

#include <string>
#include <vector>


void clear_terminal() {
    #ifdef _WIN32
    std::system("cls");
    #else
    std::system("clear");
    #endif
}


int main() {
    clear_terminal();

    std::vector<Day*> day_objects;

    Day1_2 day1_2;
    Day1_1 day1_1;

    day_objects.push_back(&day1_2);
    day_objects.push_back(&day1_1);

    for (const auto &day_object : day_objects) {
        std::cout << '\n' << day_object->get_label() << '\n';
        day_object->main();
    }

    return 0;
}