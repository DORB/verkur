#include "utilities.h"

namespace utils {
    std::string str2upper(std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(),toupper);

        return str;
    }

    std::string str2lower(std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(),tolower);

        return str;
    }

    std::string int2str(const int& a)
    {
        std::stringstream ss;
        ss << a;
        std:: string str;
        ss >> str;

        return str;
    }
}
