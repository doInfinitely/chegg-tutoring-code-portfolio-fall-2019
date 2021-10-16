#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

typedef struct name {
 char * str; // Just a string
} name;
typedef struct array_list {
 name * arr; // array of names
 int size, cap;
} array_list;
typedef struct full_list{
 array_list * aol; // array of (array)lists
 int size, cap;
} full_list;

void print_char_array(char array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%c", array[i]);
    }
}

bool equals(name student, char arg[], int size) {
    for(int i = 0; i < size; i++) {
        if (student.str[i] != arg[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int queries = 2;
    scanf("%d\n", &queries);
    array_list students;
    name names[queries];
    students.arr = names;
    students.size = 0;
    
    full_list symptoms;
    array_list aol[queries];
    symptoms.aol = aol;
    symptoms.size = 0;
    symptoms.cap = queries;
    /*for (int i = 0; i < queries; i++) {
        name syms[queries];
        symptoms.aol[i].arr = syms;
        symptoms.aol[i].size = 0;
        symptoms.aol[i].cap = queries;
    }*/


    students.cap = queries;
    for (int i = 0; i < queries; i++) {
        char input[203];
        char arg1[100];
        int size1;
        char arg2[100];
        int size2;
        for (int j = 0; j < 203; j++) {
            input[j] = ' ';
        }
        scanf("%[^\n]%*c", input);
        //printf("%s\n", input);
        char kind = input[0];
        //printf("%c\n", kind);
        int j = 0;
        while (input[j+2] != ' ') {
            arg1[j] = input[j+2];
            j++;
        }
        size1 = j;
        //printf("%s\n", arg1);
        j = 0;
        while (j < 100 && input[size1+3+j] != ' ') {
            arg2[j] = input[size1+3+j];
            j++;
        }
        size2 = j;
        //printf("%s\n", arg2);
        if (kind == 'u') {
            j = 0;
            bool found = false;
            while(j < students.size) {
                if(equals(students.arr[j], arg1, size1)) {
                    found = true;
                    break;
                }
                j++;
            }
            if (!found) {
                students.arr[students.size].str = malloc(sizeof(char)*size1);
                memcpy(students.arr[students.size++].str, arg1, sizeof(char)*size1);
                symptoms.aol[symptoms.size].arr = malloc(sizeof(name)*queries);
                symptoms.aol[symptoms.size++].size = 0;
            }
            symptoms.aol[j].arr[symptoms.aol[j].size].str = malloc(sizeof(char)*size2);
            memcpy(symptoms.aol[j].arr[symptoms.aol[j].size++].str, arg2, sizeof(char)*size2);
        } else if (kind == 'q') {
            bool student = true;
            char string[7] = "student";
            for (int j = 0; j < 7; j++) {
                if (string[j] != arg1[j]) {
                    student = false;
                    break;
                }
            }
            if (student) {
                j = 0;
                bool found = false;
                while(j < students.size) {
                    if(equals(students.arr[j], arg2, size2)) {
                        found = true;
                        break;
                    }
                    j++;
                }
                if (found) {
                    printf("%d\n", symptoms.aol[j].size);
                    for (int k = 0; k < symptoms.aol[j].size; k++) {
                        printf("%s\n", symptoms.aol[j].arr[k].str);
                    }
                }
            }
            bool symptom = true;
            char string2[7] = "symptom";
            for (int j = 0; j < 7; j++) {
                if (string2[j] != arg1[j]) {
                    symptom = false;
                    break;
                }
            }
            if (symptom) {
                char *has_symptom[queries];
                int num_has_symptom = 0;
                for (int k = 0; k < students.size; k++) {
                    for (int l = 0; l < symptoms.aol[k].size; l++) {
                        if (equals(symptoms.aol[k].arr[l], arg2, size2)) {
                            has_symptom[num_has_symptom++] = students.arr[k].str;
                            break;
                        }
                    }
                }
                printf("%d\n", num_has_symptom);
                for (int k = 0; k < num_has_symptom; k++) {
                    printf("%s\n", has_symptom[k]);
                }
            }
        }
    }
}
