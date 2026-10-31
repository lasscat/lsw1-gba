void sub_08000BF4(void *arg0, unsigned int arg1);
void sub_08009F6C(int a, int b, int c);
void sub_08009F98(int a, int b, int c);
extern unsigned int gUnknown_03006B14;

struct D { char u[149]; unsigned char b95; char p[6]; unsigned int w9c; char q[21]; unsigned char bb5; };
struct S { char u[8]; unsigned int w8; unsigned char bc; };

void sub_0800074C(struct D *arg0, struct S *arg1)
{
    unsigned char t = arg1->bc;
    arg0->b95 = t;
    arg0->w9c = 0;
    sub_08000BF4(arg0, (unsigned int)arg1);
    {
        unsigned int v = arg1->w8;
        if (v != 0) {
            if ((gUnknown_03006B14 & 0x10) != 0) {
                sub_08009F6C(v, (arg0->bb5 >> 4) << 4, 16);
            } else {
                sub_08009F98(v, (arg0->bb5 >> 4) << 4, 16);
            }
        }
    }
}
