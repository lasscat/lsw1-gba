extern void sub_080020FC(void *obj, int val);
extern void sub_0803ABE0(void *obj);
extern void sub_08036AF0(unsigned int obj, unsigned int val);

struct Obj3BC98 {
    int unk0[9];
    int unk24;
    unsigned char unk28[0xBA];
    unsigned char unkE2;
};

void sub_0803BC98(struct Obj3BC98 *obj)
{
    int var;
    int val;
    int absval;

    if (obj->unkE2 == 0)
        sub_080020FC(obj, 0x2f);
    var = obj->unkE2;
    if (var == 0x2f) {
        val = obj->unk24;
        absval = val;
        if (val < 0)
            absval = -val;
        if (absval <= 0xFFF)
            var = 2;
        else
            obj->unk24 = val - (val >> 4);
    } else {
        sub_0803ABE0(obj);
    }
    if (var == 2)
        sub_08036AF0((unsigned int)obj, 0);
}
