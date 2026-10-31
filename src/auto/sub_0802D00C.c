extern unsigned char gUnknown_03006B1C[];
extern unsigned char gUnknown_08052F34[];
int sub_08017400(int a, int b);
int sub_0801BEB8(int a);

void sub_0802D00C(void)
{
    int v = 0x45F;
    unsigned char *p = gUnknown_03006B1C + v;
    if (*p == 0) {
        sub_0801BEB8(gUnknown_08052F34[sub_08017400(0, 3)]);
        *p = sub_08017400(200, 300);
    } else {
        (*p)--;
    }
}
