extern void sub_08000F24(void *);
extern void sub_080020FC(void *, int);
extern void sub_08002138(void *, unsigned int);
extern void sub_08004458(unsigned char, unsigned char);
extern void sub_080047B4(void);
extern int sub_08004B18(int);
extern void sub_0802AB84(void *);
extern void sub_08036AF0(void *, unsigned int);
extern void sub_0803ABE0(void *);
extern void sub_0803AF10(void *);
extern int sub_0803AFA4(void *);
extern void sub_0803B02C(void *, int, int);
extern void sub_0803B074(void *, int, int);
extern void sub_0803B0D4(void *);
extern void sub_0803B148(void *, int, int);
extern unsigned char gUnknown_03002BEC;

void sub_0803B39C(void *arg)
{
    unsigned char *obj = arg;
    unsigned int state;
    if (obj[0xE2] == 0)
        sub_0803AF10(obj);
    state = obj[0xE2];
    switch (state) {
    case 3:
    case 0x23:
    case 0x2c: {
        int v = sub_0803AFA4(obj);
        if (v == 0x100 || state == 0x23) {
            unsigned int a = obj[0x121];
            unsigned int c = obj[0x122] + 1;
            if (c == (unsigned char)sub_08004B18(a)) {
                sub_08000F24(obj);
                sub_080020FC(obj, 0x45);
                sub_0803B02C(obj, a, 0);
                sub_0803B074(obj, a, 0);
            } else {
                sub_0803B148(obj, a, c);
                sub_0802AB84(obj);
            }
        } else if (obj[0x5F] != v) {
            sub_0802AB84(obj);
        }
        break;
    }
    case 0x45: {
        unsigned int a, b;
        sub_08002138(obj, 3);
        sub_080020FC(obj, 2);
        a = obj[0x11f];
        b = obj[0x120];
        if ((*(unsigned int *)(obj + 0x58) & 0x8000000) && gUnknown_03002BEC == 0x14) {
            *(unsigned int *)(obj + 0x58) &= 0xF7FFFFFF;
            sub_080047B4();
        } else {
            unsigned int kind = obj[0x5c];
            if (kind == 0xc || kind == 0x13 || kind == 7 || kind == 0x1c) {
                unsigned short *flags = (unsigned short *)(obj + 0xf2);
                if (*flags & 0x2000) {
                    *flags |= 8;
                    sub_08036AF0(obj, 0);
                }
            }
        }
        sub_08004458(a, b);
        break;
    }
    case 2:
        sub_080020FC(obj, 3);
        break;
    case 0x58: {
        unsigned short *timer = (unsigned short *)(obj + 0xdc);
        --*timer;
        if (*timer == 0)
            sub_0803B0D4(obj);
        break;
    }
    default:
        sub_0803ABE0(obj);
        break;
    }
}
