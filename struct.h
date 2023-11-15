#ifndef STRUCT_H
#define STRUCT_H

#include <wchar.h>

struct Sentence
{
    wchar_t* sentence;
    int lenStr;
};

struct Text
{
    wchar_t** text;
    int cntSentence;
};

#endif