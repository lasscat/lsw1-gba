void sub_08000494(void *node);
void sub_08000D00(void *arg0, int arg1);
int sub_08047BE4(int, int);

void sub_08035408(void *arg)
{
    unsigned short h;
    int v;
    ((unsigned int *)arg)[3] = (*(unsigned int **)((unsigned char *)arg + 0x68))[3];
    ((unsigned int *)arg)[4] = (*(unsigned int **)((unsigned char *)arg + 0x68))[4];
    h = *(unsigned short *)((unsigned char *)(*(unsigned int **)((unsigned char *)arg + 0x68)) + 0x11c);
    if (h == 15)
        v = 0;
    else {
        int t = sub_08047BE4(h << 16, 15);
        v = 5 - (int)((unsigned int)(t * 6) >> 16);
    }
    if ((unsigned int)v <= 5)
        sub_08000D00(arg, v);
    {
        unsigned int *b = *(unsigned int **)((unsigned char *)arg + 0x68);
        if ((*(unsigned int *)((unsigned char *)b + 0x58) & 2) != 0 || *(unsigned char *)((unsigned char *)b + 0xe1) != 0x34)
            sub_08000494(arg);
    }
}
