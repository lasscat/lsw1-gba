typedef struct SpriteLike SpriteLike;
struct SpriteLike {
    int unk0[3];
    int x;
    int y;
};

typedef struct RootLike RootLike;
struct RootLike {
    int unk0[2];
    SpriteLike *a;
    SpriteLike *b;
    SpriteLike *c;
    SpriteLike *d;
    SpriteLike *e;
};

extern int gUnknown_03003694;
extern unsigned char gUnknown_0300332C[];
extern RootLike *gUnknown_03006AEC;

int sub_08011FC4(int *counter, unsigned int limit, unsigned int value, unsigned int flag, int index);
int sub_0801BEB8(int arg0);
void sub_08000D7C(void *arg0, int arg1, int arg2);

void sub_080261D0(void)
{
    if (sub_08011FC4(&gUnknown_03003694, 3, 4, 1, gUnknown_0300332C[0xB9]) != 0) {
        sub_0801BEB8(0);
        if (gUnknown_03003694 == 3) {
            sub_08000D7C(gUnknown_03006AEC->a, 0x3B0000, gUnknown_03006AEC->a->y);
            sub_08000D7C(gUnknown_03006AEC->b, 0x610000, gUnknown_03006AEC->b->y);
        } else {
            sub_08000D7C(gUnknown_03006AEC->a, 0x950000, gUnknown_03006AEC->a->y);
            sub_08000D7C(gUnknown_03006AEC->b, 0xBB0000, gUnknown_03006AEC->b->y);
        }
    }
}
