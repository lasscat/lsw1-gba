typedef struct {
    unsigned char _00[0x58];
    unsigned int unk58;
    unsigned char _5C[0x86];
    unsigned char unkE2;
    unsigned char _E3[0x0F];
    unsigned short unkF2;
} S42E2C;

extern void *gUnknown_0300731C[];
extern unsigned char gUnknown_0300739C;
extern void sub_08042E94(void *);

void sub_08042E2C(S42E2C *p)
{
    if ((p->unkF2 & 8) == 0)
        return;
    if (p->unk58 & 0x20)
        return;
    if (p->unkE2 == 0x58)
        return;
    gUnknown_0300731C[gUnknown_0300739C] = p;
    gUnknown_0300739C++;
    sub_08042E94(p);
}
