#include <netinet/in.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

uint32_t get_nbo(FILE* fp);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage : ./add-nbo [file1] [file2]\n");
        return -1;
    }

    FILE *fp1, *fp2;
    if ((fp1 = fopen(argv[1], "rb")) == NULL) return -1;
    if ((fp2 = fopen(argv[2], "rb")) == NULL) return -1;

    uint32_t nbo1, nbo2;
    nbo1 = get_nbo(fp1);
    nbo2 = get_nbo(fp2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", nbo1, nbo1, nbo2, nbo2, nbo1+nbo2, nbo1+nbo2);
//    1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)

    fclose(fp2);
    fclose(fp1);

    return 0;
}

uint32_t get_nbo(FILE* fp)
{
    uint32_t nbo, hbo;

    fread(&hbo, 1, sizeof(uint32_t), fp);
    nbo = htonl(hbo);

    return nbo;
}
