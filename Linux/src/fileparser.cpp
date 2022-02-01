#include "fileparser.hpp"

TestFileParser::TestFileParser(const std::string& fileAdress) noexcept : ifs{fileAdress}{ 
    open(); 
}

TestFileParser::~TestFileParser(){ 
    if(is_open())
        ifs.close();
}

bool TestFileParser::is_open() const {
    return ifs.is_open();
}

void TestFileParser::close_file(){
    ifs.close();
}

void TestFileParser::open(){
    if(is_open())
        lines.assign((std::istreambuf_iterator<char>(ifs)) , std::istreambuf_iterator<char>());
    else
        std::cout << "TestFileParser::open() : File cannot open.\n";
}

void TestFileParser::parse(){
    std::replace_if( lines.begin() , lines.end() , [](auto tmp){ return tmp == '|'; }, '\n');
    lineOfString = split(lines , ';');
}

std::vector<std::string> TestFileParser::getContests() const{
    return lineOfString;
}

std::string TestFileParser::getLines() const {
     return lines; 
}

std::vector<std::string> TestFileParser::split (const std::string& s, char delim) {
    std::vector<std::string> ret;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        ret.push_back(item);
        ret.push_back("\n\n");
    }
    return ret;
}

std::ostream& operator<<(std::ostream& os , const TestFileParser& tfp){
    for( const auto& a : tfp.getContests())   
        os << a;
    return os;
}