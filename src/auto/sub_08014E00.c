extern unsigned char gUnknown_030049F0[];

typedef struct
{
    int x;
    unsigned int y;
} Pos;

int sub_08014E00(Pos *p)
{
    unsigned char *base = gUnknown_030049F0;

    if (p->x > (*(unsigned short *)(base + 0x412) << 3))
        return 0;
    if (p->y <= (unsigned int)(*(unsigned short *)(base + 0x414) << 3))
        return 1;
    return 0;
}
