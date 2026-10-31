extern void *sub_0804328C(int arg0, int arg1);
extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);

void *sub_080433C4(int arg0, int arg1)
{
    unsigned char *obj = sub_0804328C(arg0, arg1);
    unsigned char *entry = sub_08004A14(arg0, arg1);
    unsigned char v;

    if (entry[9] == 0)
        obj[0xe8] = 4;
    else
        obj[0xe8] = entry[9];
    if (entry[0xa] == 0)
        obj[0xeb] = 7;
    else
        obj[0xeb] = entry[0xa];
    if (entry[0xb] == 0)
        obj[0xec] = 9;
    else
        obj[0xec] = entry[0xb];
    obj[0xed] = 0;
    v = entry[0xc];
    obj[0xef] = v;
    return obj;
}
