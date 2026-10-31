extern void *sub_0804328C(int arg0, int arg1);
extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);

void *sub_08043454(int arg0, int arg1)
{
    unsigned char *obj = sub_0804328C(arg0, arg1);
    unsigned char *entry = sub_08004A14(arg0, arg1);
    unsigned char v;

    if (entry[9] == 0)
        obj[0xe8] = 4;
    else
        obj[0xe8] = entry[9];
    if (entry[0xa] == 0)
        obj[0xe9] = 7;
    else
        obj[0xe9] = entry[0xa];
    if (entry[0xb] == 0)
        obj[0xea] = 7;
    else
        obj[0xea] = entry[0xb];
    v = entry[0xc];
    obj[0xef] = v;
    return obj;
}
