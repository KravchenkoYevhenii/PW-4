#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>

int main() {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);

    if (pw != NULL) {
        printf("Information about user (UID %d):\n", uid);
        printf("User name: %s\n", pw->pw_name);
        printf("Home directory: %s\n", pw->pw_dir);
        printf("Full name: %s\n", pw->pw_gecos);
        printf("Shell path: %s\n", pw->pw_shell);
    } else {
        perror("UID error");
    }

    char *root_username = "root";
    pw = getpwnam(root_username);

    if (pw != NULL) {
        printf("\nInformation about user %s:\n", root_username);
        printf("UID: %d\n", pw->pw_uid);
        printf("Guide: %d\n", pw->pw_gid);
        printf("Home directory: %s\n", pw->pw_dir);
        printf("Name: %s\n", pw->pw_gecos);
        printf("Shell path: %s\n", pw->pw_shell);
    } else {
        perror("Username error");
    }

    return 0;
}
