extern unsigned int gUnknown_03006A1C[];
void sub_08008354(unsigned char *a, unsigned int b, int c);

void sub_0802481C(unsigned char *a)
{
    if (a == 0)
        return;
    switch (a[0]) {
    case 0:
        sub_08008354(a, gUnknown_03006A1C[0], 0);
        break;
    case 1:
        sub_08008354(a, gUnknown_03006A1C[1], 0);
        break;
    case 2:
        sub_08008354(a, gUnknown_03006A1C[2], 0);
        break;
    }
}
