int sub_0800EB7C(unsigned char *p);
void *sub_080135D0(int arg0);
unsigned int strlen(const char *s);

void sub_0801DB1C(unsigned char *s, void *arg)
{
    unsigned int len = 0;
    unsigned int pos = 0;
    unsigned int n = ((unsigned char *)arg)[0x30];
    unsigned int idx = n - 1;
    unsigned int v;
    unsigned int off;
    unsigned char *cnt;
    v = sub_0800EB7C((*(unsigned char ***)((unsigned char *)arg + 0x44))[idx]) + sub_0800EB7C(s);
    if (v > ((unsigned char *)arg)[0x34]) {
        idx = n;
        (*(void ***)((unsigned char *)arg + 0x44))[idx] = sub_080135D0(((unsigned char *)arg)[0x31]);
    } else {
        len = strlen((*(const char ***)((unsigned char *)arg + 0x44))[idx]);
    }
    cnt = (unsigned char *)arg + 0x30;
    off = idx * 4;
    idx++;
    while (pos < strlen((const char *)s)) {
        (*(unsigned char **)(off + (unsigned int)(*(void **)((unsigned char *)arg + 0x44))))[len] = s[pos];
        (*(unsigned char **)(off + (unsigned int)(*(void **)((unsigned char *)arg + 0x44))))[len + 1] = 0;
        pos++;
        len++;
    }
    (*(unsigned char **)(off + (unsigned int)(*(void **)((unsigned char *)arg + 0x44))))[len] = 0;
    *cnt = idx;
}
