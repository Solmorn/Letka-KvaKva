#ifndef MODE
#define MODE


#include <stdio.h>

#include "system\tools\tools.h"


enum Mode {
    UndefinedMode,
    TestMode,
    FileMode,
    HelpMode,
    NormalMode
};


struct FlagParams {
    const char* flag_name_long;
    const char* flag_name_short;
    const char* flag_description;
    Mode flag_mode = UndefinedMode;

};



static const FlagParams Flags[] = {{"--test", "-t", "Help you to test the program", TestMode},
                                   {"--file", "-f", "Change mode from normal to file input", FileMode},
                                   {"--help", "-h", "Describe flags and show you the cat", HelpMode}};

void Run(Mode mode);
void StartTestMode();
void StartHelpMode();
void StartNormalMode();
void StartFileMode();
Errors CheckMode(Mode* mode_adr, const int argc, const char* const argv[]);



#endif
