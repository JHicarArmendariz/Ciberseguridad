#include <stdio.h>

void main(int argc, char **argv){
int count;
char buf[3];

printf("Insert a number:");
gets(buf);
count = atoi(buf);

if(count==10){
	printf("Counter=10 \n");
}else{
	printf("Counter not 10 \n");
}

}
