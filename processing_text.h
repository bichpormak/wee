#ifndef PROCESSING_TEXT_H
#define PROCESSING_TEXT_H

#include <wchar.h>
#include <stdlib.h>
#include <wctype.h>
#include <stdio.h>
#include "struct.h"

#define ADDITIONAL_DATA 100

struct Word* processWordsFromText(struct Text* text);
struct Sentence* inputSentence();
struct Text* inputText();
void print_text(struct Text* text);

#endif