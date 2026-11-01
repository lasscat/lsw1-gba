typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void sub_0802AF4C(void *);
extern void sub_08037798(void *, int);
extern void sub_080020FC(void *, int);
extern void sub_0802A758(void *, int);
extern void sub_08036AF0(unsigned int, unsigned int);
extern void sub_0803ABE0(void *);
extern unsigned int gUnknown_FFFBFFFF;

void sub_08031E24(void *arg0)
{
    u8 *obj = arg0;
    u32 *flags;
    u32 status;

    status = obj[0xE2];
    switch ((u32)status) {
    case 0:
        sub_0802AF4C(obj);
        sub_08037798(obj, 0);
        sub_080020FC(obj, 5);
        sub_0802A758(obj, 0);
        flags = (u32 *)(obj + 0x58);
        *flags &= (u32)&gUnknown_FFFBFFFF;
        break;
    case 2:
    case 5:
        flags = (u32 *)(obj + 0x58);
        if ((*flags & 0x40000) != 0 ||
            *(u16 *)((u8 *)*(u32 **)((u8 *)*(u32 **)(obj + 0x98) + 4) + 6) == 1)
            sub_08036AF0((unsigned int)obj, 0);
        break;
    default:
        sub_0803ABE0(obj);
        break;
    }
}
