void *sub_0801D0AC(const char *a);
char *sub_08047968(const char *s, int c);
void *sub_08047878(void *dst, const void *src, unsigned int len);
void *memcpy(void *dst, const void *src, unsigned int len);
unsigned int strlen(const char *s);
extern char gUnknown_03002D12[];

char *sub_0800F81C(const char *a)
{
    int i = 0;
    char *sb = sub_0801D0AC(a);
    char *entry;
    char *dst;
    char *src;
    int len;
    int k;

    if (sub_08047968(sb, 0x40) != 0) {
        if (*sb != 0) {
            do {
                if (sb[i] == 0x40) {
                    i++;
                    entry = &gUnknown_03002D12[(unsigned char)sb[i] * 30];
                    len = strlen(entry);
                    i++;
                    dst = sb + (i + len - 2);
                    src = sb + i;
                    sub_08047878(dst, src, strlen(src) + 1);
                    src -= 2;
                    memcpy(src, entry, len);
                    k = i - 2;
                    i = k + len;
                } else {
                    i++;
                }
            } while (sb[i] != 0);
        }
    }
    return sb;
}
