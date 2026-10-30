extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_0803F108(void *);

struct Obj_0800CE3C
{
    unsigned char pad[0x101];
    unsigned char f101;
    unsigned char pad2[3];
    unsigned char f105;
};

void sub_0800CE3C(unsigned char *arg)
{
    struct Obj_0800CE3C *obj = (struct Obj_0800CE3C *)sub_08004A5C(arg[4], arg[5]);
    obj->f105 = 1;
    sub_0803F108(obj);
    obj->f101 = arg[6];
}
