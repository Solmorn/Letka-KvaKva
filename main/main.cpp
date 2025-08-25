#include <stdio.h>

#include "mode\mode.h"

int main(const int argc, const char* const argv[]) {
    Mode mode = NormalMode;
    WhichMode(&mode, argc, argv);
    StartMode(mode);
    return 0;
}
