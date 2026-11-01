extern void sub_08000F24(void *);
extern void sub_080020FC(void *, int);
extern void sub_08002138(void *, unsigned int);
extern void sub_08004458(unsigned char, unsigned char);
extern void sub_080047B4(void);
extern int sub_08004B18(int);
extern int sub_08017400(int, int);
extern void sub_0802AB84(void *);
extern void sub_08031434(void *, int);
extern void sub_08036AF0(void *, unsigned int);
extern void sub_08037548(void *, int, unsigned int, int);
extern void sub_0803ABE0(void *);
extern void sub_0803AF10(void *);
extern int sub_0803AFA4(void *);
extern void sub_0803B02C(void *, int, int);
extern void sub_0803B074(void *, int, int);
extern void sub_0803B0D4(void *);
extern void sub_0803B148(void *, int, int);
extern unsigned char gUnknown_03002BEC;

struct RowA {
    unsigned char pad[0x26];
    unsigned char idx;
    unsigned char pad2[0x30 - 0x27];
};
struct RowB {
    unsigned char pad[0xB];
    unsigned char val;
    unsigned char pad2[0x14 - 0xC];
};
extern struct RowA gUnknown_0804FB00[];
extern struct RowB gUnknown_08052FEC[];

void sub_0803B524(void *arg)
{
    unsigned char *obj = arg;
    unsigned int state;
    if (obj[0xE2] == 0) {
        sub_0803AF10(obj);
        *(unsigned short *)(obj + 0xdc) = sub_08017400(20, 100);
        if (obj[0x5c] == 0xc && obj[0xe0] == 0x5c)
            *(unsigned short *)(obj + 0xf2) |= 0x40;
    }
    state = obj[0xE2];
    switch (state) {
    case 3:
    case 0x23:
    case 0x2c: {
        int v = sub_0803AFA4(obj);
        unsigned short *timer;
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
        timer = (unsigned short *)(obj + 0xdc);
        if (*timer == 0) {
            *timer = 0x65;
            obj[0xe3] |= 4;
            sub_08037548(obj, 7, ((obj[0x5f] + 0x10) & 0xff) >> 5, 1);
            *(unsigned int *)(obj + 0x58) &= 0xFFFBFFFF;
            *(unsigned int *)(obj + 0x58) &= 0xFFFF7FFF;
        } else if (*timer == 0x65) {
            if (*(unsigned int *)(obj + 0x58) & 0x8000) {
                unsigned int k = gUnknown_0804FB00[obj[0xe0]].idx;
                sub_08031434(obj, gUnknown_08052FEC[k].val);
                *(unsigned int *)(obj + 0x58) &= 0xFFFF7FFF;
            }
            if (*(unsigned int *)(obj + 0x58) & 0x40000) {
                *timer = sub_08017400(20, 100);
                obj[0xe3] |= 4;
                sub_08037548(obj, 0, ((obj[0x5f] + 0x10) & 0xff) >> 5, 0);
            }
        } else {
            *timer = *timer - 1;
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
