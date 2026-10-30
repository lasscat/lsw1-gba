int sub_080316D4(int idx);
void sub_08013DEC(unsigned int arg0, unsigned int arg1, unsigned int arg2);
extern unsigned short gUnknown_03003430[];

void sub_08021B00(void)
{
    if (sub_080316D4(0) != 0) {
        if ((gUnknown_03003430[2] & 0x30F) != 0)
            goto call;
    }
    if (sub_080316D4(1) == 0)
        return;
call:
    sub_08013DEC(3, 0, 0);
}
