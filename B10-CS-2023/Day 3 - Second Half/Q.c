#include <stdio.h>
int f(void) {
}
int main(void) {
int i;
i = f();
printf("%d",i);
return 0;
}


int f(void);


int (*pf)(void);

pf = f;

int x = (*pf)()

