#include <stdio.h>
#include "json_writer.h"

int write_json(const char *filename, const Config *cfg) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for JSON output");
        return 1;
    }

    fprintf(file, "{\n");
    fprintf(file, "  \"fps_max\": %d,\n", cfg->fps_max);
    fprintf(file, "  \"mat_queue_mode\": %d,\n", cfg->mat_queue_mode);
    fprintf(file, "  \"cl_showfps\": %d,\n", cfg->cl_showfps);
    fprintf(file, "  \"resolution\": {\"x\": %d, \"y\": %d}\n", cfg->rezX, cfg->rezY);
    fprintf(file, "}\n");

    fclose(file);
    return 0;
}
