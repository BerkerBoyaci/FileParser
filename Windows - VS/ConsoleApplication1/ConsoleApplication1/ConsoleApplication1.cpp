#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include "fileparser.h"
#include <memory>
#include <thread>



struct thread_deleter {
    void operator()(std::thread* p) {
        if (p) {
            if (p->joinable())
                p->join();
            delete p;
            p = nullptr;
        }
    }
};


int main()
{
    try {
        auto beginCreate = std::chrono::system_clock::now();
        parser::FileParser tfp{ "Text.txt" };
        auto endCreate = std::chrono::system_clock::now();

        auto beginParse = std::chrono::system_clock::now();
        tfp.parseWithSize(200);
        auto endParse = std::chrono::system_clock::now();

        auto begin = std::chrono::system_clock::now();
        tfp.parseFile("txt");
        auto end = std::chrono::system_clock::now();

        std::chrono::duration<double, std::milli> ms_doubleCreate = endCreate - beginCreate;
        std::cout << "Create Time : " << ms_doubleCreate.count() << "\n";

        std::chrono::duration<double, std::milli> ms_doubleParse = endParse - beginParse;
        std::cout << "Parse Time : " << ms_doubleParse.count() << "\n";

        std::chrono::duration<double, std::milli> ms_doubleFile = end - begin;
        std::cout << "File Time : " << ms_doubleFile.count() << "\n";
    }
    catch (const parser::FileParserException& ex) {
        std::cout << ex.what() << "\n";
    }
    catch (...) {
        std::cout << "Unknown error.\n";
    }
    return 0;
}
