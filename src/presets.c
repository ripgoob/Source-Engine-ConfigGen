#include <string.h>
#include "presets.h"
#include <stdio.h>

int load_preset(const char *preset_name, Config *config) {
    if (strcmp(preset_name, "low") == 0) {
        config->fps_max        = 60;
        config->mat_queue_mode = 0;
        config->cl_showfps     = 0;
        config->rezX           =1220;
        config->rezY           =720;
    }
    else if (strcmp(preset_name, "medium") == 0) {
        config->fps_max        = 120;
        config->mat_queue_mode = 1;
        config->cl_showfps     = 1;
        config->rezX           =1600;
        config->rezY           =900;
    }
    else if (strcmp(preset_name, "high") == 0) {
        config->fps_max        = 240;
        config->mat_queue_mode = 2;
        config->cl_showfps     = 1;
        config->rezX           =1920;
        config->rezY           =1080;
    }
    else if (strcmp(preset_name, "UltraHigh") == 0){
        config->fps_max        = 480;
        config->mat_queue_mode = 2;
        config->cl_showfps     = 1;
        config->rezX           =2560;
        config->rezY           =1440;
    }
    else {
        return 1;  // unknown preset
    }
    return 0;
}


void list_presets(void) {
    printf("Available presets:\n");
    printf("  low        - 720p / 60 FPS\n");
    printf("  medium     - 900p / 120 FPS\n");
    printf("  high       - 1080p / 240 FPS\n");
    printf("  UltraHigh  - 1440p / 480 FPS\n");
}
