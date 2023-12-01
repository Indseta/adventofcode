#include <base/day.h>

#include <2023/day_1/day_1_1.h>
#include <2023/day_1/day_1_2.h>

#include <2023/day_2/day_2_1.h>
#include <2023/day_2/day_2_2.h>

#include <chrono>
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

    std::vector<Day*> programs;

    // Day 1
    Day1_1 day1_1;
    Day1_2 day1_2;

    programs.push_back(&day1_1);
    programs.push_back(&day1_2);

    // Day 2
    Day2_1 day2_1;
    Day2_2 day2_2;

    programs.push_back(&day2_1);
    programs.push_back(&day2_2);

    // Main

    std::chrono::high_resolution_clock::time_point start_time, end_time;
    std::chrono::duration<double, std::milli> elapsed_time, total_elapsed_time;

    total_elapsed_time = std::chrono::milliseconds(0);

    for (const auto &program : programs) {
        std::cout << '\n';
        std::cout << "-- " << program->get_label() << " --" << '\n';

        start_time = std::chrono::high_resolution_clock::now();

        program->main();

        end_time = std::chrono::high_resolution_clock::now();

        elapsed_time = end_time - start_time;
        total_elapsed_time += elapsed_time;

        std::cout << "Elapsed time: " << elapsed_time.count() << "ms" << '\n';
    }

    std::cout << '\n';
    std::cout << "Total elapsed time: " << total_elapsed_time.count() << "ms" << "\n";
    std::cout << '\n';

    return 0;
}