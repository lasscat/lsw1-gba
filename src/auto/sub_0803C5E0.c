struct Param_0803C5E0 {
    int unk0;
    short unk4;
    short unk6;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char unkB;
    unsigned char unkC;
    unsigned char unkD;
    unsigned char unkE;
    unsigned char unkF;
};

struct Obj_0803C5E0 {
    unsigned char pad0[12];
    int unkC;
    int unk10;
    unsigned char pad14[44];
    int unk40;
    unsigned char pad44[20];
    unsigned int unk58;
    unsigned char unk5C;
    unsigned char pad5D[3];
    void *unk60;
    unsigned char pad64[132];
    int unkE8;
    unsigned char padEC[4];
    unsigned char unkF0;
    unsigned char unkF1;
    unsigned char padF2[2];
    unsigned char unkF4;
    unsigned char padF5;
    unsigned char unkF6;
    unsigned char padF7[9];
    unsigned char unk100;
    unsigned char unk101;
    unsigned char pad102[2];
    unsigned char unk104;
    unsigned char unk105;
    unsigned char unk106;
    unsigned char pad107;
    unsigned short unk108;
    unsigned char pad10A[2];
    int unk10C;
    int unk110;
    unsigned int unk114;
};

extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
extern void *sub_08000234(void);
extern void sub_08002138(void *arg0, unsigned int arg1);
extern void sub_080020FC(void *arg0, int arg1);
extern void sub_08000DA4(void *arg0, int arg1, int arg2);
extern int sub_0801419C(int x, int y);
extern void sub_080144F4(void *arg0);
extern unsigned int sub_08004A5C(unsigned char arg0, unsigned char arg1);
extern void sub_0803C6D4(void);

void *sub_0803C5E0(unsigned char arg0, unsigned char arg1)
{
    struct Param_0803C5E0 *p;
    struct Obj_0803C5E0 *obj;

    p = sub_08004A14(arg0, arg1);
    obj = sub_08000234();
    obj->unk5C = p->unk0;
    obj->unk58 = 0x01000008;
    sub_08002138(obj, 3);
    sub_080020FC(obj, 0);
    obj->unkF1 = 0;
    obj->unkF0 = 0;
    obj->unk100 = 0;
    obj->unkF6 = 0x2D;
    obj->unk60 = sub_0803C6D4;
    obj->unkF4 = 0;
    sub_08000DA4(obj, p->unk4, p->unk6);
    obj->unk40 = sub_0801419C(obj->unkC, obj->unk10) + (p->unk8 << 16);
    sub_080144F4(obj);
    obj->unk101 = p->unk9;
    obj->unk104 = p->unkD;
    obj->unk105 = p->unkC;
    obj->unkE8 = 0;
    obj->unk114 = sub_08004A5C(p->unkA, p->unkB);
    obj->unk106 = p->unkE;
    obj->unk108 = p->unkF;
    obj->unk110 = 0;
    obj->unk10C = 0;
    return obj;
}
