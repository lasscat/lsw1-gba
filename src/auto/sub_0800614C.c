int sub_0800614C(unsigned int mode, unsigned short *dest, unsigned short *pal,
                unsigned short tile, unsigned short attr, unsigned int x, unsigned int y)
{
    switch (mode) {
    case 0:
        break;
    case 1:
        if (x > 31) {
            dest += 1024;
            x -= 32;
        }
        break;
    case 2:
        if (y > 31) {
            dest += 1024;
            y -= 32;
        }
        if (x > 31) {
            dest += 1024;
            x -= 32;
        }
        if (y > 31) {
            dest += 2048;
            y -= 32;
        }
        break;
    case 3:
        if (x > 31) {
            dest += 1024;
            x -= 32;
        }
        if (y > 31) {
            dest += 2048;
            y -= 32;
        }
        break;
    }
    dest += y * 32 + x;
    *dest = (attr << 12) + *pal + tile;
    return 1;
}
