#include "sorted_sentence.h"

int countLetters(wchar_t* word, int flag)
{
    int cnt = 0;

    if (flag == 0) 
    {
        for (size_t j = 0; word[j] != L'\0'; j++)
        {
            if ((word[j] >= L'A' && word[j] <= L'Z') || (word[j] >= L'a' && word[j] <= L'z'))
                cnt++; 
        }
    }

    if (flag == 1) 
    {
        for (size_t j = 0; word[j] != L'\0'; j++)
        {
            if ((word[j] >= L'А' && word[j] <= L'Я') || (word[j] >= L'а' && word[j] <= L'я'))
                cnt++; 
        }
    }

    return cnt;
}

void sorted_sentence(struct Text* text, int flag)
{
    for (size_t i = 0; i < text->cntSentence; i++)
    {
        struct Word* my_word = processWordsFromText(text);

        if (flag == 0)
        {
            for (size_t i = 0; i < my_word->cntWord - 1; i++)
            {
                for (size_t k = i + 1; k < my_word->cntWord; k++)
                {
                    if (countLetters(my_word->word[i], flag) < countLetters(my_word->word[k], flag))
                    {
                        wchar_t* temp = my_word->word[i];
                        my_word->word[i] = my_word->word[k];
                        my_word->word[k] = temp;
                    }
                }
            }
        }

        int fl = 1;
        if (flag == 1)
        {
            for(size_t j = 0; j < my_word->cntWord; j++)
            {
                if (countLetters(my_word->word[j], flag) == wcslen(my_word->word[j]))
                    continue;
                else
                {
                    fl = 0;
                    break;
                }
            }
            if (fl == 1)
            {
                for (size_t j = 0, k = my_word->cntWord-1; j < my_word->cntWord/2; j++, k--)
                {
                    wchar_t* temp = my_word->word[j];
                    my_word->word[j] = my_word->word[k];
                    my_word->word[k] = temp;
                }
            }
        }
        

        wchar_t* sorted_sentence = (wchar_t*) malloc(sizeof(wchar_t) * ADDITIONAL_DATA);
        sorted_sentence[0] = '\0';
        for (size_t i = 0; i < my_word->cntWord; i++)
        {
            wcscat(sorted_sentence, my_word->word[i]);
            if (i < my_word->cntWord - 1)
            {
                wcscat(sorted_sentence, L" ");
            }
        }
        
        free(text->text[i]);
        text->text[i] = sorted_sentence;
        wprintf(L"%ls.\n", sorted_sentence);
        
        for(size_t j = 0; j < my_word->cntWord; j++)
        {
            free(my_word->word[j]);
        }
        free(my_word->word);
        free(my_word);
    }

}