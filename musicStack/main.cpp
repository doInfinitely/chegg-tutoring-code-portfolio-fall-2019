#include "stringStack.h"
#include "stringQueue.h"
#include <fstream>
#include <vector>

string songs_in_list(std::vector<string> namelist, int num) {
    stringQueue simqueue;
    for (string name: namelist) {
        simqueue.enQueue(name);
    }

    while (simqueue.size() > 1) {
        for (int i = 0; i < num; ++i) {
            simqueue.enQueue(simqueue.deQueue());
        }
    }
    simqueue.deQueue();
    return simqueue.deQueue();
}

int main() {
    std::ifstream infile("thefile.txt");
    std::string line;
    std::vector<string> lines;
    while (std::getline(infile, line, '|')) {
        string temp = line;
        lines.push_back(temp);
    }
    cout << songs_in_list(lines, 6);
    infile.close();
    return 0;
}
