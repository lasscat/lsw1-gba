extern unsigned char gUnknown_03002D12[];
extern unsigned int gUnknown_03003250[];

int sub_0800EB7C(unsigned char *p);
int sub_0800F7D0(int, int);

unsigned char *sub_0800EC24(unsigned char *p, int limit)
{
    unsigned char *a = 0;
    unsigned char *b = 0;
    int sum = 0;

    for (; *p != 0 && sum <= limit; p++) {
        if (*p == 7)
            continue;
        if (*p == 0x0a) {
            a = p;
            break;
        }
        if (*p == 0x40) {
            p++;
            sum += sub_0800EB7C(&gUnknown_03002D12[*p * 30]);
        } else {
            unsigned int code;
            unsigned int base;

            if (*p == 0x20 || (*p == 0xf0 && *(p + 1) == 0))
                a = p;
            code = *p;
            if (code > 0xef) {
                code = (code << 8) | *++p;
                base = gUnknown_03003250[1];
            } else {
                base = gUnknown_03003250[0];
            }
            sum += sub_0800F7D0(base, code);
            if (*p == 0x2d && sum <= limit)
                b = p + 1;
        }
    }
    if (*p == 0) {
        if (sum <= limit)
            a = p;
    }
    if (a == 0)
        a = b;
    return a;
}
