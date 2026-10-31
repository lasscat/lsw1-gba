struct Obj {
    unsigned char pad[0xC];
    int fC;
    int f10;
};

extern int sub_08017400(int a, int b);
extern int sub_0802A8E0(void *obj, int *p, int arg2);
extern void sub_08035F20(void *obj);
extern void sub_08036140(void *obj, int a, int b);

void sub_08036048(struct Obj *obj)
{
    int ang;
    int mag;
    int vals[2];
    int *tbl;

    ang = sub_08017400(0, 0xFF);
    mag = sub_08017400(0x14, 0x3C);
    tbl = (int *)0x0804BA04;
    vals[0] = obj->fC + tbl[0xFF & ~(ang + 0x40)] * mag;
    vals[1] = obj->f10 + tbl[0xFF & ~ang] * mag;
    if (sub_0802A8E0(obj, vals, mag) == 0)
        sub_08035F20(obj);
    else
        sub_08036140(obj, vals[0], vals[1]);
}
