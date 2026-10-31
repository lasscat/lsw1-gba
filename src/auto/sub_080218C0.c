void sub_08006DA4(int a0, int a1, int a2);
void sub_0801BE48(void);
void sub_08021980(void);
void sub_08031644(int, int);
int sub_080316D4(int);
extern unsigned int gUnknown_0300368C[];
extern unsigned int gUnknown_03002C50[];
extern unsigned short gUnknown_03003430[];

void sub_080218C0(void)
{
    if (gUnknown_0300368C[5]++ > 15) {
        if (gUnknown_03002C50[0x90 / 4] != 0) {
            sub_08006DA4(1, 0, 0);
            sub_08006DA4(2, 0, 0);
            sub_08031644(0, 0x3c);
            sub_0801BE48();
        }
    }
    if (sub_080316D4(0) != 0 || (gUnknown_03003430[0] & 0x30f) != 0)
        sub_08021980();
}
