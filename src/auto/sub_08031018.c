int sub_08017400(int a, int b);
void sub_08008FC0(void);
typedef struct {
    int unk0[3];
    int unkC;
    int unk10[5];
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34[10];
    unsigned char unk5C;
    unsigned char unk5D[11];
    void *unk68;
    int unk6C[8];
    void (*unk8C)(void);
} Obj;
void sub_08031018(Obj *a, Obj *b)
{
    int x = a->unkC;
    int y = b->unkC;
    int flag = 1;
    if (x > y)
        flag = 0;

    a->unk5C = 11;
    a->unk8C = sub_08008FC0;
    if (flag == 0)
        a->unk24 = sub_08017400(0x10000, 0x30000) + 0x46000;
    else
        a->unk24 = 0xFFFBA000 - sub_08017400(0x10000, 0x30000);
    a->unk28 += 0xFFF86000;
    a->unk30 = 0xE000;
    a->unk68 = b;
}
