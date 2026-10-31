struct Sub08016B50Inner
{
    unsigned char pad[6];
    unsigned short count;
};

struct Sub08016B50Mid
{
    unsigned char pad[4];
    struct Sub08016B50Inner *inner;
};

struct Sub08016B50Obj
{
    unsigned char pad00[8];
    struct Sub08016B50Mid *mid;
    int x;
    int y;
    unsigned char pad14[8];
    int vx;
    int vy;
    unsigned char pad24[22];
    unsigned short flags;
    unsigned char pad3c[2];
    short timer;
    short accel;
    unsigned char pad42[10];
    signed char limit;
    signed char frame;
};

void sub_08016B50(struct Sub08016B50Obj *p)
{
    if (p->timer++ >= p->limit) {
        if (p->frame < p->mid->inner->count - 1) {
            p->frame++;
        } else if (p->flags & 4) {
            p->frame = 0;
        }
        p->timer = 0;
    }
    p->x += p->vx;
    p->y += p->vy;
    p->vy += p->accel << 4;
}
