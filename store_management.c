#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct details{
    int outfit_id;
    int outfit_price;
    char outfit_name[100];
    char outfit_company[100];
};


int *ptr;
int size=0;


//void menu function
void menu();
//void sub-menu functions
void add();
void view();
void cancel();
void calculate();
void exitt();
void rating();
void arrange();


struct details o[15]={{101,2599,"Printed Lenin shirts","U.S POLO ASSN"},{102,1679,"Slim Fit Casual shirts","LeVI'S"},{103,1999,"Tailored Fit shirts","TOMMY HILFIGER"},{104,2789,"Regular Fit Casual shirts","JACK&JONES"},{105,1599,"Slim Fit checked Casual shirts","WROGN"},{106,4955,"Kanjeevaram Saree","MITERA"},{107,2599,"Banaras saree","Saree mall"},{108,3999,"Printed saree","Kalakari india"},{109,4999,"Jamdani Saree","Laa Calcutta"},{110,2108,"Mysore silk saree","Gosiriki"},{111,1599,"Culotte Jumpsuit","Uptownie Lite"},{112,1399,"Girls Net Dress","Cherry Crumble"},{113,899,"Girls Printed Playsuit","LilPicks"},{114,369,"Round Neck T-Shirt","max"},{115,799,"T-Shirts","HELLCAT"}};



int main()
{   printf("\n\n");
    printf("                           SRM Clothing Store\n");
    printf("                                       -Feel the heaven of comfort\n");
    printf("\n\n");
	printf("\t\t Welcome,user ");
    printf("\n\n Press any key to continue...");
    getch();
    menu();
}

void menu()
{
    system("cls");
    int choice;
    printf("\n           ........* Clothing Store Management System  ........* ");
	printf("                                                                                          ");
	printf("                                                                                          ");
	//Displaying Sub-Menu Options.
	printf("\n                1. Add Items");
	printf("\n                2. View Items");
	printf("\n                3. Delete Items");
    printf("\n                4. Calculate Bill");
	printf("\n                5. Exit!");
	 printf("                                                                                          ");
	printf("                                                                                          ");
	printf("\n           The Joy Of Dressing is an ART......\n");
    printf("\n\n              Enter your choice[1-5] : ");
    scanf("%d",&choice);
    printf("                                                                                          ");
	printf("                                                                                          ");
    //accepting choice from user to select any sub-menu option
    switch(choice)
    {
        case 1:
        add();
        break;
        case 2:
        view();
        break;
        case 3:
        cancel();
        break;
        case 4:
        calculate();
        break;
        case 5:
        exitt();
        break;
        default:
        printf("Invalid Choice,Please Try Again...");
        getch();
        menu();
    }
}



void add()
{
    system("cls");
    //selection of available goods can be done here
    printf(" ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^.^.^.^.^.^.^\n");
    printf("outfit Id                    outfit                    Company                   Price\n");
    printf(" ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^ ^.^.^.^.^.^.^.^\n");
    printf("101                      Printed Lenin shirts               U.S POLO ASSN        2,599 \n");
    printf("102                      Slim Fit Casual shirts             LeVI'S               1,679 \n");
    printf("103                      Tailored Fit shirts                TOMMY HILFIGER       1,999 \n");
    printf("104                      Regular Fit Casual shirts          JACK&JONES           2,789 \n");
    printf("105                      Slim Fit checked Casual shirts     WROGN                1,599 \n");
    printf("106                      kanjeevaram saree                  MITERA               4,955 \n");
    printf("107                      Banaras saree                      Saree mall           2,599 \n");
    printf("108                      Printed saree                      Kalakari india       3,999 \n");
    printf("109                      Jamdani Saree                      Laa Calcutta         4,999 \n");
    printf("110                      Mysore silk saree                  Gosiriki             2,108 \n");
    printf("111                      Culotte Jumpsuit                   Uptownie Lite        1,599 \n");
    printf("112                      Girls Net Dress                    Cherry Crumble       1,399 \n");
    printf("113                      Girls Printed Playsuit             LilPicks             899   \n");
    printf("114                      Round Neck T-Shirt                 max                  369   \n");
    printf("115                      T-Shirts                           HELLCAT              799   \n");
    printf("\n");
    printf("Please select the outfits of your wish\n");
    printf("\nMaximum of 6 outfits can be selected\n");
    int num,a,i,found;
    if(size==0)
    {
        printf("\nEnter The Item Code : ");
        scanf("%d",&num);
        for(i=0;i<15;i++)
        {
            if(num==o[i].outfit_id)
            {
                found=1;
                break;
            }
            else
            {
                found=0;
            }
        }
        if(found==1)
        {
            //storing the selected items dynamically
            ptr=(int *)malloc(1*sizeof(int));
            printf("\n\n%d Item Added To Cart....",num);
            ptr[size]=num;
            size++;
        }
        else
        {
            printf("\noutfit With ID : %d Not In Our Shop..\n",num);
        }
    }
    else
    {
        printf("Enter The Item Code : ");
        scanf("%d",&num);
        for(i=0;i<15;i++)
        {
            if(num==o[i].outfit_id)
            {
                found=1;
                break;
            }
            else
            {
                found=0;
            }
        }
        if(found==1)
        {
            ptr=(int *)realloc(ptr,size+1);
            printf("\n\n%d Item Added To Cart....",num);
            ptr[size]=num;
            size++;
        }
        else
        {
            printf("\noutfit With ID : %d Not In Our Shop..\n",num);
        }
    }
    printf("\n\nPress 1 Add More Items & 0 to go to Menu : ");
    scanf("%d",&a);
    if(a==1)
    {
        add();
    }
    else
    {
        menu();
    }
}

void view()
{
    //Displaying the selected items
    arrange();
    int i,a,j;
    system("cls");

     printf(",;,;,;,;,;,;,;,;,;,; Selected Items ,;,;,;,;,;,;,;,;,;,; ");
     printf("\n\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<15;j++)
        {
            if(ptr[i]==o[j].outfit_id)
            {
                        printf("outfit %d\n",i+1);
                        printf("A.outfit ID      : %d\n",o[j].outfit_id);
                        printf("B.outfit Name    : %s\n",o[j].outfit_name);
                        printf("C.outfit Company : %s\n",o[j].outfit_company);
                        printf("D.outfit Price   : %d\n\n",o[j].outfit_price);

            }
        }
    }
    printf("\nPress 1 Add More Items & 0 to go to Menu : ");
    scanf("%d",&a);
    if(a==1)
    {
        add();
    }
    else
    {
        menu();
    }
}

void cancel()
{
    //undesired items can be deleted from selected items
    system("cls");
    int id,a,found,i,j;
    printf(" >< >< >< >< >< Delete Items  >< >< >< >< >< >< ");
    printf("\n\n");
    printf("Enter the outfit ID to be Deleted : ");
    scanf("\n%d",&id);
    for(i=0;i<size;i++)
    {
        if(id==ptr[i])
        {
            found=1;
            break;
        }
        else
        {
            found=0;
        }
    }
    if(found==1)
    {
        for(i=0;i<size;i++)
    {
        if(ptr[i]==id)
        {
            for(j=i;j<size;j++)
            {
                ptr[j]=ptr[j+1];
            }
        }
    }
    printf("\noutfit With ID %d removed Sucessfully.\n",id);
    ptr=(int *)realloc(ptr,size-1);
    size--;
    }
    else
    {
        printf("The outfit With ID:%d Does Not Exists In Your Cart...\n",id);
    }
    printf("\nPress 1 Add More Items & Press 2 to Delete more Items & 0 to go to Menu : ");
    scanf("%d",&a);
    if(a==1)
    {
        add();
    }
    else if(a==2)
    {
        cancel();
    }
    else
    {
        menu();
    }
}

void calculate()
{
    //accepting the quantity of items and calculating the bill.
    system("cls");
    int quantity,i,j;
    float total=0,discount_amount,tax=0,Final=0,amount=0;
    long long int  num;
    printf("\nInput the quantity of Outfits and Accept the details from Customer\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<15;j++)
        {
            if(o[j].outfit_id==ptr[i])
            {
                printf("\nEnter The Quantity Of outfit %d : ",ptr[i]);
                scanf("%d",&quantity);
                amount=amount + o[j].outfit_price*quantity;
            }
        }
    }
    printf("\nTotal(Excluding discount)    : %.2f\n",amount);
                if(amount<5000)
                {
                  printf("You are not eligible to avail discount since your Total purchase is less than 5000\n");
                  tax=0;
                  printf("Tax Amount = %.2f/-",tax);
                  Final=tax+amount;
                }
                else if(amount>5000 && amount<10000)
                {
                  discount_amount = (10*amount)/100;
                  total = amount-discount_amount;
                  printf("\nTotal(Including discount)    : %.2f\n",total);
                  tax=total*2/100;
                  printf("\nTax Amount = %.2f/-\n",tax);
                  Final=tax+total;
                }
                else if(amount>10000 && amount<50000)
                {
                    discount_amount = (20*amount)/100;
                    total = amount-discount_amount;
                    printf("\nTotal(Including discount)    : %.2f\n",total);
                    tax=total*5/100;
                    printf("\nTax Amount = %.2f/-\n",tax);
                    Final=tax+total;
                }
                else if(amount>50000)
                {
                    discount_amount = (30*amount)/100;
                    total = amount-discount_amount;
                    printf("\nTotal(Including discount)    : %.2f\n",total);
                    tax=total*7/100;
                    printf("\nTax Amount = %.2f/-\n",tax);
                    Final=tax+total;
                }





    printf("\n");
    //accepting customer details like phone number
    printf("Mobile Number : ");
    scanf("%llu",&num);
    printf("\n");
    printf("Press any key to continue...");
    getch();
    system("cls");
     //bill generation
    printf("$...$...$...$...Bill...$...$...$...$");
    printf("\n\n");
    printf("\nCustomer Mobile Number              : %llu\n",num);
    printf("\nTotal Bill(Including Tax &Discount) : %.2f\n",Final);
    printf("\nGeneration of bill has been completed successfully");
    printf("\n");
    printf("\n\nThank You For Shopping With Us....\n\n");
    getch();
    system("cls");
    printf("Press any key to proceed!");
    rating();
}

void rating()
{
    int rate;
    //rating
    printf("\n\n****Rating***");
    printf("\nPlease rate your shopping experience with us on scale of [1-5]\n");
    printf("1.Bad\n");
    printf("2.Moderate\n");
    printf("3.Good\n");
    printf("4.Very Good\n");
    printf("5.Excellent\n");
    scanf("%d",&rate);
    if(rate==1)
    {
      printf("Sorry for the inconvinience caused....We are very sorry for it...\n");
      printf("Thanks for your valuable feedback...\n");
      printf("Thanks for shopping with us...");
    }
    else if(rate==2)
    {
        printf("We understand the problem troubled you...we are sorry for it...\n");
        printf("Thanks for your valuable feedback...\n");
        printf("Thanks for shopping with us...");
    }
    else if(rate==3 || rate==4 || rate==5)
    {
        printf("Thanks for your valuable feedback...\n");
        printf("Thanks for shopping with us...");
    }
    else
    {
       printf("Invalid choice...Please Try Again.");
    rating();
    }

    getch();
    system("cls");
    exitt();
}


void exitt()
{
    system("cls");
    printf("----------> Project done by <----------");
    printf("\nOmkar Ghongade");
    printf("\nCSE-B 2020-2024")
    printf("\n");
    printf("------------> The END <----------\n\n\n\n\n\n\n\n\n\n\n");
    exit(0);
}

void arrange()
{
    int i,j,swap;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(ptr[i]>ptr[j])
            {
                swap=ptr[j];
                ptr[j]=ptr[i];
                ptr[i]=swap;
            }
        }
    }
}
