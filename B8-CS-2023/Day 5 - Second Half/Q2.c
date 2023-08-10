#include<stdio.h>

int main() {
  int (*ptr)[10];
  int a[10];
  printf("%u\n", ptr);
  printf("%u\n", ptr+1);
  printf("%u\n", a);
  printf("%u\n", a+1);
  printf("%u\n", &a);
  printf("%u\n", (&a)+1);
  ptr = &a;
  printf("%u\n",(*(ptr+1))-1);
  //print last element address of "a" using "ptr"
}

// &a -> pointer to array (address of entire array)
// *&a -> addr of base element 
// (&a) + 1 -> address of after array | addr of next to last element 
// (*((&a) + 1))-1