#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(const char *msg, const char *filename) {
    dprintf(STDERR_FILENO, msg, filename);
    exit(98);
}

void print_elf_header(const Elf64_Ehdr *header) {
    printf("ELF Header:\n");
    printf("  Magic:   %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x\n",
        header->e_ident[EI_MAG0], header->e_ident[EI_MAG1],
        header->e_ident[EI_MAG2], header->e_ident[EI_MAG3],
        header->e_ident[EI_CLASS], header->e_ident[EI_DATA],
        header->e_ident[EI_VERSION], header->e_ident[EI_OSABI]);
    
    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
    }
    
    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
    }
    
    printf("  Version:                           %d (current)\n",
        header->e_ident[EI_VERSION]);
    
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("TRU64 UNIX\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
    }
    
    printf("  ABI Version:                       %d\n",
        header->e_ident[EI_ABIVERSION]);
    
    printf("  Type:                              ");
    switch (header->e_type) {
        case ET_NONE:
            printf("None\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown: %x>\n", header->e_type);
    }
    
    printf("  Entry point address:               0x%lx\n",
        (unsigned long)header->e_entry);
}

int main(int argc, char *argv[]) {
    int fd;
    Elf64_Ehdr header;

    if (argc != 2) {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(97);
    }
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Error: Can't read from file %s\n", argv[1]);
    }
    
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        print_error("Error: Can't read from file %s\n", argv[1]);
    }
    
    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) {
        dprintf(STDERR_FILENO, "Error: Not an ELF file - %s\n", argv[1]);
        close(fd);
        exit(98);
    }
    
    print_elf_header(&header);
    
    if (close(fd) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
    
    return (0);
}
