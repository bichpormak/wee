#include "repeat_words.h"
#include <string.h>

void repeat_words(struct Sentence* sentence)
{
    wchar_t** printedWords = (wchar_t**) malloc(sentence->cntWord * sizeof(wchar_t*));
    if (printedWords == NULL)
        free(printedWords);

    int flag = 0;
    for(size_t i = 0; i < sentence->cntWord; i++)
    {
        int already_printed = 0;
        for(size_t k = 0; k < i; k++)
        {
            if(printedWords[k] && wcscmp(printedWords[k], sentence->word[i]) == 0)
            {
                already_printed = 1;
                break;
            }
        }

        if(already_printed)
            continue;

        int cntRepeatWords = 0;

        for(size_t j = i; j < sentence->cntWord; j++)
        {
            if(wcscmp(sentence->word[i], sentence->word[j]) == 0)
            {
                cntRepeatWords++;
                
                printedWords[i] = (wchar_t*) malloc((wcslen(sentence->word[i]) + 1) * sizeof(wchar_t));
                if (printedWords[i] == NULL)
                    break;
                printedWords[i] = sentence->word[i];
                
            }
        }

        if (cntRepeatWords >= 3)
        {
            wprintf(L"Слово %ls встретилось %d раз\n", sentence->word[i], cntRepeatWords);
            flag = 1;
        }
    }

    if (flag == 0)
        wprintf(L"В тексте не обнаружено повторяющихся слов\n"); 
    
    for(size_t i = 0; i < sentence->cntWord; i++)
    {
        free(printedWords[i]);
    }
    free(printedWords);
}