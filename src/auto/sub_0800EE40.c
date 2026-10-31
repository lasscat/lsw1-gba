unsigned char *sub_0800EC24(unsigned char *p, int d);
int sub_0800EF10(int a0, int a1, int a2, unsigned char *a3, int flags);

int sub_0800EE40(int a, int b, int c, int d, unsigned char **e, int f, int *g)
{
    unsigned char buf[96];
    unsigned char *src;
    unsigned char *end;
    unsigned char *dst;
    unsigned int code;

    src = *e;
    end = sub_0800EC24(src, d);
    if (end == 0)
        return a;
    dst = buf;
    src = *e;
    if (src != end && *g != 0) {
        do {
            *dst++ = *src++;
            (*g)--;
            if (src == end)
                break;
        } while (*g != 0);
    }
    if (dst[-1] == 0x40) {
        code = dst[-2];
        if (code <= 0xEF)
            *dst++ = *src++;
    }
    if (dst[-1] == 7)
        *dst++ = *src++;
    *dst = 0;
    *e = src;
    a = sub_0800EF10(a, b, c, buf, f);
    if (**e == 0x0A)
        (*e)++;
    while (**e == 0x20)
        (*e)++;
    return a;
}
