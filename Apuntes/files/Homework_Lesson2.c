
#include <stdio.h>
int doit(int var1, int var2){
	int getit = 20;
	int getitAux=var1+var2;
	return (getit * getitAux);
}

void main(int argc, char **argv){
int var=1;
int var1=10;
int result=0;

if(var>var1){
	printf("Higher number required \n");
}else{
	result = doit(var1, var1);
}

if(10000 < result){
	printf("YOU HAVE GOT IT! \n");
}else{
	printf("DO NOT GET IT! \n");
}

}
