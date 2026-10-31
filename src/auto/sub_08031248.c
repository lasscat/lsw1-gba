extern unsigned char gUnknown_08047FBC[];
typedef struct {
    unsigned char unk0[92];
    unsigned char unk5C;
    unsigned char fill5D[2];
    unsigned char unk5F;
    unsigned char fill60[4];
    int unk64;
    unsigned char fill68[108];
    int unkD4;
} S31248;
void sub_08031248(S31248 *a, int *b, int *c)
{
    if (a->unk5C != 1 && a->unk64 != 0 && !(a->unkD4 & 0x1000000)) {
        *b = a->unk5F >> 3;
        *c = gUnknown_08047FBC[*b];
    } else {
        *c = gUnknown_08047FBC[*b];
    }
}
