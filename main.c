#include <locale.h>
#include "processing_text.h"
#include "repeat_words.h"

#define CREATOR_NAME "Pankratov Lev"
#define VERSION "5.17"

#define COLOR_RED       "\033[4;31m"
#define COLOR_WHITE     "\033[1;37m"
#define COLOR_BLUE      "\033[1;36m"
#define COLOR_GREEN     "\033[1;32m"
#define COLOR_YELLOW    "\033[1;33m"

#define INVALID_OPERATION_ERROR     L""COLOR_RED"Error: "COLOR_WHITE"вы ввели неправильную операцию. Программа завершена\n"
#define MEMORY_ALLOCATION_ERROR     L""COLOR_RED"Error: "COLOR_WHITE"ошибка выделения памяти\n"

int main()
{
    setlocale(LC_CTYPE, "");
    wprintf(L"Course work for option "VERSION", created by "CREATOR_NAME".\n");
    
    wprintf(L"Введите номер операции: ");
    int choiceOperation;
    if (wscanf(L"%d", &choiceOperation) == 1)
    {
        //struct Text* text = inputText();
        
        //if (text == NULL)
            //wprintf(MEMORY_ALLOCATION_ERROR);

        switch (choiceOperation)
        {
            case 0:
                print_text(inputText());
                break;
            case 1:
                repeat_words(inputSentence());
                break;
            case 2:
                break;
            case 3:
                break;

            case 4:
                break;
            case 5:
                break;
            default: 
                wprintf(INVALID_OPERATION_ERROR);
        }
    }
    else wprintf(INVALID_OPERATION_ERROR);
    return 0;
}