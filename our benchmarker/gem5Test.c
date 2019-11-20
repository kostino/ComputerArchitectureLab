#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
	

	//array rand 0-10
	int array[1000];
	int even=0;
	

	for(int i=0;i<1000;i++){
		array[i]=((int)(rand())%10+1);
		
		printf("array[%d] = %d\t",i,array[i]);
		 if(array[i]%2==0){
                        even++;
		 	printf("EVEN");
		 }
		 printf("\n");
		
		
	}

		
	
	printf("Total Even: %d\n",even);

	return 0;


}
