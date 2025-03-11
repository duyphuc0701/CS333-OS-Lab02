#include "kernel/types.h"
#include "kernel/sysinfo.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    struct sysinfo s;
    if (sysinfo(&s) < 0) {
        printf("FAIL: sysinfo failed");
        exit(0);
    } else {
        struct sysinfo *info = &s;
        printf("Number of bytes of free memory: %d\n", info->freemem);
        printf("Number of used processes: %d\n", info->nproc);
        printf("Load average in past 1 minute: %d\n", info->load_avg_1_min);
    }
    exit(0);
}