#include <stdio.h>
#include <string.h>

char seating[15][20];
float row_price[15];

void display(){
   printf("-------------------------- Seating Chart----------------------------\n");
   printf("Seats: ");
   for(int i=0;i<20;i++)
       printf("%d ", i);
   printf("\n");
   for(int i=0;i<15;i++){
       if(i<10)
           printf("Row %d  ",i);
       else
           printf("Row %d ",i);
       for(int j=0;j<20;j++){
           if(j<10)
               printf("%d ",seating[i][j]);
           else
               printf("%d   ", seating[i][j]);
       }
       printf("\n");
   }
}

void row_price_details(){
   printf("Enter row wise fares:\n");
   for(int i=0;i<15;i++)
	   scanf("%f",&row_price[i]);
}

int main(){
   char choice;
   int i,j,row,seat;
   float revenue=0;
   for(i=0;i<15;i++){
       for(j=0;j<20;j++){
           seating[i][j]='*';
       }
   }
   display();
   row_price_details();
   do{
       printf("Enter row number and press enter then enter the seat number and press enter again:\n");
       scanf("%i",&row);
       scanf("%i",&seat);
       if(row<15||seat<<20){
           if(seating[row][seat]=='*'){
               revenue=revenue+row_price[row];
               seating[row][seat]='#';
               printf("Thank you for booking\n");
           }
           else{
               printf("The position you entered is'nt available\n See the seating chart to see available seats\n");
               display();
           }
       }
       else{
           printf("Invalid seat number or row number....\n");
       }
       printf("Do you want to buy another ticket?\nIf yes enter Y or y otherwise enter N or n\n");
       scanf("%c",&choice);
   }while(choice=='Y'||choice=='y');
   printf("After booking the seating chart:\n");
   display();
   printf("Total Revenue: %f\n", revenue);
}
