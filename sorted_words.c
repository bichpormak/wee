#include "sorted_words.h"

int countLatinLetters(wchar_t* word) {
    int cnt = 0;
    for (size_t j = 0; word[j] != '\0'; j++) {
        if ((word[j]>=65 && word[j] <= 90) || (word[j] >= 97 && word[j] <= 122)) {
            cnt++; 
        }
    }
    return cnt;
}

void sorted_words(struct Word* word) {
    for (size_t i = 0; i < word->cntWord-1; i++) {
        for (size_t j = i+1; j < word->cntWord; j++) {
            if (countLatinLetters(word->word[i]) < countLatinLetters(word->word[j])) {
                wchar_t* temp = word->word[i];
                word->word[i] = word->word[j];
                word->word[j] = temp;
            }
        }
    }

    for (size_t i = 0; i < word->cntWord; i++)
    {
        if (i < word->cntWord - 1) {
            wprintf(L"%ls ", word->word[i]);
        } else {
            wprintf(L"%ls", word->word[i]);
        }
    }
    wprintf(L".");
}
