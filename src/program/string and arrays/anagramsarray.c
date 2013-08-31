#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void anagrams(char **strs, int num) {
    int *used = (int *) calloc(num, sizeof(int)), i, j, k, l, len;
    int *anas = (int *) calloc(num, sizeof(int)), ana_num;
    for (i = 0; i < num; i++) {
        len = strlen(strs[i]);
        ana_num = 0;
        for (j = i+1; j < num; j++) {
            if (strlen(strs[j]) != len || used[j])
                continue;
            for (k = 0; k < len; k++) {
                for (l = 0; l < len; l++)
                    if (strs[j][l] == strs[i][k])
                        break;
                if (l == len)
                    break;
            }
            if (k == len)
                anas[ana_num++] = j;
        }
        if (ana_num > 0) {
            printf("anagrams: %s", strs[i]);
            for (k = 0; k < ana_num; k++) {
                printf(" %s", strs[anas[k]]);
                used[anas[k]] = 1;
            }
            printf("\n");
        }
    }
    free(used);
    free(anas);
}

int main() {
    char *strs[] = {"eat", "robe", "tea", "peels", "none", "ate",
"sleep", "bore", "one"};
    anagrams(strs, 8);
    return 0;
}
