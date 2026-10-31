struct S100 { unsigned char pad[5]; unsigned char v; unsigned char pad2[94]; };
extern struct S100 gUnknown_03002C50[];

void sub_08005A38(int a, unsigned short *b, unsigned short *c)
{
    int v;

    v = gUnknown_03002C50[a].v >> 6;
    switch (v) {
    case 1:
        *b = 0x200;
        *c = 0x100;
        break;
    case 2:
        *b = 0x100;
        *c = 0x200;
        break;
    case 3:
        *b = 0x200;
        *c = 0x200;
        break;
    default:
        *b = 0x100;
        *c = 0x100;
        break;
    }
}
