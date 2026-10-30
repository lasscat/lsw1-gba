extern void sub_08018220(void);
extern unsigned short sub_08047504(unsigned short arg0, void *arg1);
extern void sub_0801826C(void);

int sub_0801811C(int index, int count, void *ptr)
{
    unsigned int result = 0;
    int attempts;
    sub_08018220();
    if (count) {
        do {
            int retries = 3;
            do {
                result = sub_08047504(index, ptr);
                if (result == 0)
                    break;
                attempts = retries--;
            } while (attempts);
            if (result != 0)
                break;
            ptr += 8;
            index++;
            count--;
        } while (count);
    }
    sub_0801826C();
    return result == 0;
}
