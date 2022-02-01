#include <iostream>
#include <string>
#include <vector>
#include "fileparser.hpp"

 



int main()
{

    TestFileParser tfp{"../File1.test"};


    auto ret = tfp.getLines();
    std::cout << ret <<"\n\n";

    
    
    std::cout << "\n**********************************************\n";
    tfp.parse();
    std::cout << tfp <<"\n";



    return 0;
}