#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

const char *get_file_type(mode_t mode);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat buff;

    if (stat(argv[1], &buff) == -1)
    {
        perror("stat");
        return EXIT_FAILURE;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);
    printf("File Type:            %s\n", get_file_type(buff.st_mode));
    printf("Permissions:          %04o\n", buff.st_mode & 0777);
    printf("File Size:            %ld bytes\n", (long)buff.st_size);
    printf("Hard Links Count:     %lu\n", (unsigned long)buff.st_nlink);
    printf("Owner (UID):          %u\n", buff.st_uid);
    printf("Group (GID):          %u\n", buff.st_gid);
    printf("Last Access Time:     %s", ctime(&buff.st_atime));
    printf("Last Modification:    %s", ctime(&buff.st_mtime));
    printf("Status Change Time:   %s", ctime(&buff.st_ctime));

    return 0;
}

const char *get_file_type(mode_t mode)
{
    if (S_ISREG(mode))
        return "Regular File";
    if (S_ISDIR(mode))
        return "Directory";
    if (S_ISLNK(mode))
        return "Symbolic Link";
    if (S_ISCHR(mode))
        return "Character Device";
    if (S_ISBLK(mode))
        return "Block Device";
    if (S_ISFIFO(mode))
        return "FIFO (Pipe)";
    if (S_ISSOCK(mode))
        return "Socket";

    return "Unknown";
}
