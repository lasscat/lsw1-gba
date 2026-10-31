typedef struct {
    unsigned char unk_00[0x1B];
    unsigned char unk_1B;
    unsigned char unk_1C[0x14];
} T48_0805171C;

typedef struct {
    unsigned char unk_00[0x19];
    unsigned char unk_19;
    unsigned char unk_1A[6];
} T32_08051ECC;

typedef struct {
    unsigned char unk_00[0x5C];
    unsigned char unk_5C;
    unsigned char unk_5D[0x83];
    unsigned char unk_E0;
} ObjB75C;

extern T48_0805171C gUnknown_0805171C[];
extern T32_08051ECC gUnknown_08051ECC[];

int sub_0802B75C(ObjB75C *p)
{
    if (p->unk_5C == 0x18 && gUnknown_0805171C[p->unk_E0].unk_1B != 0)
        return 1;
    if (p->unk_5C == 0x19 && gUnknown_08051ECC[p->unk_E0].unk_19 != 0)
        return 1;
    return 0;
}
