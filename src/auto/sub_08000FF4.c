void sub_08000F78(void *, unsigned int, unsigned int, unsigned int);

void sub_08000FF4(void *arg0, unsigned short arg1, unsigned short arg2, unsigned int arg3)
{
    sub_08000F78(arg0, (unsigned int)arg1 << 16, (unsigned int)arg2 << 16, arg3);
}
