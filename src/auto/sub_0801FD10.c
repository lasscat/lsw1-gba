extern int gUnknown_0300368C[];
extern int gUnknown_030069A4;
extern unsigned short gUnknown_03003430[];
extern int gUnknown_030036BC[];
extern int gUnknown_03006A00[];

int sub_08011F80(int *counter, unsigned int limit, unsigned int value, unsigned int flag, int index);
void sub_08000D7C(void *arg0, int arg1, int arg2);
void sub_0801FE24(void);
void sub_08029DEC(void);
void sub_08013DEC(unsigned int arg0, unsigned int arg1, unsigned int arg2);

void sub_0801FD10(void)
{
    int v = gUnknown_0300368C[4];
    int *p;

    if (v != 0)
        return;
    p = &gUnknown_030069A4;
    if (sub_08011F80(p, 0, 4, 1, v) != 0) {
        int *q = p - 1;
        sub_08000D7C((void *)q[0], 0x320000, q[1] * 0xC0000 + 0xC0000);
    }
    if (gUnknown_03003430[2] & 1) {
        sub_0801FE24();
    } else if (gUnknown_03003430[2] & 2) {
        if (gUnknown_030036BC[0] == 5) {
            sub_08029DEC();
            sub_08013DEC(5, 2, gUnknown_03006A00[4]);
        } else {
            p -= 1;
            sub_08013DEC(((unsigned short *)p)[4], ((unsigned short *)p)[5], 0);
            if (((unsigned short *)p)[4] == 13)
                sub_08029DEC();
        }
    }
}
