extern unsigned char gUnknown_080714A6[];
extern unsigned char gUnknown_08070A4C[];
extern unsigned int gUnknown_0807126C[];
extern unsigned int gUnknown_0300340C;
extern void sub_080157AC(void *arg0);
extern void sub_08015810(void *arg0);
extern void sub_08015A70(void *arg0, unsigned int arg1, unsigned int arg2);
extern void sub_08000BF4(void *arg0, unsigned int arg1);

struct Obj {
    unsigned char unk00[0x58];
    unsigned int unk58;
    unsigned char unk5C[0x50];
    unsigned int unkAC;
    unsigned char unkB0[0x0C];
    unsigned short unkBC;
    unsigned char unkBE[0x22];
    unsigned char unkE0;
};

void sub_080407BC(struct Obj *arg0, unsigned int arg1)
{
    unsigned int v = arg1;
    unsigned char *field;

    if (v == 0x82)
        v = gUnknown_080714A6[*(unsigned char *)(gUnknown_0300340C + 0xE0) - 0x2C];
    field = &arg0->unkE0;
    if (*field != v) {
        if (arg0->unk58 & 0x200000) {
            sub_080157AC(arg0);
            arg0->unkAC = 0;
            arg0->unkBC &= 0xFDFF;
        }
        sub_08000BF4(arg0, (unsigned int)&gUnknown_08070A4C[v << 4]);
        sub_08015A70(arg0, gUnknown_0807126C[v], 0);
        if (arg0->unk58 & 0x400)
            sub_08015810(arg0);
        *field = v;
    }
}
