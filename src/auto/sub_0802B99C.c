struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
};

struct Obj
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C;
    unsigned char pad5D[0x8B];
    unsigned int tokE8;
    unsigned int tokEC;
};

void sub_08000494(struct Node *node);
void sub_0802BA5C(void *arg0);
void sub_0802BA98(void *arg0);
void sub_08014F60(void *arg0);

void sub_0802B99C(struct Obj *obj)
{
    sub_08000494((struct Node *)obj);
    obj->flags |= 8;
    sub_0802BA5C(obj);
    sub_0802BA98(obj);
    if (obj->tokE8 != 0) {
        ((struct Node *)obj->tokE8)->flags |= 2;
        sub_08014F60((void *)obj->tokE8);
    }
    if (obj->unk5C == 0x19) {
        if (obj->tokEC != 0) {
            ((struct Node *)obj->tokEC)->flags |= 2;
            obj->tokEC = 0;
            sub_08014F60((void *)obj->tokEC);
        }
    }
}
