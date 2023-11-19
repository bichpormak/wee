#include "repeat_numbers.h"

void repeat_numbers(struct Text* text)
{
    size_t cnt[MAX_NUM] = {0};

    for (size_t i = 0; i < text->cntSentence; i++)
    {
        for (size_t j = 0; j < wcslen(text->text[i]); j++)
        {
            wchar_t ch = text->text[i][j];
            if (iswdigit(ch))
                cnt[ch - L'0']++;
        }
    }

    for (size_t i = 0; i < text->cntSentence; i++)
    {
        for (size_t j = 0; j < wcslen(text->text[i]); j++)
        {
            wchar_t ch = text->text[i][j];
            if (iswdigit(ch))
                wprintf(L"%lu", cnt[ch - L'0']);
                
            else
                wprintf(L"%lc", ch);
        }
        wprintf(L"\n");
    }
    wprintf(L"\n");

    for(size_t i = 0; i < text->cntSentence; i++)
    {
        free(text->text[i]);
    }
    free(text);
}