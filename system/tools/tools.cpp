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
        char p = 0;
        p = getchar();
        switch (p) {
            case ' ':
                break;
            case '\n':
                return true;
            default:
                return false;
        }
    }
}

void PrintError(Errors err) {
    switch (err) {
        case TypingError:
            printf("Typing Error\n");
            break;
        case UnexpectedError:
            printf("Unexpected Error\n");
            break;
        default:
            printf("Ok\n");
    }
}
