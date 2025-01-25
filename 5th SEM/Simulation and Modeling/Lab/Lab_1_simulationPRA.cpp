/* Lab Work: 1
  C  Program for Simulation of Page replacement algorithms: 
 -FIFO Page replacement Algorithm
 -LRU Page Replacement Algorithm 
 -Optimal Page Replacement Algorithm 
 Find the best Algorithm.
 */
 // Programmed by: Dabbal S. Mahara

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void FIFO(char [],char [],int,int);
void lru(char [],char [],int,int);
void opt(char [],char [],int,int);

int main()
{
   int ch,YN=1,i,l,frame;
   char F[10],s[25];
   FILE *fptr;
  
   printf("\n\n\tEnter the no of empty frames:");
   scanf("%d",&frame);
  
   if ((fptr=fopen("input.txt","r"))==NULL)
   {
       printf("Error! opening file");
       exit(1);     //  EXIT_FAILURE, Program exits if file pointer returns NULL. */
   }
   fscanf(fptr,"%s",s);
   l = strlen(s);
  // printf("\n\n\tEnter the length of the string: ");
  // scanf("%d",&l);
  // printf("\n\n\tEnter the string: ");
   //scanf("%s",s);
   
   do
    {
     
      printf("\n\n\t*********** MENU ***********");
      printf("\n\n\t1:FIFO\n\n\t2:LRU\n\n\t3:OPT\n\n\t4:EXIT");
      printf("\n\n\tEnter your choice: ");
      scanf("%d",&ch);
     
      switch(ch)
       {
      case 1:
          FIFO(s,F,l,frame);
          break;
      case 2:
          lru(s,F,l,frame);
          break;
      case 3:
          opt(s,F,l,frame);
          break;
      case 4:
          exit(0);  //EXIT_SUCCESS
       }
      printf("\n\n\tDo u want to continue IF YES PRESS 1\n\n\tIF NO PRESS 0 : ");
      scanf("%d",&YN);
    }while(YN==1);
    return(0);     //EXIT_SUCCESS
}

//FIFO: Replaces the page that appeared first 
void FIFO(char s[],char F[],int l,int f)
{
  
   int i,j=0,k,flag=0,cnt=0;
   for(i=0;i<f;i++)
    {
             F[i]=-1;
    }
   printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
        {
            if(F[k]==s[i])   // page found in the frame memory
            {
              flag=1;        // indicate this by flag =1
       	   	  break;	
			}
        }

       if(flag==1) // page hit case
	   {
    		flag=0;
      		printf("\n\t%c\t",s[i]);
      		for(k=0;k<f;k++)
       		{
        		printf("   %c",F[k]);
       		}
     	 	printf("\tNo page-fault");
       }
   	   else // page miss case
		{
      		printf("\n\t%c\t",s[i]);
      		if(j<f)  // slot is available in the memory frame
			  {
			    F[j]=s[i]; //insert the ith page in the jth frame
      			j++;       //increment frame number
      		  }
      		else         //frame is full ; no space available, have to replace first page
      		 {
      		  	for(k=0;k<f-1;k++)  // shift pages in frame towards the base 
      		  		F[k]=F[k+1];
      		  	F[k]=s[i];
      		  	
			 }
			  
      		for(k=0;k<f;k++)
       		{ 
       			 printf("   %c",F[k]);
      		}
    		printf("\tPage-fault%d",cnt+1);
    	    cnt++;
    	}	
      
    } // End of outer for loop
    printf("\n\n\t Total number of page faults:\t%d",cnt);
}

//LRU: Replaces the least recently used page from page frame
void lru(char s[],char F[],int l,int f)
{
   int i,j=0,k,m,flag=0,cnt=0,top=-1; //top is for indicating recently used
   for(i=0;i<f;i++)
    {
             F[i]=-1;
    }
   printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
       {
         if(F[k]==s[i]) // page found in memory
         {
            flag=1;
            break;
         }
       }
       if(flag==1) // page hit case
	   {
    		flag=0;
      		printf("\n\t%c\t",s[i]);
      		for(m=k;m<top;m++)  //shift all pages towards base of the frame memory
            {
       		  F[m]=F[m+1];
            }
            F[top]=s[i];   // insert the newly appeared page at the top
      		for(k=0;k<f;k++)
       		{
        		printf("   %c",F[k]);
       		}
     	 	printf("\tNo page-fault");
       }
       else   // page miss occured
	   {
       	    printf("\n\t%c\t",s[i]);
       		if(j!=f )  // frame memory slots are available
       		{
           		top++;     //increment top since top=-1 initially
				F[top]=s[i];  // insert the page at the top
           		j++;    // increment frame number
       		}
       		else    // no frame slots are available
  	        {
                for(k=0;k<top;k++)   // shift the pages upto top towards the base 
          		{
        	    	F[k]=F[k+1];
                }
                 F[top]=s[i];  // new page is inserted at the top position
            }
       
       		for(k=0;k<f;k++)
   		 	{
   			  printf("   %c",F[k]);
    		 }
       	 	printf("\tPage-fault%d",cnt+1);
      	 	cnt++;
        }
	}
	printf("\n\n\t Total number of page faults:\t%d",cnt);
 }

//optimal: this algorithm replaces the page that will not be 
// used for longest period of time in future
void opt(char s[],char F[],int l,int f)
{
   int i,j=0,k,m,flag=0,cnt=0,temp[10];

	for(i=0;i<f;i++)
    {
             F[i]=-1;
    }
   printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   
   for(i=0;i<10;i++) 
     temp[i]=0;

   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
    	{
     		 if(F[k]==s[i])
      			  flag=1;
   		 }
  	   if(flag==1) // page hit case
	    {
    		flag=0;
      		printf("\n\t%c\t",s[i]);
      		for(k=0;k<f;k++)
       		{
        		printf("  %c",F[k]);
       		}
     	 	printf("\tNo page-fault");
        }
	   else   // page miss occured
	   {
       	    printf("\n\t%c\t",s[i]);
       		if(j!=f )  // frame memory slots are available
       		{
           		F[j]=s[i];  // insert the page at the top
           		j++;    // increment frame number
       		}
       		else    // no frame slots are available
  	        {
               for(m=0;m<f;m++) // find the length of next use for the pages in the frames
          	   {
          		  for(k=i+1;k<l;k++)    // 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
           		   {                   // 7 0 1 in page frame and new page read is 2
          			if(F[m]!=s[k])    //search until the F[0] == s[k] i.e. until the page
					{                 // in the frame is found in the input string 
                       temp[m]=temp[m]+1;  //and count number of pages in between. 
                     }                  //then, temp[0] = 13 , temp[1] = 0, temp[2]=9
                     else
                         break;
                   }
               }
      		   m=0;
     		   for(k=0;k<f;k++) // finding page to replace
        	    {	
           			if(temp[k]>temp[m])
        			{	
          				m=k;
        			}
                }		
        		  F[m]=s[i]; // inserting the new page into page frame to be replaced
       		} //end of inner else

    		for(k=0;k<f;k++) // printing the pages in the frames
      		 {
             	 printf("  %c",F[k]);
      		 }
            printf("\tPage-fault %d",cnt+1);
            cnt++;
    	} //end of outer else
       
        for(k=0;k<10;k++)
           temp[k]=0;
    } //end of outer for loop
   printf("\n\n\t Total number of page faults:\t%d",cnt);
} //end of function
