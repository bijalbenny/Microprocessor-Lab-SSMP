#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void main(){
 int choice;
 while(true){
    printf("Enter the choice\n 1)FCFS 2)SJF 3)Priority 4)Exit \n");
    scanf("%d",&choice);
    switch(choice){
    		case 1:{
    			int limit;
    			printf("\nEnter the number of process : ");
    			scanf("%d",&limit);
    			int process[limit],bt[limit],tat[limit],wt[limit],i;
    			 printf("Enter the processes and their corresponding burst time : \n");
    			for(i=0;i<limit;i++)
    			     scanf("%d%d",&process[i],&bt[i]);
    			wt[0]=0;
    			tat[0]=bt[0];
    			float tot_wt = wt[0],tot_tat=tat[0];
    			for(i=1;i<limit;i++){
    			     wt[i]=wt[i-1]+bt[i-1];
    			     tat[i]=tat[i-1]+bt[i];
    			     tot_wt+=wt[i];
    			     tot_tat+=tat[i];
    			}
    			printf("GANTT CHART:\n");
			for(i=0;i<limit;i++)
			    printf("\tP%d",process[i]);
			 printf("\n");
		        for(i=0;i<limit;i++)
			     printf("     %d\t",wt[i]);
			     printf("   %d",tat[limit-1]);
			     printf("\n");
			printf("Process\tBT\tWT\tTAT\n");
			for(i=0;i<limit;i++)
			     printf("%d\t%d\t%d\t%d\n",process[i],bt[i],wt[i],tat[i]);
			printf("Total WT = %.2f , Avg WT = %.2f\nTotal TAT = %.2f , Avg TAT = %.2f\n",tot_wt,tot_wt/limit,tot_tat,tot_tat/limit);
    			break;
    		     }
    		case 2: {
    			int limit;
    			printf("\nEnter the number of process : ");
    			scanf("%d",&limit);
    			int process[limit],bt[limit],tat[limit],wt[limit],i,temp;
    			 printf("Enter the processes and their corresponding burst time : \n");
    			for(i=0;i<limit;i++)
    			     scanf("%d%d",&process[i],&bt[i]);
    			for(i=0;i<limit-1;i++){
    			    for(int j=i+1;j<limit;j++){
    			      if(bt[i]>bt[j]){
    			         temp = bt[i];
    			         bt[i] = bt[j];
    			         bt[j] = temp;
    			         
    			         temp = process[i];
    			         process[i] = process[j];
    			         process[j] = temp;
    			      }
    			    }
    			   }
    			wt[0]=0;
    			tat[0]=bt[0];
    			float tot_wt = wt[0],tot_tat=tat[0];
    			for(i=1;i<limit;i++){
    			     wt[i]=wt[i-1]+bt[i-1];
    			     tat[i]=tat[i-1]+bt[i];
    			     tot_wt+=wt[i];
    			     tot_tat+=tat[i];
    			}
    			printf("GANTT CHART:\n");
			for(i=0;i<limit;i++)
			    printf("\tP%d",process[i]);
			 printf("\n");
		        for(i=0;i<limit;i++)
			     printf("     %d\t",wt[i]);
			     printf("   %d",tat[limit-1]);
			     printf("\n");
			printf("Process\tBT\tWT\tTAT\n");
			for(i=0;i<limit;i++)
			     printf("%d\t%d\t%d\t%d\n",process[i],bt[i],wt[i],tat[i]);
			printf("Total WT = %.2f , Avg WT = %.2f\nTotal TAT = %.2f , Avg TAT = %.2f\n",tot_wt,tot_wt/limit,tot_tat,tot_tat/limit);
    		        break;
      
                      }
                 case 3: {
                 	int limit;
    			printf("\nEnter the number of process : ");
    			scanf("%d",&limit);
    			int process[limit],bt[limit],tat[limit],wt[limit],priority[limit],i,temp;
    			 printf("Enter the processes and their corresponding burst time and priority : \n");
    			for(i=0;i<limit;i++)
    			     scanf("%d%d%d",&process[i],&bt[i],&priority[i]);
    			for(i=0;i<limit-1;i++){
    			    for(int j=i+1;j<limit;j++){
    			      if(priority[i]>priority[j]){
    			         
    			         temp = priority[i];
    			         priority[i] = priority[j];
    			         priority[j] = temp;
    			      
    			         temp = bt[i];
    			         bt[i] = bt[j];
    			         bt[j] = temp;
    			         
    			         temp = process[i];
    			         process[i] = process[j];
    			         process[j] = temp;
    			      }
    			    }
    			   }
    			wt[0]=0;
    			tat[0]=bt[0];
    			float tot_wt = wt[0],tot_tat=tat[0];
    			for(i=1;i<limit;i++){
    			     wt[i]=wt[i-1]+bt[i-1];
    			     tat[i]=tat[i-1]+bt[i];
    			     tot_wt+=wt[i];
    			     tot_tat+=tat[i];
    			}
    			printf("GANTT CHART:\n");
			for(i=0;i<limit;i++)
			    printf("\tP%d",process[i]);
			 printf("\n");
		        for(i=0;i<limit;i++)
			     printf("     %d\t",wt[i]);
			  printf("   %d",tat[limit-1]);
			  printf("\n");
			printf("Process\tBT\tPriority\tWT\tTAT\n");
			for(i=0;i<limit;i++)
			     printf("%d\t%d\t%d\t%d\t%d\n",process[i],bt[i],priority[i],wt[i],tat[i]);
			printf("Total WT = %.2f , Avg WT = %.2f\nTotal TAT = %.2f , Avg TAT = %.2f\n",tot_wt,tot_wt/limit,tot_tat,tot_tat/limit);
			break;
                 }
                 case 4: exit(0);
                 default : printf("Invalid choice");
                 
       }
    }
   }
    
