extern void *sub_0801D0AC(const char *a);

typedef struct {
    unsigned char pad[0x74];
    int f74;
} Struct_030069D8;

extern Struct_030069D8 *gUnknown_030069D8;

char *sub_08020B40(unsigned int a)
{
    char *s = sub_0801D0AC((const char *)a);
    gUnknown_030069D8->f74 = -1;
    if (*s == '^') {
        s++;
        if ((unsigned char)(*s - '0') <= 9) {
            gUnknown_030069D8->f74 = *s - '0';
            s++;
        }
    }
    return s;
}
