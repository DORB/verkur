#include "utilities.h"

namespace utils {
    string str2upper(string str)
    {
        transform(str.begin(), str.end(), str.begin(),::toupper);

        return str;
    }

    string str2lower(string str)
    {
        transform(str.begin(), str.end(), str.begin(),::tolower);

        return str;
    }

    string int2str(const int& a)
    {
        stringstream ss;
        ss << a;
        string str;
        ss >> str;

        return str;
    }
}
