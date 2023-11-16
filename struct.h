#ifndef STRUCT_H
#define STRUCT_H

#include <wchar.h>


struct Sentence
{
    wchar_t* sentence;
    int lenStr;
    wchar_t** word;
    int cntWord;
};

struct Text
{
    wchar_t** text;
    int cntSentence;
};



#endif