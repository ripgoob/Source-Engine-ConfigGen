#include "config_writer.h"
#include <stdio.h>
#include "presets.h"

int write_config(const char *filename, const Config *cfg) {
    FILE *configFile = fopen(filename, "w");
    if (!configFile) { perror("fopen"); return 1; }

    fprintf(configFile, "fps_max %d\n",        cfg->fps_max);
    fprintf(configFile, "mat_queue_mode %d\n", cfg->mat_queue_mode);
    fprintf(configFile, "cl_showfps %d\n",     cfg->cl_showfps);
    fprintf(configFile, "mat_setvideomode %d %d 1\n", cfg->rezX, cfg->rezY);
    fclose(configFile);
    return 0;
}