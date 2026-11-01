struct Par;
struct Obj
{
    unsigned char unk00[0xc];
    int x;
    int y;
    unsigned char unk14[0x2c];
    unsigned int posZ;
    int vel;
    unsigned char unk48[0x10];
    unsigned int flags;
    unsigned char unk5C[0xc];
    struct Par *parent;
    unsigned char unk6C[0x49];
    unsigned char bitsLo : 2;
    unsigned char fld : 2;
    unsigned char bitsHi : 4;
    unsigned char unkB6[0x2c];
    unsigned char state;
};

struct Par
{
    unsigned char unk00[0xc];
    int x;
    int y;
    unsigned char unk14[0x2c];
    unsigned int posZ;
    int vel;
    unsigned char unk48[0x10];
    unsigned int flags;
    unsigned char unk5C[0xc];
    struct Obj *parent;
    unsigned char unk6C[0x49];
    unsigned char bitsLo : 2;
    unsigned char fld : 2;
    unsigned char bitsHi : 4;
    unsigned char unkB6[0x2c];
    unsigned char state;
};

extern unsigned char gUnknown_03006B1C[];
extern unsigned char gUnknown_0300332C[];

void sub_08000494(struct Obj *node);
void sub_08000F24(struct Obj *p);
void sub_08000F78(struct Obj *arg0, int arg1, int arg2, int arg3);
void sub_080020FC(struct Par *obj, int val);
void *sub_08033374(struct Par *a, int b);
extern void sub_08033458(void *arg0, int arg1, int arg2, int arg3);

void sub_08033874(struct Obj *obj)
{
    unsigned char *st;
    unsigned char *st2;
    struct Par *p;
    unsigned int target;
    int dx, dy;
    int z;
    unsigned char sw;

    if (gUnknown_03006B1C[0x29A] & 8)
    {
        int a, b;
        p = obj->parent;
        a = p->x;
        b = p->y;
        obj->x = a;
        obj->y = b;
        obj->posZ = p->posZ + 0x280000;
    }
    st = &obj->state;
    sw = *st;
    st2 = st; // FAKE: second copy of the state pointer steers register allocation
    switch (sw)
    {
    case 8:
        sub_08000F78(obj, obj->parent->x, obj->parent->y, 0x1e);
        obj->vel -= obj->vel >> 4;
        target = obj->parent->posZ + 0x280000;
        obj->fld = obj->parent->fld;
        if (obj->posZ < target)
            obj->vel += 0x3999;
        else if (obj->posZ > target)
            obj->vel += -0x3999;
        if (obj->parent->state == 0x50)
            *st2 = 0xf;
        break;
    case 0xf:
        if (obj->parent->flags & 0x40000)
        {
            dx = obj->x - obj->parent->x;
            if (dx < 0)
                dx = -dx;
            dy = obj->y - obj->parent->y;
            if (dy < 0)
                dy = -dy;
            if (dx + dy <= 0x4FFFF)
            {
                sub_08033458(obj, 0x34, 0, 0);
                z = 0; // FAKE: keeps the zero in a callee-saved register across the call
                *st = 0x14;
                sub_08000F24(obj);
                obj->vel = z;
            }
        }
        break;
    case 0x14:
        if (obj->flags & 0x40000)
        {
            sub_080020FC(obj->parent, 0x51);
            obj->parent->flags &= 0xFFFBFFFF;
            sub_08033374(*(struct Par * volatile *)&obj->parent, 0x32); // FAKE: force reload of parent
            sub_08033458(obj, 0x35, 0, 0);
            *st = 0x51;
        }
        break;
    case 0x51:
        if (obj->parent->flags & 0x40000)
        {
            sub_08033458(obj, 0x33, 0, 0);
            *st = 0x2c;
            { unsigned int *g = (unsigned int *)gUnknown_0300332C; g += 0x23; *g &= 0xFFFFFFFE; }
        }
        break;
    case 0x2c:
        obj->vel += 0x2710;
        if (!(obj->flags & 0x400))
            sub_08000494(obj);
        break;
    case 6:
        sub_08000494(obj);
        obj->parent->flags &= 0xFFFBFFFF;
        break;
    }
    if (obj->parent->flags & 2)
    {
        { unsigned int *g = (unsigned int *)gUnknown_0300332C; g += 0x23; *g &= 0xFFFFFFFE; }
        sub_08000494(obj);
    }
}
