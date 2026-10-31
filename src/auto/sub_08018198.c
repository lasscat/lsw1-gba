extern void sub_08018220(void);
extern unsigned short sub_080475B4(unsigned short arg0, void *arg1);
extern unsigned short sub_08047728(unsigned short arg0, void *arg1);
extern void sub_0801826C(void);

int sub_08018198(int index, int count, void *ptr)
{
    unsigned int result = 0;
    int attempts;
    sub_08018220();
    if (count) {
        do {
            int retries = 3;
            do {
                sub_080475B4(index, ptr);
                result = sub_08047728(index, ptr);
                if (result == 0)
                    break;
                attempts = retries--;
            } while (attempts);
            if (result == 0) {
                ptr += 8;
                index++;
                count--;
            } else {
                break;
            }
        } while (count);
    }
    sub_0801826C();
    return result == 0;
}
