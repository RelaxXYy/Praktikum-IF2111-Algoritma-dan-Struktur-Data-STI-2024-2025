#include <stdio.h>

int main() {
    char pola[100], kata[100];
    scanf("%s", pola);
    scanf("%s", kata);
    int i = 0, ans=1;
    while ((pola[i] != '\0') && (ans==1)) {
        if (pola[i] != '*') {
            if (pola[i] != kata[i]){
                ans=0;
            }
        }
        i++;
    }
    printf("%d\n", ans);
}
