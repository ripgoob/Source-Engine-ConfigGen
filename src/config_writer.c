#include <stdio.h>
#include <string.h>
#include "presets.h"
#include "formats/json_writer.h"
#include "config_writer.h"
#include "ini_writer.h"
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
int write_config_to_file(const char *filename, const Config *cfg, const char *format) {
    if (strcmp(format, "cfg") == 0) {
        return write_config(filename, cfg);
    } else if (strcmp(format, "json") == 0) {
        return write_json(filename, cfg);
    }else if(strcmp(format,"ini")==0){
        return write_ini(filename,cfg);
    }else {
        fprintf(stderr, "Unknown output format: %s\n", format);
        return 1;
    }
}
