extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_0800037C(unsigned int);
extern void sub_0800455C(unsigned char, unsigned char);

struct Obj_0800CA0C
{
    unsigned char pad[0x58];
    unsigned int flags;
};

void sub_0800CA0C(void *p)
{
    unsigned char *r4 = p;
    unsigned int r2 = sub_08004A5C(r4[4], r4[5]);

    if (r2 != 0) {
        ((struct Obj_0800CA0C *)r2)->flags |= 2;
        sub_0800037C(r2);
    }
    sub_0800455C(r4[4], r4[5]);
}
