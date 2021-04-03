#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
*   THIS IS UMASK APPLET.
*   To calculate pass permissions for:
*   FILES:  [ octal 666 (110 110 110) - umask_out_put ] 
*   DIRECTORYIES:   [ octal 777 (111 111 111) - umask_out_put ]
*/

int main()
{
    mode_t old_mask = umask(0);
    umask(old_mask);
    printf("%03o\n", old_mask);
    return 0;
}