#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <elf.h>
#include <sys/mman.h>

#include "encrypt.h"

static char *key = NULL;
static int key_len = 0;

int get_file_size (int fd){
    struct stat _info;
    fstat (fd, &_info);
    return _info.st_size;
}

int open_file (char *fname){
    int fd;
  
    if ((fd = open (fname, O_APPEND | O_RDWR, 0)) < 0){
        perror ("open:");
        exit (1);
    }

    return fd;  
}

void *map_elf(int fd){
    int size;
    void *data;
  
    size = get_file_size (fd);
    if ((data = mmap (0, size, PROT_READ| PROT_WRITE| PROT_EXEC,
                      MAP_SHARED, fd, 0)) == MAP_FAILED){
        perror ("mmap:");
        exit (1);
    }

    return data;
}

Elf64_Shdr *find_section (void *data, char *name){
    int i;
    char *sname;
    Elf64_Ehdr* elf_hdr = (Elf64_Ehdr *) data;
    Elf64_Shdr *shdr = (Elf64_Shdr *)(data + elf_hdr->e_shoff);
    Elf64_Shdr *sh_strtab = &shdr[elf_hdr->e_shstrndx];
    const char *const sh_strtab_p = data + sh_strtab->sh_offset;

    for (i = 0; i < elf_hdr->e_shnum; i++){
        sname = (char*) (sh_strtab_p + shdr[i].sh_name);
        if (!strcmp (sname, name))  return &shdr[i];
    }

    return NULL;
}

void xor_mem(unsigned char *text, int size){
    for (int i = 0; i < size; i++)
        *(text+i) ^= *(key + (i % key_len));
}

void xor_section(void *data, Elf64_Shdr *sec){
    unsigned char *text = (unsigned char*)data;
    text += sec->sh_offset;
    xor_mem (text, sec->sh_size);
}

void encrypt (char *sname, char *fname){
    int fd;
    void *data;
    Elf64_Shdr* sec;

    if (!key){
        fprintf(stderr, "No key set...Aborting\n");
        exit (1);
    }

    fd = open_file(fname);
    data = map_elf(fd);
    sec = find_section(data, sname);
    xor_section(data, sec);
    close(fd);
}

void decrypt_mem(unsigned char *ptr, unsigned char *ptr1){
    int prot = PROT_READ | PROT_WRITE | PROT_EXEC;
    size_t pagesize = sysconf(_SC_PAGESIZE);
    uintptr_t pagestart = (uintptr_t)ptr & -pagesize;

    int psize = ptr1 - (unsigned char*)pagestart;

    if (!key)
        exit(-1);

    if (mprotect((void*)pagestart, psize, prot) < 0)
        perror("mprotect:");
  
    xor_mem(ptr, ptr1 - ptr);
}

void set_key (char *str){
    if (!key)
        free(key);
    key = strdup(str);
    key_len = strlen(str);
}

void erase_key(void){
    memset(key, 0, key_len);
    free(key);
    key = NULL;
}
