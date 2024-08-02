// shi.yinx@northeastern.edu
// Yinxia Shi

#include <stdio.h>
#include <string.h>

int compression(char arr[], int n, char res[]) {
    //insert your code here
    int size = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] != arr[i + 1]) {
            res[size] = arr[i];
            size++;
            if (count > 1) {
                size += sprintf(&res[size], "%d", count);
            }
            count = 0;
        }
    }
    res[size] = '\0';
    return size;
}

int main() {
    char a[] = "aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r, n = strlen(a); //n is the size of input array
    r = compression(a, n, res);
    printf("length of the compressed string:%d\n", r);
    printf("Compressed result: %s\n", res);
    return 0;
}
