/*
Program Filename : Lee Kar Xin Final.c
Purpose          : Design and develop a Vegetables Ordering System for an organic vegetable farm.
*/

#include<stdio.h>
#include <string.h>
#pragma warning (disable :4996)

//defined constants
#define PACKAGE_A_PRICE 24.50
#define PACKAGE_B_PRICE 26.00
#define PACKAGE_C_PRICE 27.50
#define PACKAGE_D_PRICE 29.00
#define DELIVERY_FEES 5.00
#define DISCOUNT_RATE 0.15
#define MIN_AMOUNT_FOR_FREE_DELIVERY 80.00
#define MIN_AMOUNT_FOR_DISCOUNT 100.00

void menu();
void customer();

void main()
{
	//variable declarations
	int opt;

	//Input
	do {
		system("cls");
		printf("\n\n\t~~~ WELCOME TO GH ORGANIC VEGETABLE FARM! ~~~\n");
		printf("\t\t Vegetables Ordering System \n");
		printf("\n");
		printf("\t1.VIEW MENU\n");
		printf("\t2.CUSTOMER SECTION\n");
		printf("\t3.EXIT\n\n");
		printf("Enter your option :");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:menu(); break;
		case 2:customer(); break;
		case 3:printf("\tTHANK YOU, HAVE A NICE DAY!!\n\n"); break;
		default:printf("Invalid choice, Please Try again.\n\n");
		}
	} while (opt != 3);
	system("pause");
}

void menu()
{
	int opt;
	system("cls");
	printf("\n\n\t\t\t<<< MENU PRICES >>>\n");
	printf("------------------------------------------------------------------\n");
	printf("| Package A = kangkung,cabbage,Ladies finger,banana   = RM 24.50 |\n");
	printf("| Package B = Yam leaves,long bean,brinjal, guava     = RM 26.00 |\n");
	printf("| Package C = sanke beans,broccoli,spinach,papaya     = RM 27.50 |\n");
	printf("| Package D = bak choy,asparagus,brinjal,dragon fruit = RM 29.00 |\n");
	printf("------------------------------------------------------------------\n");
	printf("KINDLY REMINDER  : If purchase amount less than RM80.00, delivery fees will be charge as RM5.00\n");
	printf("\nDISCOUNT HERE!!! : If purchase amount of RM100.00 or more, a 15 percent discount is given :D\n\n");

	do {
		printf("1.RETURN TO HOME PAGE\n");
		printf("2.GO TO ORDER\n");
		printf("3.EXIT\n");
		printf("Enter your option: ");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:main();
		case 2:customer();
		case 3:printf("\tTHANK YOU, HAVE A NICE DAY!!\n\n"); break;
		default:printf("Invalid choice, Try again!\n\n");
		}
	} while (opt != 3);
	system("pause");
}

void customer()
{
	char customerName[31], contactNumber[15], yesno;
	char address1[31], address2[31], address3[31];
	int qtyPackageA, qtyPackageB, qtyPackageC, qtyPackageD, opt, ttlPackage, ttlA = 0, ttlB = 0, ttlC = 0, ttlD = 0, totalCustomers = 0;
	double ttlPackageA, ttlPackageB, ttlPackageC, ttlPackageD, amountA = 0, amountB = 0, amountC = 0, amountD = 0, ttlSalesAmount = 0;
	double subtotal, tax, total;
	do {
		totalCustomers++;
		system("cls");
		printf("\n\nCustomer No: %d\n", totalCustomers);
		printf("Enter surname : ");
		rewind(stdin);
		scanf("%[^\n]", &customerName);
		while (1) {
			int validSurname = 1;
			for (int i = 0; customerName[i] != '\0'; i++) {
				if (isdigit(customerName[i])) {
					validSurname = 0;
					break;
				}
			}

			if (validSurname) break;
			else {
				printf("Invalid surname! Surname should not contain numbers. Please enter again: ");
				rewind(stdin);
				scanf("%[^\n]", customerName);
			}
		}
		printf("Enter phone number :");
		scanf("%s", contactNumber);
		// Validate phone number
		while (!validatePhoneNumber(contactNumber)) {
			printf("Enter phone number again: ");
			rewind(stdin);
			scanf("%s", contactNumber); 
		}
		printf("Enter Address :\n");
		printf("      Address 1 :");
		rewind(stdin);
		scanf("%[^\n]", &address1);
		printf("      Address 2 :");
		rewind(stdin);
		scanf("%[^\n]", &address2);
		printf("      Address 3 :");
		rewind(stdin);
		scanf("%[^\n]", &address3);
		printf("\n");
		printf("Enter order quantity of package\n");
		printf("Package A RM24.50 :");
		rewind(stdin);
		while (scanf("%d", &qtyPackageA) != 1) {
			printf("Invalid input! Please enter an integer for Package A.\n");
			while (getchar() != '\n'); // Clear the input buffer
		}		printf("Package B RM26.00 :");
		rewind(stdin);
		while (scanf("%d", &qtyPackageB) != 1) {
			printf("Invalid input! Please enter an integer for Package B.\n");
			while (getchar() != '\n'); // Clear the input buffer
		}		printf("Package C RM27.50 :");
		rewind(stdin);
		while (scanf("%d", &qtyPackageC) != 1) {
			printf("Invalid input! Please enter an integer for Package C.\n");
			while (getchar() != '\n'); // Clear the input buffer
		}		printf("Package D RM29.00 :");
		rewind(stdin);
		while (scanf("%d", &qtyPackageD) != 1) {
			printf("Invalid input! Please enter an integer for Package D.\n");
			while (getchar() != '\n'); // Clear the input buffer
		}		printf("\n\n");
		printf("\t\tINVOICE\n");
		printf("=======================================\n");
		printf("Name      : Mr / Ms %11s\n", customerName);
		printf("Telephone : %s\n", contactNumber);
		printf("Address   : %s\n", address1);
		printf("            %s\n", address2);
		printf("            %s\n", address3);
		printf("\n");
		printf("\t\tCUSTOMER ORDERS\n");
		printf("====================================================\n");

		//Process
		ttlPackageA = qtyPackageA * PACKAGE_A_PRICE;
		ttlPackageB = qtyPackageB * PACKAGE_B_PRICE;
		ttlPackageC = qtyPackageC * PACKAGE_C_PRICE;
		ttlPackageD = qtyPackageD * PACKAGE_D_PRICE;

		//Output
		printf("\tPACKAGE A %d @ 24.50 = RM %.2f\n", qtyPackageA, ttlPackageA);
		printf("\tPACKAGE B %d @ 26.00 = RM %6.2f\n", qtyPackageB, ttlPackageB);
		printf("\tPACKAGE C %d @ 27.50 = RM %6.2f\n", qtyPackageC, ttlPackageC);
		printf("\tPACKAGE D %d @ 29.00 = RM %6.2f\n", qtyPackageD, ttlPackageD);
		printf("\n");

		//Process
		subtotal = ttlPackageA + ttlPackageB + ttlPackageC + ttlPackageD;

		if (subtotal >= 80)
			if (subtotal >= 100)
				total = subtotal - (subtotal * DELIVERY_FEES);
			else
				total = subtotal;
		else
			total = subtotal + DELIVERY_FEES;

		//output
		printf("\tPACKAGE Charge = RM %6.2f\n", subtotal);
		if (subtotal >= 80)
			printf("\tDelivery Fees  = RM   0.00\n");
		else
			printf("\tDelivery Fees  = RM %6.2f\n", DELIVERY_FEES);
		if (subtotal >= 100)
			printf("\tDiscounts      = RM %6.2f\n", DISCOUNT_RATE * subtotal);
		else
			printf("\tDiscounts      = RM   0.00\n");
		printf("\tTotal to pay   = RM %6.2f\n", total);
		printf("\n\n");
		printf("\tTHANK YOU, HAVE A NICE DAY!!\n\n");

		ttlA += qtyPackageA;
		ttlB += qtyPackageB;
		ttlC += qtyPackageC;
		ttlD += qtyPackageD;
		amountA += ttlPackageA;
		amountB += ttlPackageB;
		amountC += ttlPackageC;
		amountD += ttlPackageD;
		ttlPackage = ttlA + ttlB + ttlC + ttlD;
		ttlSalesAmount = amountA + amountB + amountC + amountD;

		printf("Next customer (Y=yes) : ");
		rewind(stdin);
		scanf("%c", &yesno);

	} while (yesno == 'y' || yesno == 'Y');


	printf("\n\n");
	printf("*****************************************\n");
	printf("\tDAILY SALES SUMMARY REPORT\n");
	printf("\tTotal Number of Customers =%d\n", totalCustomers);
	printf("%3s   %-11s   %10s\n", "PACKAGE", "Quantity Sold", "Sales Amount");
	printf("%3s   %-11s   %10s\n", "-------", "-------------", "------------");
	printf("%3s   %12d   %13.2f\n", "A", ttlA, amountA);
	printf("%3s   %12d   %13.2f\n", "B", ttlB, amountB);
	printf("%3s   %12d   %13.2f\n", "C", ttlC, amountC);
	printf("%3s   %12d   %13.2f\n", "D", ttlD, amountD);
	printf("%3s   %12s   %10s\n", "=======", "=============", "============");
	printf("%1s   %10d   %13.2f\n\n", "TOTAL", ttlPackage, ttlSalesAmount);
	printf("GREAT DAY!!! :D :D :D\n");
	system("pause");
}

int validatePhoneNumber(char* contactNumber) {
	int length = strlen(contactNumber);

	// Check if the phone number is at least 10 digits long
	if (length < 10) {
		printf("Invalid phone number. Please enter at least 10 digits.\n");
		return 0; // Invalid phone number
	}

	// Ensure the phone number contains only digits
	for (int i = 0; i < length; i++) {
		if (!isdigit(contactNumber[i])) {
			printf("Invalid phone number. It should only contain digits.\n");
			return 0; // Invalid phone number
		}
	}

	// If the phone number is valid (contains only digits and has at least 10 digits)
	return 1; // Valid phone number
}