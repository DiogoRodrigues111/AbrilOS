#assemble bootloader.s file
as --32 bootloader.s -o bootloader.o

#compile kernel.c file
#-m32
#gcc-9 -m32 -c ../kernel/kmain.c -o kernel.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
gcc-9 -m32 -c ../kernel/utils/utils.c -o utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
gcc-9 -m32 -c ../kernel/kernel_entry.c -o kernel.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
gcc-9 -m32 -c ../user32/usr32.c -o user32.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

#linking the kernel with kernel.o and boot.o files
#ld -m elf_i386 -T linker.ld utils.o kernel.o bootloader.o -o AbrilOS.bin -nostdlib
#i386:x86-64
#elf_x86_64
ld -m elf_i386 -T linker.ld utils.o kernel.o bootloader.o -o AbrilOS.bin

#check MyOS.bin file is x86 multiboot file or not
#grub-file --is-x86-multiboot AbrilOS.bin
grub-file AbrilOS.bin

#UEFI Boot
#grub-mkstandalone -O x86_64-efi -o BOOTX64.EFI "isodir/boot/grub/grub.cfg=build/grub.cfg"

#building the iso file
mkdir -p isodir/boot/grub
cp AbrilOS.bin isodir/boot/AbrilOS.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o AbrilOS.iso isodir

#run it in qemu
#qemu-system-x86_64 -cdrom AbrilOS.iso
qemu-system-x86_64 -cdrom AbrilOS.iso -cpu host -enable-kvm -m 2048 -smp 2
