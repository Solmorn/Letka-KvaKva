#include <stdio.h>
#include <string.h>


#include "mode\mode.h"
#include "math\general_math\general_math.h"
#include "math\square_math\square_math.h"
#include "math\linear_math\linear_math.h"
#include "system\talking\talking.h"




void WhichMode(Mode* mode_adr, const int argc, const char* const argv[]) {
    int flags_size = sizeof(Flags)/sizeof(Flags[0]);
    for (int i = 1; i < argc; i++) {
        int j = 0;
        for (int j = 0; j < flags_size; j++) {
            if (strncmp(argv[i], Flags[j].flag_name_long, MAX_LEN) == 0 ||
               strncmp(argv[i], Flags[j].flag_name_short, MAX_LEN) == 0) {

                *mode_adr = Flags[j].flag_mode;
                return;

            }


        }
    }
}

void StartTestMode() {
    CompareWithZeroTest();
    RootsOfSquareTest();
    HowManySolutionsTest();
    IsLinearTest();
    RootsOfLinearTest();
    DiscriminantTest();
}



void StartHelpMode() {
    printf("    /\\___/\\\n"
           "   /  o o  \\\n"
           "  ( == ^ == )\n"
           "   )       (\n"
           "  (         )\n"
           " ( (  ) (  ) )\n"
           "(__(__)_(__)__)\n");
    int flags_size = sizeof(Flags)/sizeof(Flags[0]);
    for (int i = 0; i < flags_size; i++) {
        printf(YELLOW "Flag long name: " RESET "%s\n" YELLOW
                      "Flag short name: " RESET "%s\n" YELLOW
                      "Description: " RESET "%s\n\n", Flags[i].flag_name_long,
                                                      Flags[i].flag_name_short,
                                                      Flags[i].flag_description);

    }

}

void StartInteractiveMode(Mode mode) {
    char filename[MAX_LEN] = "";
    EquationParams eq;
    Errors err;
    while (true) {
        if (mode == NormalMode) {
            Greeting(&eq.a, &eq.b, &eq.c);
        } else {
            FileGreeting(&eq.a, &eq.b, &eq.c, filename);
        }
        Solver(&eq);
        if (AskUser()) {
            continue;
        } else {
            break;
        }
    }
}

void StartMode(Mode mode) {
    switch (mode) {
        case TestMode:
            StartTestMode();
            break;
        case HelpMode:
            StartHelpMode();
            break;
        default:
            StartInteractiveMode(mode);
    }
}
