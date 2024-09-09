#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main() {
    char file_data[65536];
    FILE* file_ptr = fopen("data.txt", "r");
    uint32_t file_size = fread(file_data, sizeof(char), sizeof(file_data), file_ptr);
    file_data[file_size] = '\0';
    fclose(file_ptr);

    uint_fast32_t bf_ap = 0;
    uint_fast32_t bf_ip = 0;
    uint_fast32_t bf_mem[(1 << 16)];
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
                uint_fast32_t nest = 1;
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
            uint_fast32_t nest = 1;
            while (nest) {
                bf_ip--;
                if (file_data[bf_ip] == '[') {
                    nest--;
                }
                if (file_data[bf_ip] == ']') {
                    nest++;
                }
            }
        } else if (file_data[bf_ip] == '.') {
            putchar(bf_mem[bf_ap]);
        } else if (file_data[bf_ip] == ',') {
            bf_mem[bf_ap] = getchar();
        }
        bf_ip++;
    }
}