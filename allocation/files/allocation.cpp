#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

#define Megabyte (1024 * 1024)
#define RequiredArgc 4

int main(int argc, char *argv[]) {
    if (argc != RequiredArgc) {
        std::cout << "Usage: <max> <size> <interval>" << std::endl;
        std::cout << std::endl;
        std::cout << "\t<max>\t\tmax of iterations e.g.: 100" << std::endl;
        std::cout << "\t<size>\t\tsize in MB e.g.: 25 = 25MB" << std::endl;
        std::cout << "\t<interval>\tinterval in milliseconds, e.g. 1000 = 1 Second" << std::endl;
        return 1;
    }

    int max = std::stoi(argv[1]);
    int size = std::stoi(argv[2]);
    int interval = std::stoi(argv[3]);
    int malloc_size = Megabyte * size / 1024 / 1024;
    char *data;

    for (int i = 0; i < max; i++) {
        printf("[%i] Allocating %iMB..\n", i, malloc_size);
        data = (char *) malloc(Megabyte * malloc_size);
        printf("[%i] Sleep for %i..\n", i, interval);
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}