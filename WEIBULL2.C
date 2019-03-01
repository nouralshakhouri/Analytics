#include <stdio.h>
#include <math.h>
#define A 100
#define sen 0

/* print outline */

void
print_1(void)
{

	printf("******************************************************************************\n");
	printf("*  		 King Fahad University of Petrolum and Menirals   	     *\n");
	printf("* 	       College of Computer Scince and Systems Engineering            *\n");
	printf("*   	   		Systems Engineering Department                       *\n");
	printf("******************************************************************************\n");
	printf("*                		Weibull Analysis                             *\n");
	printf("******************************************************************************\n");
	printf("*   	        SE 480 (Reliability and Maintainability) Project   	     *\n");
	printf("*          		Instructor: Dr. Mohammad Ben Diah                    *\n");
	printf("*	      		   Done by Nour AL- Shakhouri                        *\n");
	printf("*                   		  12/13/1998                        	     *\n");
	printf("******************************************************************************\n");
}


/* Main Program*/


int
main(void)
{
	int n,i=1,sorted,pass,temp,s,f;
	double k[A], j=1,xsum=0, ysum=0, xysum=0, x2sum=0,x,y,z,top,bot,B,xmean,ymean,c,theta;

		{
			print_1();
		}
		

			printf("Enter the number of data on the test>");
			scanf("%d", &n);
			printf("Enter the number of faliures>");
			scanf("%d", &f);
                        printf("\nEnter the failuer time 1>");

				for(scanf("%lf", &k[i]); i<= f-1 ;scanf("%lf", &k[i])){
					printf("\nEnter the failuer time %d>",i+1);
					 i++;

       }

/*sorting the aray*/
{
	pass=1;
		do {
			sorted=1;
			for (s=1; s <= i-pass;++s){
				
				if(k[s] < k[s+1]){
					temp=k[s];
					k[s]=k[s+1];
					k[s+1]=temp;
					sorted=0;
					
				}
			}
			
			++pass;
			
		} while(!sorted);

}

/*calculate the parameters*/

		for(j=1;j <= f;++j){
                         
			y=log((k[j]));
			z=(1.0/(1.0-(j/(n+1.0))));
			x=log(log(z));
			xsum=xsum+x;
			ysum=ysum+y;
			xysum=xysum + (x*y);
			x2sum=x2sum + (x*x);

		}
		xmean=xsum/f;
		ymean=ysum/f;

		top=(f*xysum)-(xsum*ysum);
		bot=(f*x2sum)-(xsum*xsum);
		B=bot/top;

		c=ymean-(xmean/B);
		theta=exp(c);
		printf("Parameter eistimation:\n");
		printf("Scale parameter = %f\n",fabs(B));
		printf("Shape parameter = %f\n",theta);

                
		


	return(0);

}


