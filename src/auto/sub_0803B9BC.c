extern void sub_08000F24(void *p);
extern void sub_08000FA4(void *arg0, int arg1, int arg2, int arg3);
extern void sub_080020FC(void *obj, int val);
extern void sub_08002138(void *, unsigned int);
extern void sub_08004458(unsigned char a, unsigned char b);
extern void sub_080047B4(void);
extern void sub_0802A758(void *arg0, int arg1);
extern void sub_0802AB84(void *arg0);
extern void sub_08036AF0(unsigned int obj, unsigned int val);
extern void sub_0803ABE0(void *obj);

struct Entry3B9BC {
    int unk0;
    int unk4;
    int pad[10];
};

extern struct Entry3B9BC gUnknown_0804FB00[];
extern unsigned char gUnknown_03002BEC;

struct Obj3B9BC {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    unsigned char pad14[0x20];
    int unk34;
    int unk38;
    unsigned char pad3C[0x1C];
    unsigned int unk58;
    unsigned char unk5C;
    unsigned char pad5D[0x37];
    unsigned char unk94;
    unsigned char unk95;
    unsigned char pad96[0x48];
    unsigned short unkDE;
    unsigned char unkE0;
    unsigned char padE1;
    unsigned char unkE2;
    unsigned char unkE3;
    unsigned char padE4[0xC];
    unsigned short unkF0;
    unsigned short unkF2;
    unsigned char padF4[0x28];
    unsigned short unk11C;
    unsigned short unk11E;
    unsigned char pad120[2];
    unsigned char unk122;
    unsigned char unk123;
};

void sub_0803B9BC(struct Obj3B9BC *obj)
{
    unsigned int state = obj->unkE2;

    switch (state) {
    case 0:
        if (obj->unk5C == 1) {
            obj->unkE3 |= 0xA;
            obj->unk95 = 2;
            obj->unk94 = 2;
            obj->unk8 = gUnknown_0804FB00[obj->unkE0].unk4;
            sub_080020FC(obj, 3);
        } else {
            sub_0802A758(obj, 2);
            if (obj->unkF0 & 0x100)
                sub_080020FC(obj, 0x2C);
            else
                sub_080020FC(obj, 3);
        }
        obj->unk34 = obj->unk11C << 16;
        obj->unk38 = obj->unk11E << 16;
        sub_0802AB84(obj);
        sub_08000FA4(obj, obj->unk34, obj->unk38, obj->unk8);
        break;
    case 3:
    case 0x2C:
        if (obj->unkC == obj->unk34 && obj->unk10 == obj->unk38) {
            sub_08000F24(obj);
            obj->unkDE = 0;
            sub_080020FC(obj, 0x45);
        }
        break;
    case 0x45:
        if ((obj->unk58 & 0x08000000) && gUnknown_03002BEC == 0x15) {
            obj->unk58 &= ~0x08000000;
            sub_080047B4();
        } else {
            unsigned char t = obj->unk5C;
            if ((t == 0xC || t == 0x13 || t == 7 || t == 0x1C) && (obj->unkF2 & 0x2000)) {
                obj->unkF2 |= 8;
                sub_08036AF0((unsigned int)obj, 0);
            } else {
                obj->unkE2 = 2;
            }
        }
        sub_08004458(obj->unk122, obj->unk123);
        break;
    default:
        sub_0803ABE0(obj);
        break;
    }
    if (state == 2) {
        if (obj->unk5C != 1)
            sub_08036AF0((unsigned int)obj, 0);
        else
            sub_08002138(obj, 3);
    }
}
