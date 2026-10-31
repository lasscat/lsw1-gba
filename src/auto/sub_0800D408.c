extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_080020FC(void *, int);
extern void sub_08000F50(void *);
extern void sub_08002138(void *, unsigned int);
extern void sub_0802E2CC(void *);
extern unsigned char *gUnknown_0300340C;

struct UnkD408 {
    unsigned char pad0[0xD4];
    unsigned int word_d4;
    unsigned char pad1[0x19];
    unsigned char byte_f1;
};

void sub_0800D408(void *arg)
{
    unsigned char *p = arg;
    struct UnkD408 *obj = (struct UnkD408 *)sub_08004A5C(p[4], p[5]);

    if (obj->byte_f1 != 0)
        return;
    obj->word_d4 |= 8;
    sub_080020FC(obj, 0x14);
    sub_0802E2CC(gUnknown_0300340C);
    sub_08000F50(gUnknown_0300340C);
    sub_08002138(gUnknown_0300340C, 3);
    *(unsigned int *)(gUnknown_0300340C + 0xD4) |= 4;
}
