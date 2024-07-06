#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define mem_capacity (1 << 20)
#define file_capacity (1 << 16)

void file_read(char* dst, const char* path) {
    FILE* file_ptr = fopen(path, "r");
    uint32_t file_size = fread(dst, sizeof(char), file_capacity, file_ptr);
    dst[file_size] = '\0';
}

void exec(char* mem) {
    char* ip = &mem[0];
    char* ap = &mem[file_capacity];
    char* sp = &mem[mem_capacity - 1];
    uint_fast8_t lc = 0;
    while (1) {
        switch (*ip) {
            case '>':
                ap++;
                break;
            case '<':
                ap--;
                break;
            case '+':
                (*ap)++;
                break;
            case '-':
                (*ap)--;
                break;
            case '.':
                putchar(*ap);
                break;
            case ',':
                *ap = getchar();
                break;
            case '[':
                lc = (*ap == 0);
                while (lc) {
                    ip++;
                    lc += (*ip == '[');
                    lc -= (*ip == ']');
                }
                break;
            case ']':
                lc = 1;
                while (lc) {
                    ip--;
                    lc -= (*ip == '[');
                    lc += (*ip == ']');
                }
                ip--;
                break;
            case '\0':
                return;
            default:
                break;
        }
        ip++;
    }
}

int main() {
    static char mem[file_capacity];
    file_read(mem, "data.txt");
    exec(mem);
}