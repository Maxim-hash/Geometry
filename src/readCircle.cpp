#include "readCircle.h"
#include <stdio.h>
#include <string.h>

std::vector<std::string> split(std::string str, char spl)
{
    int all_spl = 0;
    int N = str.length();
    std::vector<std::string> str_arr;
    int start_str = 0;
    int end_str = 0;
    for (int i = 0; i < N; i++) {
        if (str[i] == spl)
            all_spl++;
    }
    for (int i = 0; i < all_spl + 1; i++) {
        end_str = 0;
        for (int j = start_str; j < N; j++) {
            end_str++;
            if (str[j] == spl) {
                break;
            }
        }
        if (start_str + end_str == N) {
            str_arr.push_back(str.substr(start_str, end_str));
        } else {
            str_arr.push_back(str.substr(start_str, end_str - 1));
        }
        start_str = start_str + end_str;
    }
    std::vector<std::string> res_str;
    int sizee = str_arr.size();
    int size_st = 0;
    for (int i = 0; i < sizee; i++) {
        size_st = str_arr[i].length();
        char* cstr = new char[size_st + 1];
        strcpy(cstr, str_arr[i].c_str());

        char* p = strtok(cstr, " ");
        while (p != 0) {
            res_str.push_back(p);
            p = strtok(NULL, " ");
        }
    }
    sizee = res_str.size();
    return res_str;
}
