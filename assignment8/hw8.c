// name:  Yinxia Shi
// email: shi.yinx@northeastern.edu

// format of document is a bunch of data lines beginning with an integer (rank which we ignore)
// then a ',' followed by a double-quoted string (city name)
// then a ',' followed by a double-quoted string (population) - ignore commas and covert to int; or (X) - convert to 0
// then a lot of entries that are ignored

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXSTRING 200

#define HASHTABLESIZE 400

int hash1(char* s) {
  return strlen(s) % HASHTABLESIZE;
}

int hash2(char* s) {
  int length = strlen(s);
  int total = 0;
  for (int i = 0; i < length; i++) {
    total += s[i];
  }
  return total % HASHTABLESIZE;
}

int hash3(char* s) {
  return s[0] * s[1] % HASHTABLESIZE;
}

typedef struct ListNode {
  char key[MAXSTRING];
  int val;
  struct ListNode* next;
} Node;

typedef struct TableCell {
  Node* head;
} Cell;

Cell* createHashtable() {
  Cell* newHashTable = malloc(HASHTABLESIZE * sizeof(Cell));
  for (int i = 0; i < HASHTABLESIZE; i++) {
    newHashTable[i].head = NULL;
  }
  return newHashTable;
}

void freeNode(Node* node) {
  while (node != NULL) {
    Node* next = node->next;
    free(node);
    node = next;
  }
}

void freeHashTable(Cell hashtable[]) {
  for (int i = 0; i < HASHTABLESIZE; i++) {
    freeNode(hashtable[i].head);
  }
  free(hashtable);
}

Node* createNewNode(char* key, int val) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->key, key);
  newNode->val = val;
  return newNode;
}

void insert(Cell* hashtable, char* key, int val) {
  Node* newNode = createNewNode(key, val);
  newNode->next = hashtable->head;
  hashtable->head = newNode;
}

void display(Cell hashtable[]) {
  printf("====================\n");
  for (int i = 0; i < HASHTABLESIZE; i++) {
    printf("TABLE[%d]:\n", i);
    Node* curr = hashtable[i].head;
    while (curr != NULL) {
      printf("key/value: [%s] / [%d]\n", curr->key, curr->val);
      curr = curr->next;
    }
    printf("\n");
  }
  printf("====================\n");
}

// finite state machine states
#define STARTSTATE 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define ACCEPTSTATE 10
#define ERRORSTATE 11

// check if a character c is a digit
bool isDigit(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  } else {
    return false;
  }
}

// append character c to string s
void appendChar(char* s, char c) {
  char charToStr[2];           // convert char to string
  charToStr[0] = c;
  charToStr[1] = '\0';         // put NUL to terminate string of one character
  strcat(s, charToStr);
}

int main() {

  char inputLine[MAXSTRING];   // temporary string to hold input line
  char cityStr[MAXSTRING];     // city name
  int  lineNum;                // line number (city rank)
  int  popInt;                 // population
  int  state;                  // FSM state
  int  nextChar;               // index of next character in input string
  char temp[MAXSTRING];        // temp string to build up extracted strings from input characters

  Cell* table1 = createHashtable();
  Cell* table2 = createHashtable();
  Cell* table3 = createHashtable();

  FILE* fp;
  fp = fopen("pop.csv", "r");

  if (fp != NULL) {
    fgets(inputLine, MAXSTRING, fp); // prime the pump for the first line

    // ***** BEGIN FINTITE STATE MACHINE *****

    // STARTSTATE: digit -> S1
    // S1: digit -> S1; , -> S2
    // S2: " -> S3
    // S3: !" -> S3; " -> S4
    // S4: , -> S5
    // S5: " -> S6; ( -> ACCEPTSTATE
    // S6: digit -> S6; , -> S6; " -> ACCEPTSTATE; 
    // ACCEPTSTATE: done!
    // else go to ERRORSTATE
    //
    while (feof(fp) == 0) {
      nextChar = 0;
      state = STARTSTATE; 
      strcpy(temp, "");       // temp = ""
      strcpy(cityStr, "");
      popInt = 0;

      if (nextChar >= strlen(inputLine)) {
        // if no input string then go to ERRORSTATE
        state = ERRORSTATE;
      } 

      while ((state != ERRORSTATE) && (state != ACCEPTSTATE)) {
        switch (state) {
        case STARTSTATE:
          // look a digit to confirm a valid line
          if (isDigit(inputLine[nextChar])) {
            state = S1;
            appendChar(temp, inputLine[nextChar]);
          } else {
            state = ERRORSTATE;
          }  
          break;
          // ADD YOUR CODE HERE

        case S1:
          if (isDigit(inputLine[nextChar])) {
            state = S1;
            appendChar(temp, inputLine[nextChar]);
          } else if (inputLine[nextChar] == ',') {
            state = S2;
          } else {
            state = ERRORSTATE;
          } 
          break;

        case S2:
          if (inputLine[nextChar] == '"') {
            state = S3;
          } else {
            state = ERRORSTATE;
          } 
          break;

        case S3:
          if (inputLine[nextChar] != '"') {
            state = S3;
            appendChar(cityStr, inputLine[nextChar]);
          } else {
            state = S4;
          }
          break;

        case S4:
          if (inputLine[nextChar] == ',') {
            state = S5;
          } else {
            state = ERRORSTATE;
          } 
          break;

        case S5:
          if (inputLine[nextChar] == '"') {
            state = S6;
          } else if (inputLine[nextChar] == '(') {
            state = ACCEPTSTATE;
          } else {
            state = ERRORSTATE;
          } 
          break;

        case S6:
          if (isDigit(inputLine[nextChar])) {
            state = S6;
            popInt = popInt * 10 + inputLine[nextChar] - '0';
          } else if (inputLine[nextChar] == ',') {
            state = S6;
          } else if (inputLine[nextChar] == '"') {
            state = ACCEPTSTATE;
          } else {
            state = ERRORSTATE;
          }
          break;

        case ACCEPTSTATE:
          // nothing to do - we are done!
          break;

        default:
          state = ERRORSTATE;
          break;
        } // end switch

        // advance input
        nextChar++;
      } // end while state machine loop

      // ***** END FINITE STATE MACHINE *****

      // process the line - print out raw line and the parsed fields
      // printf("> %.60s\n", inputLine);
      // printf("[%.30s]: %d\n", cityStr, popInt);
      int index1 = hash1(cityStr);
      int index2 = hash2(cityStr);
      int index3 = hash3(cityStr);

      insert(&(table1[index1]), cityStr, popInt);
      insert(&(table2[index2]), cityStr, popInt);
      insert(&(table3[index3]), cityStr, popInt);

      // get next line
      fgets(inputLine, MAXSTRING, fp);
    } // end while file input loop

    fclose(fp);

  } else {
    printf("File not found!\n");
  }

  printf("\n\n***** HASH TABLE 1 *****\n\n");
  display(table1);
  printf("\n\n***** HASH TABLE 2 *****\n\n");
  display(table2);
  printf("\n\n***** HASH TABLE 3 *****\n\n");
  display(table3);

  freeHashTable(table1);
  freeHashTable(table2);
  freeHashTable(table3);

  return 0;
}
