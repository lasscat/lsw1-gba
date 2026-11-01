struct Entry {
    void (*fn0)(void *);
    unsigned char pad4[4];
    void (*fn)(void *);
    unsigned char b0c;
    unsigned char b0d;
    unsigned char pad0e[4];
    unsigned char b12;
    signed char s13;
    unsigned char pad14[4];
    unsigned char args[0x10];
    unsigned int w28;
    unsigned int w2c;
    unsigned char b30;
    unsigned char pad31[3];
};

struct Flags {
    unsigned char pad[0xb5];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

extern struct Entry gUnknown_08054F3C[];

int sub_08017400(int a, int b);
void sub_08033618(void *obj, void *s, unsigned int x, unsigned int y, unsigned int z);
void sub_08000C7C(void *arg0, void *arg1, void *arg2, int arg3);
void sub_0800074C(void *arg0, void *arg1);
void sub_08015A14(void *arg0, unsigned int arg1);
void sub_080393C4(void *, unsigned char);

void sub_08033458(unsigned char *obj, unsigned int idx, int c, int d)
{
    struct Entry *e;

    if (c == 1) {
        void (*f)(void *) = gUnknown_08054F3C[obj[0x10F]].fn;
        if (f != 0)
            f(obj);
    }
    obj[0x10F] = idx;
    {
        int r = sub_08017400(gUnknown_08054F3C[idx].b0c, gUnknown_08054F3C[idx].b0d);
        e = &gUnknown_08054F3C[idx];
        obj[0x10E] = r;
    }
    if (d != 0) {
        sub_08033618(obj, gUnknown_08054F3C[idx].args, (void *)gUnknown_08054F3C[idx].w28, gUnknown_08054F3C[idx].w2c, e->b30);
        *(int *)(obj + 0x40) += e->s13 << 16;
    } else {
        if (gUnknown_08054F3C[idx].w28 != 0)
            sub_08000C7C(obj, gUnknown_08054F3C[idx].args, (void *)gUnknown_08054F3C[idx].w28, 0);
        else
            sub_0800074C(obj, gUnknown_08054F3C[idx].args);
        *(unsigned int *)(obj + 0x58) &= 0xFFFBFFFF;
        if (gUnknown_08054F3C[idx].w2c <= 0xf)
            ((struct Flags *)obj)->hi = gUnknown_08054F3C[idx].w2c;
        else
            sub_08015A14(obj, gUnknown_08054F3C[idx].w2c);
        sub_080393C4(obj, gUnknown_08054F3C[idx].b30);
    }
    {
        unsigned char q = gUnknown_08054F3C[idx].b12;
        obj[0xbf] = q;
    }
    {
        void (*g)(void *) = gUnknown_08054F3C[obj[0x10F]].fn0;
        if (g != 0)
            g(obj);
    }
}
