extern int sub_08008948(void *arg0, void *arg1);
extern void sub_08002138(void *arg0, unsigned int arg1);
extern unsigned short gUnknown_03003430[];
extern unsigned int gUnknown_0300332C[];

typedef struct {
    unsigned char pad0[0x40];
    int unk40;
    unsigned char pad44[0x14];
    int unk58;
    unsigned char unk5C;
    unsigned char pad5D[7];
    void *unk64;
    unsigned char pad68[0x78];
    unsigned char unkE0;
    unsigned char unkE1;
    unsigned char padE2[0x13];
    unsigned char unkF5;
    unsigned char padF6[0x10];
    unsigned short unk106;
} Ent;

void sub_0803DCD4(Ent *a0, Ent *a1)
{
    if (a0->unk106 != 0) {
        if (a1->unk40 < a0->unk40)
            return;
    } else {
        if (sub_08008948(a0, a1) != 0)
            return;
    }
    if (a1->unk5C != 1)
        return;
    if (a0->unk58 & 2)
        return;
    if (a1->unkE1 != 0x18)
        return;
    if (a0->unkF5 != 0) {
        if ((gUnknown_03003430[2] & 1) == 0)
            return;
    }
    if (*(unsigned char *)&a0->unk106 != 0 && sub_08008948(a0, a1) != 0) {
        sub_08002138(a0, 0x2f);
        a0->unk64 = a1;
        gUnknown_0300332C[35] |= 0x200;
    } else {
        if (a0->unkE0 == 0)
            sub_08002138(a0, 5);
        else
            sub_08002138(a0, 4);
    }
    a0->unk58 &= ~4;
}
