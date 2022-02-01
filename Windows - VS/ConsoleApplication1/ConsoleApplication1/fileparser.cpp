#include "fileparser.h"

namespace parser {

    FileParser::FileParser(const char* fileAdress) noexcept : m_ifs{ fileAdress } {
        open();
    }
    FileParser::~FileParser() {
        if (isOpen())
            closeFile();
    }
    bool FileParser::isOpen() const {
        return m_ifs.is_open();
    }
    void FileParser::closeFile() {
        m_ifs.close();
    }
    void FileParser::open() {
        if (isOpen())
            m_lines.assign((std::istreambuf_iterator<char>(m_ifs)), std::istreambuf_iterator<char>());
        else
            throw FileParserException{ "FileParser::open() : File cannot open." };
    }
    std::vector<std::string> FileParser::getContests() const {
        return m_lineOfString;
    }
    std::string FileParser::getLines() const {
        return m_lines;
    }
    void FileParser::split(char t_delim) {
        std::stringstream ss(m_lines);
        std::string item;

        while (getline(ss, item, t_delim)) 
            m_lineOfString.push_back(item);
           
    }
    int FileParser::fileLength() {
        if (m_ifs) {
            m_ifs.seekg(0, m_ifs.end);
            m_fileLength = m_ifs.tellg();
            m_ifs.seekg(0, m_ifs.beg);
            return m_fileLength;
        }
        else
            throw FileParserException{ "Error in fileLength : file can not open" };
    }

    void FileParser::parseWithSize(size_t t_size) {
        if (isOpen() && m_lines.size() > 0) {
            size_t t_strSize = stringSize();
            size_t t_count = t_strSize / t_size;

            if (t_strSize > t_count * t_size)
                t_count++;

            for (size_t i = 0; i < fileLength(); i += t_size) {
                m_lineOfString.push_back(m_lines.substr(i, t_size));
            }
        }
        else
            throw FileParserException{ "Error in parseWithSize()" };

    }
    void FileParser::parseFile(const std::string& t_extensionName) {
        if (isOpen() && m_lineOfString.size() > 0) {
            for (int i = 0; i < m_lineOfString.size(); i++) {
                std::string iter = std::to_string(i);
                std::string t_extName = "parsedFiles/par" + iter + '.' + t_extensionName;
                m_ofs.open(t_extName, std::ios::out);
                m_ofs.write(m_lineOfString[i].c_str(), m_lineOfString[i].size());
                m_ofs.close();
                }
        }
        else
            throw FileParserException{ "Error in parseFile()" };
    }
    std::vector<std::string> FileParser::parseWithDelimiter(char t_delim) {
        split(t_delim);
        return m_lineOfString;
    }
    size_t FileParser::stringSize() const{
        return m_lines.size();
    }
}