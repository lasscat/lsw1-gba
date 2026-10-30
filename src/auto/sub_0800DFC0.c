void sub_0800DFC0(unsigned short *arg0, unsigned int arg1)
{
    unsigned short *ptr;
    unsigned int i = 1;
    unsigned int count = arg1 >> 1;
    
    if (i >= count)
        return;
    
    ptr = arg0;
    do {
        unsigned short val = ptr[1] + ptr[0];
        ptr[1] = val;
        ptr += 1;
        i++;
    } while (i < count);
}
