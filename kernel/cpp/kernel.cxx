/*
*   THIS IS KERNEL START POINT.
*/

const int __screen_location = 0xb8000;

void printf(char *str)
{
    unsigned short *VideoMemory = (unsigned short *)__screen_location;

    int i = 0;
    for (i; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

extern "C" void kernelMain(void *multiboot_structure, unsigned int magicnumber)
{
    printf("THIS IS THE KERNEL");

    //  make kernel unstopabel
    while (true)
        ;
}