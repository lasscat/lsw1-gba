typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;

typedef union Fx {
    int v;
    struct { u16 lo; s16 hi; } p;
} Fx;

typedef struct Ent {
    u8 pad0[8];
    u8 **info;
    u8 padC[8];
    Fx x;
    Fx y;
    u8 pad1C[8];
    union { u8 b[8]; u16 h[4]; struct { u8 y; u8 r0:6; u8 shape:2; } g; struct { u8 pad[3]; u8 r:6; u8 size:2; } k; struct { u16 a0; u16 x:9; u16 r1:7; u16 tile:10; u16 r2:6; } f; } oam;
    u8 pad2C[8];
    u16 *tiles;
    u8 pad38[2];
    u16 flags;
    u16 tileBase;
    u8 pad3E[10];
    int f48;
    s8 f4c;
    u8 f4d;
    u8 f4e;
    u8 pad4F[5];
    int f54;
} Ent;

extern int gUnknown_030049F0[];
extern unsigned char gUnknown_0300477C[];
extern unsigned char gUnknown_0804BEB8[];
extern unsigned char gUnknown_0804BEC8[];
void sub_08001CC8(int, int, int, int *);
int sub_080151E8(unsigned char, void *);

int sub_08016FD8(Ent *e)
{
    u8 *a;
    int w, h;
    int i, j;
    int sx, sy;

    int pos[2];
    pos[0] = gUnknown_030049F0[0xA5];
    pos[1] = gUnknown_030049F0[0xA6];
    if (e->flags & 0x200) {
        pos[0] = e->x.p.hi;
        pos[1] = e->y.p.hi;
    } else if (e->flags & 1) {
        if ((u8)(e->f4e - 9) <= 2)
            sub_08001CC8(e->x.v, e->y.v, e->f48, pos);
        else
            sub_08001CC8(e->x.v, e->y.v, e->f54, pos);
    } else {
        pos[0] = -pos[0] + e->x.p.hi;
        pos[1] = -pos[1] + e->y.p.hi;
    }
    if ((unsigned)pos[0] > 0xF0 || pos[1] < 0 || pos[1] > 0xA0)
        return 2;
    sx = pos[0];
    sy = pos[1];
    a = e->info[1];
    i = (s8)e->f4d;
    j = i + i;
    a += 0xC;
    a += a[j];
    e->oam.f.tile = e->tileBase + e->tiles[i];
    e->oam.f.x = sx;
    e->oam.g.y = sy;
    w = a[2] >> 4;
    h = a[3] >> 4;
    if (w == 4) w = 3;
    if (h == 4) h = 3;
    e->oam.k.size = gUnknown_0804BEB8[w + h * 4];
    e->oam.g.shape = gUnknown_0804BEC8[w + h * 4];
    return (s8)sub_080151E8(gUnknown_0300477C[0x20], &e->oam);
}
