struct U080179C0 { int a; int b; };
struct S080179C0
{
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0C;
    int unk_10;
    struct U080179C0 unk_14[3];
    int unk_2C[4];
    int unk_3C;
    int unk_40;
    int unk_44;
    int unk_48;
};
extern struct S080179C0 gUnknown_03004980;
extern void sub_080137A0(void *arg0, int arg1, int arg2);
void sub_0802C164(void *arg0);

void sub_080179C0(int arg0)
{
    if (gUnknown_03004980.unk_2C[arg0]) {
        gUnknown_03004980.unk_3C = gUnknown_03004980.unk_10;
        gUnknown_03004980.unk_40 = 0;
        sub_0802C164(&gUnknown_03004980.unk_14[arg0]);
    } else {
        sub_080137A0(&gUnknown_03004980.unk_14[arg0], 0, 8);
    }
}
