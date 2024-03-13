/*8. Simulate following File Organization Techniques
b) Two level directory
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct {
    char dname[10], fname[10][10];
    int fcnt;
} dir[10];
void main() {
    int i, ch, dcnt, k;
    char f[30], d[30];
    dcnt = 0;
    while (1) {
        printf("\n\n1. Create Directory\n2. Create File\n3. Delete File\n4. Search File\n5. Display\n6. Exit\nEnter your choice-- ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\nEnter name of directory -- ");
            scanf("%s", dir[dcnt].dname);
            dir[dcnt].fcnt = 0;
            dcnt++;
            printf("Directory created");
            break;
        case 2:
            printf("\nEnter name of the directory -- ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
                if (strcmp(d, dir[i].dname) == 0) {
                    printf("Enter name of the file -- ");
                    scanf("%s", dir[i].fname[dir[i].fcnt]);
                    dir[i].fcnt++;
                    printf("File created");
                    break;
                }
            if (i == dcnt)
                printf("Directory %s not found", d);
            break;
        case 3:
            printf("\nEnter name of the directory -- ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++) {
                if (strcmp(d, dir[i].dname) == 0) {
                    printf("Enter name of the file -- ");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++) {
                        if (strcmp(f, dir[i].fname[k]) == 0) {
                            printf("File %s is deleted ", f);
                            dir[i].fcnt--;
                            strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                            goto jmp;
                        }
                    }
                    printf("File %s not found", f);
                    goto jmp;
                }
            }
            printf("Directory %s not found", d);
        jmp:
            break;
        case 4:
            printf("\nEnter name of the directory -- ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++) {
                if (strcmp(d, dir[i].dname) == 0) {
                    printf("Enter the name of the file -- ");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++) {
                        if (strcmp(f, dir[i].fname[k]) == 0) {
                            printf("File %s is found ", f);
                            goto jmp1;
                        }
                    }
                    printf("File %s not found", f);
                    goto jmp1;
                }
            }
            printf("Directory %s not found", d);
        jmp1:
            break;
        case 5:
            if (dcnt == 0)
                printf("\nNo Directory's ");
            else {
                printf("\nDirectory\tFiles");
                for (i = 0; i < dcnt; i++) {
                    printf("\n%s\t\t", dir[i].dname);
                    for (k = 0; k < dir[i].fcnt; k++)
                        printf("\t%s", dir[i].fname[k]);
                }
            }
            break;
        default:
            exit(0);
        }
    }
}

/*
Output:

1. Create Directory
2. Create File
3. Delete File
4. Search File
5. Display
6. Exit
Enter your choice-- 1

Enter name of directory -- DIR1
Directory created

1. Create Directory
2. Create File
3. Delete File
4. Search File
5. Display
6. Exit
Enter your choice-- 1

Enter name of directory -- DIR2
Directory created

1. Create Directory
2. Create File
3. Delete File
4. Search File
5. Display
6. Exit
Enter your choice-- 2

Enter name of the directory -- DIR1
Enter name of the file -- A1
File created

1. Create Directory
2. Create File
3. Delete File
4. Search File
5. Display
6. Exit
Enter your choice-- 2

Enter name of the directory -- DIR1
Enter name of the file -- A2
File created

1. Create Directory
2. Create File
3. Delete File
4. Search File
5. Display
6. Exit
Enter your choice-- 2

Enter name of the directory -- DIR2
Enter name of the file -- B1
File created

1. Create Directory
2. Create File
3. Delete File
4. Search File
5. Display
6. Exit
Enter your choice-- 5

Directory       Files
DIR1                    A1      A2
DIR2                    B1

1. Create Directory
2. Create File
3. Delete File
4. Search File
5. Display
6. Exit
Enter your choice-- 4

Enter name of the directory -- DIR
Directory DIR not found

1. Create Directory
2. Create File
3. Delete File
4. Search File
5. Display
6. Exit
Enter your choice-- 3

Enter name of the directory -- DIR1
Enter name of the file -- A2
File A2 is deleted

1. Create Directory
2. Create File
3. Delete File
4. Search File
5. Display
6. Exit
Enter your choice-- 6
*/