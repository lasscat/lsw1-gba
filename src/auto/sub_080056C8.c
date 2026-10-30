void CpuSet(const void *src, void *dest, unsigned int count);
void sub_08005758(int a, unsigned short b, unsigned short c);
extern unsigned char gUnknown_03002C54[];

void sub_080056C8(int a, unsigned short color, unsigned short c)
{
    unsigned char *data = &gUnknown_03002C54[a * 100];
    unsigned short out;
    unsigned short offset;
    unsigned int dest;
    unsigned int count;

    sub_08005758(a, color, c);

    if (!(data[0] & 0x80))
        color |= (c >> 4) << 12;

    offset = data[1] << 11;
    dest = offset + ((unsigned int)0xC0 << 19);

    if ((data[1] & 0xC0) == 0x80 || (data[1] & 0xC0) == 0x40)
        count = 2;
    else {
        count = 1;
        if ((data[1] & 0xC0) == 0xC0)
            count = 4;
    }

    out = color;
    CpuSet(&out, (void *)dest, (count << 10) | ((unsigned int)0x80 << 17));
}
