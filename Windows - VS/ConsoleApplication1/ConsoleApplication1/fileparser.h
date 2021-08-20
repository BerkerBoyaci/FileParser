#ifndef FILE_PARSER__HPP
#define FILE_PARSER__HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <thread>


namespace parser {

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

    class FileParserException : public std::exception {
    public:
        explicit FileParserException(const char* message) noexcept : m_message(message) {}
        explicit FileParserException(const std::string& message) noexcept : m_message(message) {}
        virtual ~FileParserException() noexcept {}

        virtual const char* what() const noexcept {
            return m_message.c_str();
        }
    protected:
        std::string m_message{ "Invalid Parser Query" };
    };

    class FileParser {
    public:
        explicit FileParser() noexcept = delete;
        explicit FileParser(const char* fileAdress) noexcept;
        explicit FileParser(const FileParser&)noexcept = delete;
        explicit FileParser(FileParser&&)noexcept = delete;
        FileParser& operator=(const FileParser&) = delete;
        FileParser& operator=(FileParser&) = delete;
        virtual ~FileParser() noexcept;

        virtual void open();
        virtual std::string getLines() const;
        virtual bool isOpen() const;
        virtual int fileLength();
        void parseFile(std::string t_extensionName);
       
        virtual void parseWithSize(size_t);
        virtual std::vector<std::string> parseWithDelimiter(char delim);
        virtual std::vector<std::string> getContests() const;
    protected:
        virtual void closeFile() ;
        void split(char t_delim);
        size_t stringSize() const;
    private:
        std::string m_lines;
        std::ifstream m_ifs;
        std::ofstream m_ofs;
        std::size_t m_fileLength;
        std::vector<std::string> m_lineOfString;
  
    };
}

#endif //FILE_PARSER__HPP