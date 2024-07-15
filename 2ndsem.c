#include <stdio.h>
#include <stdlib.h>
//global variables for plane and seat classes
int plane[100] = {0}; //array representing plane seats
int firstCounter = 0; //counter for first class seats
int secondCounter = 50; //counter for economy class seats
struct details
{
	int aadhaar;
	int passport;
	int price;
};
struct details det[100];
//function prototypes
void firstClass (int a);
void economyClass(int b);
void notEnoughSeats(int c);
//function main begins program execution
int main(void)
{   
    printf("\n======================================");
	printf("\n======================================");
	printf("\n||                                  ||");
	printf("\n||                                  ||");
	printf("\n||     WELCOME TO KLS AIRLINES      ||");
	printf("\n||                                  ||");
	printf("\n||                                  ||");
	printf("\n======================================");
	printf("\n======================================");
	printf("\n\n\n\n");
	printf("  ====   Admin                ticket ====\n");
	printf("  ====        Vending Machine       ====");
	printf("\n\n");
	printf("________HOPE YOU HAVE A GREAT TIME_______");
	printf("\n\n\n\n=========================================\n\n\n");
	printf("\n This module takes you through the tickey reservation of the flight \n\n\n");
                         
    printf("||=====\\       =====█████╗░███████╗██╗███╗░░██╗░██████╗░  ██████╗░███████╗███████╗\n");
    printf("||      //    ||       ||\n");
    printf("||======╝     ||        ||\n");
    printf("||       \\  ||       ||\n");
    printf("||        //  ||      || \n");
    printf("||=======//    ||====||\n");
	printf("  \n\n\n       Please Enter -1 when finished booking\n\n\n\n");
	
	
	
	
    int option; //holds user option value
    puts("Airplane Ticket Reservation System.");
    puts("1. First Class");
    puts("2. Economy Class");
    puts("-1.To exit");
    printf("%s", "Your option is: " ); //prompts user for input
    scanf("%d", &option);

    //assign seats based on user input
    while (option != -1){ //terminates if user inputs -1
        if (option > 2) { //alerts user of an an invalid option
            printf("%s", "Invalid option!\n");
        }//end if
        notEnoughSeats(option);
        if (firstCounter <= 49){ //ensures this does not get executed when it is greater than 4
        firstClass(option);
        }//end if
        if (secondCounter <= 99){ //ensures this does not get executed when it is greater than 9
        economyClass(option);
        }//end if
        puts("1. First Class");
        puts("2. Economy Class");
        puts("-1.To exit");
        printf("\n%s", "Your option is: " ); //prompts user for input
        scanf("%d", &option); //gets user input
    }//end while
    printf("======================================================================\n");
    printf("|       Seat number       Aadhaar         Passport      price        |\n");
    printf("======================================================================\n");
    for (int i =0; i<=99 ;i++)
    {
         printf("       %d                %d              %d            %d\n",i+1,det[i].aadhaar,det[i].passport,det[i].price);
    }
}//end main

//function to calculate seats for first class
void firstClass (int a){
    if (a == 1){
        if (plane[firstCounter] == 0){ //sets array position
            plane[firstCounter] = firstCounter + 1; //sets array value at position
          printf("Your boarding pass is: First Class, Seat %d\n", plane[firstCounter]); //prints first class boarding pass
		  printf("Enter your aadhaar number :");
		  scanf("%d",&det[firstCounter].aadhaar);
		  printf("\nEnter your passport number :");
		  scanf("%d",&det[firstCounter].passport);
		  printf("The price per seat of the 1st class seat is 16,000");
		  det[firstCounter].price=160000;
		  printf("\nTicket confirmed \n\n=========================================\n");
          firstCounter ++ ;//increments the counter for first class
        }// end second if
    }//end first if
}//end function

//function to calculate seats for economy class
void economyClass (int b){
    if (b == 2){
        if (plane[secondCounter] == 0){ //sets array position
            plane[secondCounter] = secondCounter + 1; //sets array value at position
            printf("Your boarding pass is: Economy Class, Seat %d\n", plane[secondCounter]); //prints economy class boarding pass
            printf("Enter your aadhaar number :");
		    scanf("%d",&det[secondCounter].aadhaar);
		    printf("\nEnter your passport number :");
		    scanf("%d",&det[secondCounter].passport);
		    printf("The price per seat of the 1st class seat is 20,000");
		    det[secondCounter].price=20000;
		    printf("\nTicket confirmed \n\n=========================================\n");
		    secondCounter ++ ; //increments the counter for economy class
        }// end if
    }//end if
}//end function

//function to present alternative if the seats are full
void notEnoughSeats (int c) {
    char answer; //holds yes or no value
    //if first class is full
    if (c == 1 && firstCounter > 49) {
        printf("%s", "Seats are full. Do you want to book Economy Class (y/n)?: "); //prompts user for input
        scanf("%c", &answer);
            if (answer == 'y' || answer == 'Y') { //if the user answered yes
                if (secondCounter < 99){
                    economyClass(2); //books user for economy class
                }// end if
                if (secondCounter >= 99){
                    puts("Sorry, seats are full. Please try again for next flight.");
                }//end if
        }//end while
        if (answer == 'n' || answer == 'N') { //if the user answered no
        puts("Next flight is in 3 hours.");
        } //end else if
    }// end if
    if (c == 2 && secondCounter > 99) {
        printf("%s", "Seats are full. Do you want to book First Class (y/n)?: "); //prompts user for input
        scanf("%c", &answer);
            if (answer == 'y' || answer == 'Y') { //if the user answered yes
                if (firstCounter < 49)
                    firstClass(1); //books user for first class
                if (firstCounter >= 49){
                    puts("Sorry, seats are full. Please try again for next flight.");
                }//end if
        }//end while
        else if (answer == 'n' || answer == 'N') { //if the user answered no
        puts("Next flight is in 3 hours.");
        } //end else if
    }// end if
}//end function
