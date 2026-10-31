extern unsigned char gUnknown_03002BC8[];
int sub_08005B90(int a, void *b, unsigned short c, unsigned short d);

typedef struct {
    void **p0;
    int unk4;
    short unk8;
    unsigned short flags;
    unsigned char c;
    unsigned char max;
    unsigned char idx;
    unsigned char mode;
} S302;

void sub_08004158(void)
{
    S302 *s = (S302 *)gUnknown_03002BC8;
    if ((s->flags & 1) == 0)
        return;
    if (s->unk8 <= 0) {
        if (s->flags & 4) {
            if ((signed char)--s->idx < 0)
                s->idx = s->max;
        } else {
            s->idx++;
            if ((signed char)s->idx > s->max)
                s->idx = 0;
        }
        ((S302 *)gUnknown_03002BC8)->unk8 = ((S302 *)gUnknown_03002BC8)->c;
        {
            void **base = ((S302 *)gUnknown_03002BC8)->p0;
            if (base != 0 && ((S302 *)gUnknown_03002BC8)->mode != 0)
                sub_08005B90(3, *(void **)((char *)base + (((signed char)((S302 *)gUnknown_03002BC8)->idx) << 2)), 0x280, 1);
        }
    }
    ((S302 *)gUnknown_03002BC8)->unk8 -= 1;
}
