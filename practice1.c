#include <stdio.h>
#include <math.h>


int main(){
	float x1 = 0.0f;
	float y1 = 0.0f;
	float x2 = 0.0f;
	float y2 = 0.0f; 
	float i = 0.0f;
	float m = 0.0f;
	
	printf("Enter an ordered pair of numbers:\n");
	scanf("(%f,%f),(%f,%f)",&x1,&y1,&x2,&y2);
	
	m = (y2 - y1)/(x2 - x1);
	
	printf("X  Y\n");

	for(i=x1; i<=x2 ;i++){
		double y = m*(i-x1)+y1;
		printf("%0.2f  %0.2f\n", i,y);		
	}

	
	
	return 0;
}
