#ifndef CONFIG_WRITER_H
#define CONFIG_WRITER_H

#include "presets.h"

int write_config(const char *filename, const Config *cfg);  // Writes default config
int append_config_line(const char *filename, const char *line);  // Optional

#endif
