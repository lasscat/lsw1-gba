typedef struct {
    void *p0;
    int f4;
    int f8;
} Item;

typedef struct {
    unsigned char unk00[12];
    int f0C;
    int f10;
    unsigned char unk14[68];
    unsigned int f58;
    unsigned char unk5C[3];
    unsigned char f5F;
    unsigned char unk60[108];
    Item table[8];
} Main;

int sub_08001974(void *a, void *p, unsigned int idx, int *out);

int sub_08001108(Main *a, unsigned int i, unsigned int j, int *out)
{
    unsigned int f = a->f58 & 0x40000000;
    unsigned int t = 4;
    void *p;
    void *q;
    if (f)
        t = 8;
    p = a->table[i].p0;
    q = ((void **)p)[1];
    if (sub_08001974(a, q, j, out) == 1) {
        out[1] = a->f10 + (out[1] << 16);
        if (a->f5F > t)
            out[0] = a->f0C - (out[0] << 16);
        else
            out[0] = a->f0C + (out[0] << 16);
        return 1;
    }
    return 0;
}
