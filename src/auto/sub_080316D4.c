extern unsigned int gUnknown_03006FD4;

typedef struct {
    int unk0;
    int kind;
    struct { unsigned int flag : 1; unsigned int rest : 7; } bits;
    int count;
} Elem;

int sub_080316D4(int idx)
{
    unsigned char *p = (unsigned char *)&gUnknown_03006FD4;
    int off = idx << 4;
    unsigned int *kp = (unsigned int *)(p + 4);
    unsigned int kind = *(unsigned int *)((unsigned char *)kp + off);
    int ret;

    switch (kind) {
    case 1: {
        unsigned char *cp = p + 0xc;
        int *count = (int *)(cp + off);
        if (*count == 0) {
            ret = 1;
        } else {
            Elem *e = (Elem *)(p + off);
            if (e->bits.flag) {
                ret = 0;
            } else {
                *count = *count - 1;
                ret = (*count == 0);
            }
        }
        break;
    }
    case 0:
        ret = 1;
        break;
    case 2: {
        Elem *e = (Elem *)(p + off);
        if (!e->bits.flag) {
            unsigned char *cp = p + 0xc;
            int *count = (int *)(cp + off);
            *count = *count + 1;
        }
        ret = 0;
        break;
    }
    default:
        ret = 0;
    }

    return ret;
}
