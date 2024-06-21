// Yinxia Shi
// shi.yinx@northeastern.edu

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to encrypt the data */
void encrypt(char text[], int key) {
    // Add your code here
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        } 
    }
}

/* function to decrypt the data */
void decrypt(char text[], int key) {
    // Add your code here
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + 26 - key) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + 26 - key) % 26 + 'a';
        } 
    }
}

/*----------- Main program---------------*/
int main() {
    char text[20] ;
    int keyvalue = 3;
    /* Input string */
    printf("Enter the message:  ");
    scanf("%s", text);
    printf("text input   = %s\n", text);
    
    /* call function to encrypt the data */
    encrypt(text, keyvalue);
    printf("Encrypted value = %s\n", text);
    
    /* call function to decrypt the data */
    decrypt(text, keyvalue);
    printf("Decrypted value = %s\n", text);
    
    return 0;
}
