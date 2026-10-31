void sub_080021E8(void *arg0);
void sub_080023D8(void *arg0);

void sub_08002A80(void *arg0)
{
    unsigned char t;
    unsigned char *p94;
    unsigned int v9c;
    unsigned int b;
    if ((*(unsigned int *)((char *)arg0 + 0x58) & 0x10) == 0)
        return;
    t = *(unsigned char *)((char *)arg0 + 0x94);
    p94 = (unsigned char *)((char *)arg0 + 0x94);
    if (t == 0)
        return;
    *p94 = t - 1;
    if (*p94 != 0)
        return;
    v9c = *(unsigned int *)((char *)arg0 + 0x9c);
    if (v9c == 0) {
        *((unsigned char *)((char *)arg0 + 0x97)) += 1;
        b = *((unsigned char *)((char *)arg0 + 0x97));
        if (b >= *(unsigned short *)((char *)*(void **)((char *)*(void **)((char *)arg0 + 0x98) + 4) + 6)) {
            if ((*(unsigned int *)((char *)arg0 + 0x58) & 0x2000000) != 0) {
                *((unsigned char *)((char *)arg0 + 0x97)) = b - 1;
                *(unsigned int *)((char *)arg0 + 0x58) &= 0xFDFFFFEF;
                return;
            }
            *((unsigned char *)((char *)arg0 + 0x97)) = v9c;
        }
        if (*((unsigned char *)((char *)arg0 + 0x97)) == *(unsigned short *)((char *)*(void **)((char *)*(void **)((char *)arg0 + 0x98) + 4) + 6) - 1
            || *(unsigned short *)((char *)*(void **)((char *)*(void **)((char *)arg0 + 0x98) + 4) + 6) == 1)
            *(unsigned int *)((char *)arg0 + 0x58) |= 0x40000;
        *p94 = *(unsigned char *)((char *)arg0 + 0x95);
        sub_080023D8(arg0);
    } else {
        if ((*(unsigned int *)((char *)arg0 + 0x58) & 0x40000) != 0)
            return;
        *(unsigned int *)((char *)arg0 + 0x9c) = v9c + 2;
        sub_080021E8(arg0);
        sub_080023D8(arg0);
    }
}
