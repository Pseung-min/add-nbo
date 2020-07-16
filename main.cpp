#include <netinet/in.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

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

    uint32_t hn1, hn2;
    fread(&hn1, sizeof(uint32_t), 1, fp1);
    fread(&hn2, sizeof(uint32_t), 1, fp2);

//    printf("0x%x\n0x%x\n", hn1, hn2);

    uint32_t nn1, nn2, s;
    nn1 = htonl(hn1);
    nn2 = htonl(hn2);
    s = nn1 + nn2;

//    printf("0x%x\n0x%x\n", nn1, nn2);
//    printf("%d\n%d\n", nn1, nn2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", nn1, nn1, nn2, nn2, s, s);
//    1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)

    fclose(fp2);
    fclose(fp1);

    return 0;
}
