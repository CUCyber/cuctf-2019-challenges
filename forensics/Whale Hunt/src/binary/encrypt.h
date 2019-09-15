#ifndef SSECTION_H
#define SSECTION_H

#include <elf.h>

#define PRIVATE_FUNC __attribute__((section(".private")))
#define PRIVATE_HELPER_FUNC __attribute__((section(".privatehelper")))


#define PUBLIC_HELPER_FUNC __attribute__((section(".publichelper")))

#ifdef __cplusplus
extern "C" {
#endif

  int          get_file_size (int fd);
  void         dump_elf_info (void *data);
  void         dump_mem (unsigned char *ptr, unsigned char *ptr1);

  int          open_file (char *fname);
  void*        map_elf (int fd);
  Elf64_Shdr*  find_section (void *data, char *name);

  void         xor_section (void *data, Elf64_Shdr *sec);
  void         xor_mem (unsigned char *text, int size);
  void         encrypt (char *sname, char *fname);
  void         decrypt (char *fname);
  void         decrypt_mem (unsigned char *ptr, unsigned char *ptr1);
  void         set_key (char *str);

#ifdef __cplusplus
}
#endif

#endif
