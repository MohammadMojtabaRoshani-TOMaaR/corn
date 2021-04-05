GPPPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = loader.o kernel.o

%.o: %.cxx
		g++ $(GPPPARAMS) -o $@ -c $<

%.o: %.s
		as $(ASPARAMS) -o $@ $<

kernel.bin: linker.ld $(objects)
		ld $(LDPARAMS) -T $< -o $@ $(objects)

install: kernel.bin
		sudo cp $< /boot/kernel.bin

corn_x86-0.iso: kernel.bin
		mkdir iso
		mkdir iso/boot
		mkdir iso/boot/grub
		cp $< iso/boot/
		echo 'set timeout=3' >> iso/boot/grub/grub.cfg
		echo 'set default=0' >> iso/boot/grub/grub.cfg
		echo 'menuentry "corn" {' >> iso/boot/grub/grub.cfg
		echo '	multiboot /boot/kernel.bin' >> iso/boot/grub/grub.cfg
		echo '	boot' >> iso/boot/grub/grub.cfg
		echo '}' >> iso/boot/grub/grub.cfg
		grub-mkrescue --output=$@ iso
		rm -rf iso

run86: corn_x86-0.iso
		(killall VirtualBoxVM && sleep 1) || true
		vboxmanage startvm "cornx86" &