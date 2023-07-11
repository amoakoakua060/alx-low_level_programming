#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void validate_elf(Elf64_Ehdr *fh);
void print_magic(Elf64_Ehdr *fh);
void print_class(Elf64_Ehdr *fh);
void print_data(Elf64_Ehdr *fh);
void print_version(Elf64_Ehdr *fh);
void print_osabi(Elf64_Ehdr *fh);
void print_abiversion(Elf64_Ehdr *fh);
void print_type(Elf64_Ehdr *fh);
void print_entry(Elf64_Ehdr *fh);
void close_elf(int elf);

#endif /* MAIN_H */
