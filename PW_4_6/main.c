#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char hostname[256];
    struct utsname sys_info;

    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Name of computer network: %s\n", hostname);
    } else {
        perror("computer network error");
    }

    if (uname(&sys_info) == 0) {
        printf("System: %s\n", sys_info.sysname);
        printf("Node name: %s\n", sys_info.nodename);
        printf("Release: %s\n", sys_info.release);
        printf("Version: %s\n", sys_info.version);
        printf("Machine: %s\n", sys_info.machine);

#ifdef _GNU_SOURCE
        printf("Ідентифікатор будівництва: %s\n", sys_info.domainname); // Ідентифікатор домену NIS
#endif
    } else {
        perror("Information error");
    }

    return 0;
}
