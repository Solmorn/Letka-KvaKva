#include <stdio.h>

#include "system\talking\talking.h"
#include "mode\mode.h"
#include "system\tools\tools.h"

int main(const int argc, const char* const argv[]) {
    PrintMeow();
    Mode mode = UndefinedMode;
    Errors err = UnexpectedError;
    err = CheckMode(&mode, argc, argv);
    if (err != Ok) {
        PrintError(err);
        Run(HelpMode);
    } else {
        err = Run(mode);
        if (err == CriticalError) {
            return 0;
        }
    }
    PrintGitMeow();
    return 0;
}

