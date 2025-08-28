#include <stdio.h>
#include <ctype.h>

#include "system\tools\tools.h"


void PrintMeow() {
    PrintColor("meow!\n", Blue);

}

void PrintGitMeow() {
    printf(BLUE "meowmeowmeowmeow" BLACK "WWW" GREEN "GIT" BLACK "WWW" GREEN "COMMIT" BLACK "WWW" RED "MEOOOOOOOOOOOOOOW" BLACK "WWW" BLUE "meowmeowmeowmeow\n" RESET
           BLUE "meowmeowmeowmeow" BLACK "WWW" GREEN "GIT" BLACK "WWW" GREEN "PUSH" BLACK "WWW" RED "MEOOOOOOOOOOOOOOOOW" BLACK "WWW" BLUE "meowmeowmeowmeow\n" RESET
           BLUE "meowmeowmeowmeow" BLACK "WWW" GREEN "LEAVE" BLACK "WWW" GREEN "BUILDING" BLACK "WWW" RED "MEOOOOOOOOOOW" BLACK "WWW" BLUE "meowmeowmeowmeow\n" RESET);
}

void ClearBuffer() {
    while(true) {
        int p = 0;
        p = getc(stdin);
        if (p == '\n' || p == EOF) {
            break;
        }
    }
}

bool CheckBuffer(FILE* input) {
    bool isvalid = true;
    int p = getc(input);
    while (p != EOF && p != '\n') {
        p = getc(input);
        if (!isspace(p)) {
            isvalid = false;
        }
    }
    return isvalid;
}

void PrintError(Errors err) {
    switch (err) {
        case TypingError:
            PrintColor("Typing Error\n", Red);
            break;
        case UnexpectedError:
            PrintColor("Unexpected Error\n", Red);
            break;
        case FileNameError:
            PrintColor("Wrong file name\n", Red);
            break;
        case FileDataError:
            PrintColor("Wrong file data\n", Red);
            break;
        case FlagError:
            PrintColor("Wrong flag\n", Red);
            break;
        case TooManyFlagsError:
            PrintColor("Too many flags\n", Red);
            break;
        case Ok:
        default:
            PrintColor("Ok\n", Green);
    }
}

void PrintColor(const char* text, Color color) {
    printf("\033[%dm%s\033[0m", color, text);
}

