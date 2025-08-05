#include <stdio.h>
#include <string.h>
#include "presets.h"
#include "config_writer.h"
#include "system_info.h"
#include "interactive.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <preset> [format]\n", argv[0]);
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

    const char *preset = argv[1];
    const char *format = "cfg";  // Default format

    if (argc >= 3) {
        format = argv[2];
    }

    Config cfg;
    if (load_preset(preset, &cfg) != 0) {
        fprintf(stderr, "Unknown preset: %s\n", preset);
        printf("Use \"%s --list\" to see available presets.\n", argv[0]);
        return 1;
    }

    const char *output_file = "hl2_tuner_output";

    char full_filename[64];
    snprintf(full_filename, sizeof(full_filename), "%s.%s", output_file, format);

    if (write_config_to_file(full_filename, &cfg, format) != 0) {
        fprintf(stderr, "Failed to write config file.\n");
        return 1;
    }

    printf("✅ Config '%s' written to: %s\n", preset, full_filename);
    return 0;
}
