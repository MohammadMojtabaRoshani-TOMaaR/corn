#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/*
*   THIS APPLET WILL CREATE COPY OF EXISTING FILE BY [rw-r--r--] PERMISSION.
*   note that this applet just work for LOCAL file and its NOT suitable for NETWORK files.
*/
static const int kWrongArgumentCount = 1;
static const int kSourcefileNonExistent = 2;
static const int kDestinationFileOpenFailure = 4;
static const int kReadFailure = 8;
static const int kWriteFailure = 16;
static const int kDefaultPermission = 0644;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "%s <targer-file> <destination-file>.\n", argv[0]);
        return kWrongArgumentCount;
    }
    int file_descriptor_in = open(argv[1], O_RDONLY);
    int file_descriptor_out = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);

    while (true)
    {
        char buffer[1024];
        ssize_t bytesRead = read(file_descriptor_in, buffer, sizeof(buffer)); //  we got negative values
        if (bytesRead == 0)
            break; //  no more bytes to read
        size_t bytesWritten = 0;
        while (bytesWritten < bytesRead)
        {
            //  make sure to NOT read hole file at once
            bytesWritten += write(file_descriptor_out, buffer + bytesWritten, bytesRead - bytesWritten);
        }
    }

    close(file_descriptor_in);
    close(file_descriptor_out);
    return 0;
}