#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define bfsize (1 << 14)
#define bfint uint32_t
#define bfalign 4

enum bfinst_kind {
    bfinst_kind_nop,
};
struct bfinst{
    enum bfinst_kind inst;
    bfint val;
};

int main() {
    clock_t clock_start = clock();

    bfint bf_ap = 0;
    bfint bf_ip = 0;
    bfint nest = 1;

    __attribute__((aligned(bfalign))) char file_data[bfsize];
    __attribute__((aligned(bfalign))) char bf_mem[bfsize];

    FILE* file_ptr = fopen("data.txt", "r");
    bfint file_size = fread(file_data, sizeof(char), sizeof(file_data), file_ptr);
    file_data[file_size] = '\0';
    fclose(file_ptr);

    memset(bf_mem, 0, sizeof(bf_mem));
    while (1) {
        if (file_data[bf_ip] == '>') {
            bf_ap++;
        } else if (file_data[bf_ip] == '<') {
            bf_ap--;
        } else if (file_data[bf_ip] == '+') {
            bf_mem[bf_ap]++;
        } else if (file_data[bf_ip] == '-') {
            bf_mem[bf_ap]--;
        } else if (file_data[bf_ip] == '[') {
            if (bf_mem[bf_ap] == 0) {
                nest = 1;
                while (nest) {
                    bf_ip++;
                    if (file_data[bf_ip] == '[') {
                        nest++;
                    }
                    if (file_data[bf_ip] == ']') {
                        nest--;
                    }
                }
            }
        } else if (file_data[bf_ip] == ']') {
            nest = 1;
            while (nest) {
                bf_ip--;
                if (file_data[bf_ip] == '[') {
                    nest--;
                }
                if (file_data[bf_ip] == ']') {
                    nest++;
                }
            }
            bf_ip--;
        } else if (file_data[bf_ip] == '.') {
            putchar(bf_mem[bf_ap]);
        } else if (file_data[bf_ip] == ',') {
            bf_mem[bf_ap] = getchar();
        } else if (file_data[bf_ip] == '\0') {
            break;
        }
        bf_ip++;
    }
    printf("%f\n", (double)(clock() - clock_start) / CLOCKS_PER_SEC);
}