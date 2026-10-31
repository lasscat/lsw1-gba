extern unsigned char gUnknown_03002D12[];
extern unsigned int gUnknown_03003250[];

int sub_0800F7D0(int, int);

int sub_0800EB7C(unsigned char *p)
{
    int sum = 0;
    unsigned char c;

    while ((c = *p) != 0) {
        if (c == 0x40) {
            p++;
            sum += sub_0800EB7C(&gUnknown_03002D12[*p * 30]);
        } else {
            unsigned int base;
            unsigned int code = *p;

            if (code > 0xEF) {
                code = (code << 8) | *++p;
                base = gUnknown_03003250[1];
            } else {
                base = gUnknown_03003250[0];
            }
            sum += sub_0800F7D0(base, code);
        }
        p++;
    }
    return sum;
}
