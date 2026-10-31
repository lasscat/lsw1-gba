typedef unsigned char u8;

struct Entry {
    u8 unk0[6];
    u8 flags;
    u8 unk7;
};

extern unsigned int sub_0801597C(void *arg);
extern unsigned int sub_080159C8(void *arg);
extern void sub_080158B4(unsigned int index, void *arg0, void *arg1);
extern struct Entry gUnknown_030048A0[];

unsigned int sub_08015740(void *arg0, void *arg1)
{
    unsigned int index;

    index = sub_0801597C(arg1);
    if (index != 0xff) {
        sub_080158B4(index, arg0, arg1);
    } else {
        index = sub_080159C8(arg1);
        if (index == 0xff) {
            return 0xff;
        }
        sub_080158B4(index, arg0, arg1);
    }
    gUnknown_030048A0[index].flags |= 1;
    return index;
}
