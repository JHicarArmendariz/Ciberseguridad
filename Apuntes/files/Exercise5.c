#include <stdio.h>

void doFirst(int c, int d){
	if(c*d>10){
		printf("It is a multiplication %d",c);
	}else{
		printf("It is a multiplication %d",d);
	}
}

void doSecond(int h, int k){
	int addition = h + k;
	printf("It is an addition %d",addition);
}


void main(){
int a=1;

if(a==1){
	doFirst(5,30);
}else{
	doSecond(6,40);
}

}
