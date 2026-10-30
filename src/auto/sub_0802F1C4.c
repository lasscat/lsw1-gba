
extern int sub_08008948(void *arg);
extern int sub_0802EC50(void *arg0, void *arg1);

void sub_0802F1C4(void *a, void *b)
{
    void *r4 = a;
    void *r5 = b;
    
    if (*(unsigned char *)((char *)r5 + 0x5c) != 1) {
        goto epilogue;
    }
    
    if (sub_08008948(r4) != 0) {
        goto epilogue;
    }
    
    if (*(unsigned char *)((char *)r4 + 0xf7) != 0) {
        goto epilogue;
    }
    
    sub_0802EC50(r4, r5);
    
epilogue:
    return;
}
