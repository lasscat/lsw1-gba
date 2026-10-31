typedef struct {
    unsigned char pad00[0x0c];
    unsigned int f0c;
} Struct_0300368C;

extern Struct_0300368C gUnknown_0300368C;

int sub_08021078(void)
{
    unsigned int v = gUnknown_0300368C.f0c;
    if (v == 296 || v == 342 || v == 366 || v == 423 || v == 469 || v == 515 || v == 535 || v == 546 || v == 561)
        return 1;
    return 0;
}
