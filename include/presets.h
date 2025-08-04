#ifndef PRESETS_H
#define PRESETS_H

typedef struct {
    int fps_max;
    int mat_queue_mode;
    int cl_showfps;
    int rezX;
    int rezY;
} Config;

// Loads a preset by name (e.g. "low", "high")
// Returns 0 on success, 1 if preset name is invalid
int load_preset(const char *name, Config *config);
void list_presets(void);

#endif
