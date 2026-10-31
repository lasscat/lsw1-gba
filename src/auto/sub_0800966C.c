extern int sub_08008948(void *, void *);
extern unsigned int sub_080097F0(void *, void *);
extern void sub_08000F24(void *);
extern int sub_0802B6B0(void *);
extern void *sub_08001734(void);
extern void sub_08009A28(void *, int);
extern void sub_080020FC(void *, int);
extern void sub_0803E4CC(void);
extern unsigned char *gUnknown_0300340C;

void sub_0800966C(void *arg0, void *arg1)
{
    unsigned char *a = arg0;
    unsigned char *b = arg1;
    unsigned char *c = *(unsigned char **)(a + 0x68);
    unsigned int result;

    if (sub_08008948(a, b) != 0)
        return;
    if (c[0x5c] != 0x19) {
        if (c[0x5c] == 0x18) {
            if ((*(unsigned int *)(gUnknown_0300340C + 0xd4) & 4) != 0 &&
                sub_080097F0(b, a) <= 1) {
                *(unsigned int *)(a + 0x14) = *(unsigned int *)(a + 0xc);
                *(unsigned int *)(a + 0x18) = *(unsigned int *)(a + 0x10);
                sub_08000F24(a);
                *(unsigned int *)(c + 0x14) = *(unsigned int *)(c + 0xc);
                *(unsigned int *)(c + 0x18) = *(unsigned int *)(c + 0x10);
                sub_08000F24(c);
                return;
            }
        }
    } else {
        if (c[0xf1] == 0 && c[0xe2] != 0) {
            unsigned int zero = sub_0802B6B0(b);
            if (zero == 0 && *(unsigned char **)(b + 0x68) != c &&
                sub_080097F0(b, a) <= 1) {
                *(unsigned int *)(a + 0x14) = *(unsigned int *)(a + 0xc);
                *(unsigned int *)(a + 0x18) = *(unsigned int *)(a + 0x10);
                sub_08000F24(a);
                *(unsigned short *)(a + 0xde) = zero;
                *(unsigned int *)(c + 0x14) = *(unsigned int *)(c + 0xc);
                *(unsigned int *)(c + 0x18) = *(unsigned int *)(c + 0x10);
                sub_08000F24(c);
                *(unsigned short *)(c + 0xde) = zero;
                if (*(void (**)(void))(c + 0x60) != sub_0803E4CC)
                    *(void (**)(void))(c + 0x60) = sub_0803E4CC;
            }
        }
    }
    if (b[0x5c] == 1) {
        result = sub_080097F0(a, b);
        if (result <= 1) {
            void *other = sub_08001734();
            if (other != 0)
                sub_08009A28(other, result);
            sub_08009A28(b, result);
        } else if (result == 2) {
            *(unsigned int *)(b + 0x58) |= 0x2000;
            *(unsigned int *)(b + 0x40) = *(unsigned int *)(a + 0x40) + ((unsigned int)a[0x78] << 16);
            *(unsigned char **)(b + 0x6c) = a;
            b[0xbf] = 0x7f;
        }
    } else if (b[0x5c] == 0xc || b[0x5c] == 0x13 || b[0x5c] == 7 || b[0x5c] == 0x1c) {
        result = sub_080097F0(a, b);
        if (result <= 1)
            sub_08009A28(b, result);
    } else if (b[0x5c] == 0xb && !(b[0xfb] & 4)) {
        sub_080020FC(b, 6);
        *(unsigned int *)(b + 0x58) &= ~4u;
    }
}
