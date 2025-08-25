#include <stdio.h>
#include "system\tools\tools.h"




void ClearBuffer() {
    while(true) {
        char p = 0;
        p = getchar();
        if (p == '\n' || p == EOF) {
            break;
        }
    }
}

bool CheckBuffer() {
    while(true) {
        char p = getchar();
        switch (p) {
            case ' ':
                break;
            case '\n':
                return true;
            case EOF:
                return true;
            default:
                return false;
        }
    }
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
        default:
            PrintColor("Ok\n", Green);
    }
}

void PrintColor(const char* text, Color color) {
    printf("\033[%dm%s\033[0m", color, text);
}
