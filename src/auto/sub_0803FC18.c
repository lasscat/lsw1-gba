struct S0803FC18_Inner {
    int unk0[3];
    int x;
    int y;
};

struct S0803FC18_Outer {
    int unk0[14];
    struct S0803FC18_Inner *u38;
    struct S0803FC18_Inner *u3c;
};

extern struct S0803FC18_Outer *gUnknown_030072F0;
void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);

void sub_0803FC18(void)
{
    struct S0803FC18_Inner *s = gUnknown_030072F0->u38;
    sub_08000F78((int *)s, s->x, s->y + 0x00A00000, 0x14);
    s = gUnknown_030072F0->u3c;
    sub_08000F78((int *)s, s->x, s->y + 0x00A00000, 0x14);
}
