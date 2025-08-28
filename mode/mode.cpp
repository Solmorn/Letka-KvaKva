#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "math\general_math\general_math.h"
#include "system\talking\talking.h"
#include "mode\mode.h"
#include "math\square_math\square_math.h"
#include "math\linear_math\linear_math.h"
#include "system\tools\tools.h"


static Errors FindFlag(Mode* mode_adr, size_t all_flags_size, const char* current_flag, const bool is_short) {
    assert(mode_adr != nullptr);
    assert(current_flag != nullptr);

    size_t index = 0;
    if (is_short) {
        index = 1;
    }
    for (size_t j = 0; j < all_flags_size; j++) {
        if (strncmp(current_flag, (Flags[j].flag_name)[index], MAX_LEN) == 0) {
            if (*mode_adr == UndefinedMode) {
                *mode_adr = Flags[j].flag_mode;
            } else {
                return TooManyFlagsError;
            }
        }
    }
    return Ok;
}

Errors CheckMode(Mode* mode_adr, const int argc, const char* const argv[]) {
    assert(mode_adr != nullptr);

    Errors err = Ok;
    bool is_short = 0;
    if (argc < 2) {
        *mode_adr = NormalMode;
        return err;
    }
    size_t all_flags_size = sizeof(Flags)/sizeof(Flags[0]);
    for (size_t i = 1; i < argc; i++) {
        const char* current_flag = argv[i];
        size_t one_flag_size = sizeof(current_flag)/sizeof(current_flag[0]);
        if (one_flag_size > 1 && current_flag[0] == '-') {
            if (current_flag[1] == '-') {
                is_short = 0;
                err = FindFlag(mode_adr, all_flags_size, current_flag, is_short);
                if (err != Ok) {
                    return err;
                }
            } else {
                is_short = 1;
                err = FindFlag(mode_adr, all_flags_size, current_flag, is_short);
                if (err != Ok) {
                    return err;
                }
            }
        } else {
            *mode_adr = UndefinedMode;
            return FlagError;
        }
    }
    if (*mode_adr == UndefinedMode) {
        return FlagError;
    } else {
        return Ok;
    }
}

static void StartTestMode() {
    CompareWithZeroTest();
    RootsOfSquareTest();
    HowManySolutionsTest();
    IsLinearTest();
    RootsOfLinearTest();
    DiscriminantTest();
}

static void StartHelpMode() {
    printf("    /\\___/\\\n"
           "   /  " YELLOW "o o" RESET "  \\\n"
           "  ( == ^ == )\n"
           "   )       (\n"
           "  (         )\n"
           " ( (  ) (  ) )\n"
           "(__(__)_(__)__)\n");
    size_t flags_size = sizeof(Flags)/sizeof(Flags[0]);
    for (size_t i = 0; i < flags_size; i++) {
        printf(YELLOW "Flag long name: " RESET "%s\n" YELLOW
                      "Flag short name: " RESET "%s\n" YELLOW
                      "Description: " RESET "%s\n\n", Flags[i].flag_name[0],
                                                      Flags[i].flag_name[1],
                                                      Flags[i].flag_description);
    }

}

static Errors StartNormalMode() {
    EquationParams eq;
    Errors err = Ok;
    while (true) {
        err = Greeting(&eq.a, &eq.b, &eq.c);
        if (err == CriticalError) {
            return err;
        }
        err = Solver(&eq);
        if (err != Ok) {
            PrintError(err);
        } else {
            Errors err = ShowAnswer(&eq);
            if (err != Ok) {
                PrintError(err);
            }
        }
        if (AskUser()) {
            continue;
        } else {
            break;
        }
    }
    return err;
}

static Errors StartFileMode() {
    Errors err = Ok;
    char input_file[MAX_LEN] = "";
    char output_file[MAX_LEN] = "";
    EquationParams eq = {.a = NAN, NAN, NAN, NAN, NAN, ZeroSolutions};
    while (true) {
        err = FileGreeting(&eq, input_file, output_file);
        if (err == CriticalError) {
            return err;
        }
        if (AskUser()) {
            continue;
        } else {
            break;
        }
    }
    return err;
}

Errors Run(Mode mode) {
    Errors err = Ok;
    switch (mode) {
        case TestMode:
            StartTestMode();
            break;
        case HelpMode:
            StartHelpMode();
            break;
        case FileMode:
            err = StartFileMode();
            break;
        case NormalMode:
            err = StartNormalMode();
            break;
        case UndefinedMode:
            PrintError(UnexpectedError);
            break;
        default:
            PrintError(UnexpectedError);
            break;
    }
    return err;
}
