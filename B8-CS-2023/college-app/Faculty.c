#include "Faculty.h"
#include <stdio.h>

 void AddFaculty(){
	 if(!isLoggedIn){
		printf("Unauthorized Access");
		return;
	 }
	 printf("Facult is added into db");
 }
