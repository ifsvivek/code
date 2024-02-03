#include <stdio.h>

struct Student {
  char name[50];
  int roll_number;
  float marks;
};

union StudentUnion {
  char name[50];
  int roll_number;
  float marks;
};

void main() {
  struct Student student1 = {"Vivek", 187, 85.5};

  union StudentUnion student2 = {"Sharma", 123, 99};

  printf("Student name (structure): %s\n", student1.name);
  printf("Student roll number (structure): %d\n", student1.roll_number);
  printf("Student marks (structure): %.2f\n", student1.marks);

  printf("\nStudent name (union): %s\n", student2.name);
  printf("Student roll number (union): %d\n", student2.roll_number);
  printf("Student marks (union): %.2f\n", student2.marks);

  printf("\nSize of student structure: %d bytes\n", sizeof(student1));
  printf("Size of student union: %d bytes\n", sizeof(student2));
}
