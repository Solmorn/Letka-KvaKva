#include <stdio.h>

#include "mode\mode.h"
#include "system\tools\tools.h"

int main(const int argc, const char* const argv[]) {
    PrintMeow();
    Mode mode = UndefinedMode;
    Errors err = UnexpectedError;
    err = CheckMode(&mode, argc, argv);
    if (err != Ok) {
        PrintError(err);
    } else {
        Run(mode);
    }
    PrintGitMeow();
    return 0;
}
