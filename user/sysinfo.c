#include "kernel/types.h"
#include "kernel/sysinfo.h"
#include "user/user.h"

void
sinfo(struct sysinfo *info) {
    if (sysinfo(info) < 0) {
        printf("FAIL: sysinfo failed");
        exit(0);
    } else {
        printf("Number of bytes of free memory: %d\n", info->freemem);
        printf("Number of used processes: %d\n", info->nproc);
    }
}

int
main(int argc, char *argv[])
{
    struct sysinfo s;
    sinfo(&s);
    exit(0);
}