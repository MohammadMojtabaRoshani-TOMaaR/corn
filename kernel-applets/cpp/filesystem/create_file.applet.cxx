#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/*
*   THIS IS FILE CREATOR APPLET.
*/

const char *kFilename = "0FILE0";
const int kFileExistsErr = 17;

int main(int argc, const char **argv)
{
    umask(0);
    int file_descriptor = open(kFilename, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (file_descriptor == -1)
    {
        printf("ERROR OCCURRED IN CREATING '%s'\n", kFilename);
        if (errno == kFileExistsErr)
        {
            printf("THE FILE WITH SPECIFIC NAME ALREADY EXISTS\n");
        }
        else
        {
            printf("GOT THIS ERROR: %d\n", errno);
        }
        return -1;
    }
    close(file_descriptor);
    return 0;
}