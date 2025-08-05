#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "interactive.h"
#include "utils.h"
#include "presets.h"
#include "config_writer.h"

void interactive_mode(void)
{
    char game[64];
    char preset[64];
    char format[64];
    char path[256];

    printf("   _____                            ______             _               _____             __ _        _____            \n");
    printf("  / ____|                          |  ____|           (_)             / ____|           / _(_)      / ____|           \n");
    printf(" | (___   ___  _   _ _ __ ___ ___  | |__   _ __   __ _ _ _ __   ___  | |     ___  _ __ | |_ _  __ _| |  __  ___ _ __  \n");
    printf("  \\___ \\ / _ \\| | | | '__/ __/ _ \\ |  __| | '_ \\ / _` | | '_ \\ / _ \\ | |    / _ \\| '_ \\|  _| |/ _` | | |_ |/ _ \\ '_ \\ \n");
    printf("  ____) | (_) | |_| | | | (_|  __/ | |____| | | | (_| | | | | |  __/ | |___| (_) | | | | | | | (_| | |__| |  __/ | | |\n");
    printf(" |_____/ \\___/ \\__,_|_|  \\___\\___| |______|_| |_|\\__, |_|_| |_|\\___|  \\_____|\\___/|_| |_|_| |_|\\__, |\\_____|\\___|_| |_|\n");
    printf("                                                  __/ |                                        __/ |                  \n");
    printf("                                                 |___/                                        |___/                   \n");

    get_input(game, sizeof(game), "Enter the game (hl2, CSS, TF2): ");
    get_input(preset, sizeof(preset), "Choose preset (low, medium, high, ultra): ");
    get_input(format, sizeof(format), "Output format (cfg, ini, json): ");
    get_input(path, sizeof(path), "Path to game cfg folder (e.g. C:\\Games\\HL2\\cfg): ");

    if (strcmp(format, "cfg") != 0 && strcmp(format, "json") != 0) {
        printf("Only .cfg and .json are supported. Defaulting to cfg.\n");
        strcpy(format, "cfg");
    }

    Config cfg;
    if (load_preset(preset, &cfg) != 0) {
        printf("Unknown preset: %s\n", preset);
        return;
    }

    const char *temp_file = "hl2_tuner.tmp";
    if (write_config_to_file(temp_file, &cfg, format) != 0) {
        printf("Failed to write config.\n");
        return;
    }

    char full_path[512];
    snprintf(full_path, sizeof(full_path), "%s\\autoexec.%s", path, format);

    remove(full_path);
    if (rename(temp_file, full_path) != 0) {
        perror("Failed to move config");
        return;
    }

    printf("✅ Config for '%s' written to: %s\n", game, full_path);
}
