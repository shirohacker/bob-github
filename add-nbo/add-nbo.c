#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_number(char *filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("%s file NOT FOUND!\n", filename);
        fclose(file);
        return 0;
    }

    uint32_t num = 0;
    if (fread(&num, sizeof(uint32_t), 1, file) != 1) {
        printf("%s file READ ERROR!\n", filename);
        fclose(file);
        return 0;
    }

    fclose(file);

    return ntohl(num);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage : %s <file1> <file2>\n", argv[0]);
        return 0;
    }

    uint32_t num1 = read_number(argv[1]);
    uint32_t num2 = read_number(argv[2]);

    uint32_t res = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, res, res);

    return 0;
}