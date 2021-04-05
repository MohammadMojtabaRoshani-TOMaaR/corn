#   Kernel make commands
- ###### On linux 5.9.16-1-MANJARO
    -   make kernel.o
        -   make **kernel.o** object file

    -   make loader.o
        -   make **loader.o** object file

    -   kernel.bin
        -   link *kernel.o* with *loader.o* by [ld](https://man7.org/linux/man-pages/man1/ld.1.html) command to make single executable **.bin** file

    -   make install
        -   copy **kernel.bin** file to the */boot* directory and can be boot on user machine after update **grub.cfg** at */boot/grub*

    -   make corn_x86-x.iso
        -   make **.iso** of *x version*  of *kernel.bin* named like **corn_x86-x.iso**
        -   image *grub.cfg* will create in this step

    -   make run86
        -   you MUST create virtual machine named **cornX86** in *VirtualBox* first then this make command will...


___
<div>
<div align="center">
  <img src="https://www.gnu.org/graphics/gplv3-127x51.png" width="85" title="hover text">
</div>
</div>