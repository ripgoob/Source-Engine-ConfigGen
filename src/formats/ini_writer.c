#include <stdio.h>
#include "ini_writer.h"

int write_ini(const char *filename, const Config *cfg) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for INI output");
        return 1;
    }

    fprintf(file, "[Graphics]\n");
    fprintf(file, "fps_max = %d\n", cfg->fps_max);
    fprintf(file, "mat_queue_mode = %d\n", cfg->mat_queue_mode);
    fprintf(file, "cl_showfps = %d\n", cfg->cl_showfps);
    fprintf(file, "\n[Resolution]\n");
    fprintf(file, "rezX = %d\n", cfg->rezX);
    fprintf(file, "rezY = %d\n", cfg->rezY);

    fclose(file);
    return 0;
}
