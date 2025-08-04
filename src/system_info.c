

#include <stdio.h>
#include <windows.h>
#include "system_info.h"

void print_system_info(void) {
    SYSTEM_INFO si;
    GetSystemInfo(&si);

    printf("[sysinfo] CPU Architecture: ");
    switch (si.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:
            printf("x64 (AMD or Intel)\n");
            break;
        case PROCESSOR_ARCHITECTURE_ARM:
            printf("ARM\n");
            break;
        case PROCESSOR_ARCHITECTURE_IA64:
            printf("Intel Itanium-based\n");
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            printf("x86\n");
            break;
        default:
            printf("Unknown architecture\n");
    }

    printf("[sysinfo] Number of Cores: %lu\n", si.dwNumberOfProcessors);

    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(mem);
    if (GlobalMemoryStatusEx(&mem)) {
        printf("[sysinfo] Total RAM: %llu MB\n", mem.ullTotalPhys / (1024 * 1024));
    } else {
        printf("[sysinfo] Could not determine RAM.\n");
    }
}
