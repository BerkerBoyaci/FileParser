#ifndef FILE_PARSER__HPP
#define FILE_PARSER__HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

class TestFileParser {
public:
    explicit TestFileParser() = delete;
    explicit TestFileParser(const char* fileAdress) noexcept;
    virtual ~TestFileParser();

    virtual void open();
    virtual std::string getLines() const;
    virtual bool is_open() const;
    void parse();
    virtual std::vector<std::string> getContests() const;
    friend std::ostream& operator<<(std::ostream&, const TestFileParser&);

protected:
    virtual void close_file();


private:
    std::string lines;
    std::ifstream ifs;
    std::vector<std::string> lineOfString;

    std::vector<std::string> split(const std::string&, char);
};



#endif //FILE_PARSER__HPP