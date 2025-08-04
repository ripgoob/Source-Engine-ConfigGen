#include "utils.h"

void get_input(char *buffer, size_t size, const char *prompt) {
    printf("%s", prompt);
    if (fgets(buffer, (int)size, stdin)) {
        size_t len = strlen(buffer);
        if (len && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';  // Remove newline
        }
    }
}
