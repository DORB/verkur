#ifndef UTILITIES_H
#define UTILITIES_H

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

namespace utils {
    string str2upper(string str);
    string str2lower(string str);
    string int2str(const int& a);
    void trimeWS(string& str);
}

#endif // UTILITIES_H
