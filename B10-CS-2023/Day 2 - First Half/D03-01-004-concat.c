/*
  for given first name and last name 
  print the full name after you formed in the variable 
*/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include<cstdio>
#include<cstring>
int main() {
	char fname[50], lname[50], fullname[50];
	scanf("%s%s", fname, lname);

	strcpy(fullname, fname);
	strcat(fullname, " ");
	strcat(fullname, lname);

	printf("First Name:%s\n", fname);
	printf("Last Name:%s\n", lname);
	printf("Full Name:%s\n", fullname);
	return 0;
}
