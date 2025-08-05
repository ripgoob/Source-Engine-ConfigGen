#ifndef CONFIG_WRITER_H
#define CONFIG_WRITER_H

#include "presets.h"

int write_config(const char *filename, const Config *cfg);
int write_config_to_file(const char *filename, const Config *cfg, const char *format);

#endif
