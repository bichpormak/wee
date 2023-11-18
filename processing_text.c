#include "processing_text.h"


struct Word* processWordsFromText(struct Text* text)
{
    if (!text || !text->cntSentence || !text->text) return NULL; 

    struct Word* my_word = (struct Word*) malloc (sizeof(struct Word));
    if (!my_word) return NULL; 

    my_word->word = NULL;
	my_word->cntWord = 0;
    
    my_word->word = (wchar_t**) malloc(sizeof(wchar_t*) * ADDITIONAL_DATA);
    if (my_word->word == NULL)
    {
        free(my_word);
        return NULL;
    }
    for (size_t i = 0; i < text->cntSentence; i++)
    {
        int cntWord = 0;
        wchar_t *token;
        wchar_t *rest = wcsdup(text->text[i]);
        int capasity = ADDITIONAL_DATA;
        while ((token = wcstok(rest, L" .", &rest)))
        {
            if (my_word->cntWord >= capasity)
            {
                capasity += ADDITIONAL_DATA;
                my_word->word = realloc(my_word->word, sizeof(wchar_t*) * capasity);
                if (my_word->word == NULL)
                {
                    free(my_word);
                    return NULL;
                }
            }
            my_word->word[my_word->cntWord] = wcsdup(token);

            if (my_word->word[my_word->cntWord] == NULL)
            {
                for(int j = 0; j < my_word->cntWord; j++)
                    free(my_word->word[j]);
                free(my_word->word);
                free(my_word);
                return NULL;
            }
            cntWord++;
            my_word->cntWord++;
        }
    }
    return my_word;
}


struct Sentence* inputSentence()
{
    struct Sentence* my_sentence = (struct Sentence*) malloc(sizeof(struct Sentence));
    if (my_sentence == NULL)
        return NULL;
    
    my_sentence->sentence = (wchar_t*) malloc(sizeof(wchar_t)*ADDITIONAL_DATA);    
    if (my_sentence->sentence == NULL)
    {
        free(my_sentence);
        return NULL;
    }
    

    int capasity = ADDITIONAL_DATA;
    wchar_t symbol;
    int idxSymbol = 0;
    int emptyLine = 0;
    while ((symbol = getwc(stdin)) != WEOF)
    {
        if (idxSymbol == 0 && symbol == L'\n')
        {
            emptyLine++;
            if (emptyLine == 2)
                return NULL;
            continue;
        }
        emptyLine = 0;

        if (symbol == '\n')
            continue;


        if (idxSymbol == 0 && iswspace(symbol))
            continue;

        my_sentence->sentence[idxSymbol] = symbol;
        idxSymbol++;
        

        if (symbol == L'.')
            break;
        
        if (idxSymbol == capasity-1)
        {
            capasity += ADDITIONAL_DATA;
            my_sentence->sentence = (wchar_t*) realloc(my_sentence->sentence, sizeof(wchar_t)*capasity);
            if (my_sentence->sentence == NULL)
            {
                free(my_sentence);
                return NULL;
            }
        }
    }
    my_sentence->sentence[idxSymbol] = L'\0';
    my_sentence->lenStr = idxSymbol;
    
    
    return my_sentence;
}


struct Text* inputText()
{
    int capasity = ADDITIONAL_DATA;
    struct Text* my_text = (struct Text*) malloc(sizeof(struct Text));
    if (my_text == NULL)
        return NULL;
    
    my_text->text = (wchar_t**) malloc(sizeof(wchar_t*)*ADDITIONAL_DATA);
    if (my_text->text == NULL)
    {
        free(my_text);
        return NULL;
    }

    int cntSentence = 0;
    int cntWord = 0;
    struct Sentence* my_sentence;
    while((my_sentence = inputSentence()) != NULL)
    {     

        int dublicate_sentence = 0;
        if(cntSentence != 0)   
        {
            for (size_t i = 0; i < cntSentence; i++)
            {
                if (wcscasecmp(my_sentence->sentence, my_text->text[i]) == 0)
                {
                    free(my_sentence->sentence);
                    free(my_sentence);
                    dublicate_sentence = 1;
                    break;
                }
            }
        }

        if (dublicate_sentence == 1)
            continue;

        my_text->text[cntSentence] = my_sentence->sentence;
        cntSentence++;
        free(my_sentence);

        if (cntSentence == capasity)
        {
            capasity += ADDITIONAL_DATA;
            my_text->text = (wchar_t**) realloc(my_text->text, sizeof(wchar_t*)*capasity);
            if (my_text->text == NULL)
            {
                free(my_text);
                return NULL;
            }
        }
    }
    my_text->cntSentence = cntSentence;
    return my_text;
}

void print_text(struct Text* text)
{
    for (size_t i = 0; i < text->cntSentence; i++)
    {
        wprintf(L"%ls\n", text->text[i]);
        free(text->text[i]);
    }
    free(text->text);
    free(text);
}