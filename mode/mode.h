#ifndef MODE
#define MODE


#include <stdio.h>


enum Mode {
    TestMode,
    FileMode,
    HelpMode,
    NormalMode
};


struct FlagParams {
    const char* flag_name_long;
    const char* flag_name_short;
    const char* flag_description;
    Mode flag_mode = NormalMode;

};



static const FlagParams Flags[] = {{"--test", "-t", "Help you to test the program", TestMode},
                                   {"--file", "-f", "Change mode from normal to file input", FileMode},
                                   {"--help", "-h", "Describe flags and show you the cat", HelpMode}};

void StartMode(Mode mode);
void StartTestMode();
void StartHelpMode();
void StartNormalMode();
void StartFileMode();
void WhichMode(Mode* mode_adr, const int argc, const char* const argv[]);



#endif
