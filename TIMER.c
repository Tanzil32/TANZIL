#include <stdio.h>

#define CYCLE 5

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
    #define sleep(x) Sleep(x * 1000)
#else
    #include <unistd.h>
    #define CLEAR "clear"
#endif

int main() {
    int hour, minute, second;
    printf("Enter Hour Minute Second: ");
    scanf("%d%d%d", &hour, &minute, &second);

    int h = 0, m = 0, s = 0;

    while (1) {
        system(CLEAR);
        printf("\n\n****** Timer ****\n\n\n");
        printf("      %.2d:%.2d:%.2d\n\n", h, m, s);
        printf("\n\n***************************");

        if (h == hour && m == minute && s == second) {
            break;
        }

        s++;
        if (s == CYCLE) {
            m++;
            s = 0;
        }
        if (m == CYCLE) {
            h++;
            m = 0;
        }

        sleep(1);
    }

    printf("\n\nTimer Finished!\n");
    return 0;
}

