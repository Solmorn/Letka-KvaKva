#include <stdio.h>
#include <ctype.h>
#include "system\tools\tools.h"




void ClearBuffer() {
    while(true) {
        int p = 0;
        p = getchar();
        if (p == '\n' || p == EOF) {
            break;
        }
    }
}


bool CheckBuffer() {
    bool isvalid = true;
    int p = getchar();
    while (p != EOF && p != '\n') {
        p = getchar();
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
        case Ok:
            PrintColor("Ok\n", Green);
            break;
        default:
            PrintColor("Ok\n", Green);
    }
}

void PrintColor(const char* text, Color color) {
    printf("\033[%dm%s\033[0m", color, text);
}
