#include <stdio.h>
#include <string.h>
#include "presets.h"
#include "config_writer.h"
#include "system_info.h"
#include "intereactive.h"


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <preset>\n", argv[0]);
        printf("Or run \"%s --interactive\" for user input mode.\n", argv[0]);
        printf("Or run \"%s --list\" to see available presets.\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "--interactive") == 0) {
        interactive_mode();
        return 0;
    }

    if (strcmp(argv[1], "--list") == 0) {
        list_presets();
        return 0;
    }

    Config cfg;
    if (load_preset(argv[1], &cfg) != 0) {
        fprintf(stderr, "Unknown preset: %s\n", argv[1]);
        printf("Use \"%s --list\" to see available presets.\n", argv[0]);
        return 1;
    }

    if (write_config("hl2_tuner.cfg", &cfg) != 0) {
        fprintf(stderr, "Failed to write config.\n");
        return 1;
    }
    printf("Preset '%s' written to hl2_tuner.cfg\n", argv[1]);

    return 0;
}
