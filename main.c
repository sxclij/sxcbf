#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <stdint.h>
#include <stdio.h>

int main() {
    char file_data[65536];
    uint32_t file_size;
    FILE* file_ptr;

    file_ptr = fopen("data.txt", "r");
    file_size = fread(file_data, sizeof(char), sizeof(file_data), file_ptr);
    file_data[file_size] = '\0';

    puts(file_data);
}