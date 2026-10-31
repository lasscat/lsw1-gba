extern unsigned short gUnknown_03003430[];
extern int sub_0801123C(void);
extern int sub_0802B2A0(void *p);

typedef struct {
    unsigned char _00[0x58];
    unsigned int unk58;
    unsigned char _5C[0xAA];
    unsigned char unk106;
} Struct2814;

int sub_0802B814(Struct2814 *p)
{
    unsigned short h;
    unsigned short t;

    if ((p->unk58 & 0x400) == 0)
        return 0;
    if (p->unk106 != 0)
        h = gUnknown_03003430[2] & 0x200;
    else
        h = gUnknown_03003430[0] & 0x200;
    t = h;
    if (t == 0)
        return 0;
    if (sub_0801123C() == 0)
        return 0;
    if (sub_0802B2A0(p) == 0)
        return 0;
    return 1;
}
