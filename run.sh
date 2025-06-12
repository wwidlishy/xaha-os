nasm -f elf32 boot/boot.s -o build/boot.o

for file in kernel/*.c; do
  if [[ -f "$file" ]]; then
    gcc -m32 -c $file -o $file.o -fno-stack-protector -ffreestanding -nostdlib
  fi
done
for file in kernel/*.o; do
  if [[ -f "$file" ]]; then
    mv $file build/
  fi
done

ld -m elf_i386 -T link.ld -o dist/xaha-os.elf build/boot.o $(ls build/*.c.o)
cp dist/xaha-os.elf iso/boot/
grub-mkrescue -o dist/xaha-os.iso iso/

qemu-system-x86_64 dist/xaha-os.iso