#include "repeat_words.h"
#include <string.h>

void repeat_words(struct Word* word)
{
    wchar_t** printedWords = (wchar_t**) malloc(word->cntWord * sizeof(wchar_t*));
    if (printedWords == NULL)
        return;

    int flag = 0;
    for(size_t i = 0; i < word->cntWord; i++)
    {
        int already_printed = 0;
        for(size_t k = 0; k < i; k++)
        {
            if(printedWords[k] && wcscmp(printedWords[k], word->word[i]) == 0)
            {
                already_printed = 1;
                break;
            }
        }

        if(already_printed)
        {
            printedWords[i] = NULL;
            continue;
        }
        printedWords[i] = (wchar_t*) malloc((wcslen(word->word[i]) + 1) * sizeof(wchar_t));
        if (printedWords[i] == NULL)
            break;
        wcscpy(printedWords[i], word->word[i]);

        int cntRepeatWords = 0;

        for(size_t j = i; j < word->cntWord; j++)
        {
            if(wcscmp(word->word[i], word->word[j]) == 0)
                cntRepeatWords++;                
        }

        if (cntRepeatWords >= 3)
        {
            wprintf(L"Слово %ls встретилось %d раз\n", word->word[i], cntRepeatWords);
            flag = 1;
        }
    }

    if (flag == 0)
        wprintf(L"В тексте не обнаружено повторяющихся слов\n"); 
    
    for(size_t i = 0; i < word->cntWord; i++)
    {
        free(printedWords[i]);
    }
    free(printedWords);
}