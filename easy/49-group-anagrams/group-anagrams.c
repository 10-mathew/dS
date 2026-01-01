#include <stdlib.h>
#include <string.h>

void sortString(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char ***groups = malloc(strsSize * sizeof(char **));
    char **keys = malloc(strsSize * sizeof(char *));
    *returnColumnSizes = malloc(strsSize * sizeof(int));

    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        char *temp = strdup(strs[i]);
        sortString(temp);

        int found = -1;
        for (int g = 0; g < groupCount; g++) {
            if (strcmp(keys[g], temp) == 0) {
                found = g;
                break;
            }
        }

        if (found != -1) {
            int sz = (*returnColumnSizes)[found];
            groups[found] = realloc(groups[found], (sz + 1) * sizeof(char *));
            groups[found][sz] = strs[i];
            (*returnColumnSizes)[found]++;
            free(temp);
        } else {
            keys[groupCount] = temp;
            groups[groupCount] = malloc(sizeof(char *));
            groups[groupCount][0] = strs[i];
            (*returnColumnSizes)[groupCount] = 1;
            groupCount++;
        }
    }

    *returnSize = groupCount;
    return groups;
}
