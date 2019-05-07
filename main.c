#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void addNewCustomer(int count);
void depositeMoney();
void withdrawMoney();
void displayAccount();
void sortedDetail();
void saveExit();
void fillArray();

/*Developer Gigum Bandara Rajaguru
 * Topic: Simple Bank
 *
 **/


int count=0,oneD,issystemup=0;
char *customerarray[100][6];
char *detailarray[4][4]={{"N","Normal","4%","500"},{"E","Eighteen Plus","4.5%","1000"},{"R","Rankakulu","5%","1500"},{"W","Wanitha","4.7%","1000"}};
int main() {
    if(issystemup==0) {
        fillArray();
        issystemup=1;
    }
    int optionnumber=0;
    printf("-------------ABC Bank System Menu-------------------");
    printf("\nOptions : \n 1.Add a new customer to the bank\n 2.Deposit money\n 3.Withdraw money\n 4.Display account details\n 5.sorted customer details\n 6.Save and exit\n");
    printf("\nEnter option number :");
    scanf("%d", &optionnumber);
    switch (optionnumber) {
        case 1:
            addNewCustomer(count);
            break;
        case 2:
            depositeMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            displayAccount();
            break;
        case 5:
            sortedDetail();
            break;
        case 6:
            saveExit();
            break;
        default:
            printf("=================\n");
            printf("Incorrect input \n");
            printf("==================\n");
            main();
            break;

    }


    return 0;
}
//Function to add new account
void addNewCustomer(int count){
    char decision,number[6],type[2],name[255],nic[11],balance[500];
    int turn;
    printf("Customer number %d :\n",count);
    printf("Enter Acc number :\n");
    scanf("%s", number);
    printf("Enter Acc type :\n");
    scanf("%s", type);
    printf("Enter Acc name :\n");
    scanf("%s", name);
    printf("Enter Acc NIC :\n");
    scanf("%s", nic);
    printf("Enter Acc Balance :\n");
    scanf("%s", balance);
    for (turn=0;turn<4;turn++){
        if (strcmp(type,detailarray[turn][0])==0){
            if(atof(detailarray[turn][3])<atof(balance)){
                customerarray[count+oneD][0]=number;
                customerarray[count+oneD][1]=type;
                customerarray[count+oneD][2]=nic;
                customerarray[count+oneD][3]=name;
                customerarray[count+oneD][4]=balance;
            }
            else{
                printf("Starting amount cap is not reached");
            }
        }
    }
    printf("Add another account(Y|N) :\n");
    scanf(" %c", &decision);
    if(decision=='Y' || decision=='y'){
        count=count+1;
        addNewCustomer(count);
    }
    else{
        printf("Process completed");
        main();
    }

}
//Function to deposite money
void depositeMoney(){
    char number[6],amount[10],buff[100];
    int checkcustomer;
    char *current;
    printf("Enter Account number :\n");
    scanf(" %s", number);
    for(checkcustomer=0;checkcustomer<100;checkcustomer++)
    {
        if( customerarray[checkcustomer][0]!=NULL)
        {
            int res = strncmp(number, customerarray[checkcustomer][0], 6);
            if (res == 0) {
                printf("Enter amount :\n");
                scanf("%s", amount);
                if(amount<0){
                    printf("invalid amount");
                    main();
                }
                current = customerarray[checkcustomer][4];
                double value=atof(current)+atof(amount);
                gcvt(value, 6, buff);
                customerarray[checkcustomer][4]=buff;
                printf("Process completed. Available amount %s",customerarray[checkcustomer][4]);
                main();
            }
            else{
                printf("invalid account ID");
            }
        }
    }

}
//function to withdraw money
void withdrawMoney(){
    char number[6],amount[10],buff[100];
    int checkcustomer;
    char *current;
    printf("Enter Account number :\n");
    scanf(" %s", number);
    for(checkcustomer=0;checkcustomer<100;checkcustomer++) {
        if (customerarray[checkcustomer][0] != NULL) {
            int res = strncmp(number, customerarray[checkcustomer][0], 6);
            if (res == 0) {
                printf("Enter amount :\n");
                scanf("%s", amount);
                if (amount < 0) {
                    printf("invalid amount");
                    main();
                }
                current = customerarray[checkcustomer][4];
                if ((atof(current) - atof(amount)) > 0) {//atof convert string to float
                    double value = atof(current) - atof(amount);
                    gcvt(value, 6, buff); //convert double to string(char array)
                    customerarray[checkcustomer][4] = buff;
                    printf("Process completed. Available amount %s", customerarray[checkcustomer][4]);
                    main();
                } else {
                    printf("Unable to withdraw. only %s in account.", current);
                }
            }
        }
    }

}
//function to display account
void displayAccount() {
    char number[6];
    int turn = 0;
    int checkcustomer;
    printf("Enter Account number :\n");
    scanf(" %s", number);
    for (checkcustomer = 0; checkcustomer < 100; checkcustomer++) {
        if (customerarray[checkcustomer][0] != NULL) {
            int res = strncmp(number, customerarray[checkcustomer][0], 6);
            if (res == 0) {
                for (turn = 0; turn < 4; turn++) {
                    if (strcmp(customerarray[checkcustomer][1],detailarray[turn][0])==0) {
                        printf("account number %s \n",customerarray[checkcustomer][0]);
                        printf("account type %s \n",customerarray[checkcustomer][1]);
                        printf("account Balance %s \n",customerarray[checkcustomer][4]);
                        printf("account title %s \n",detailarray[turn][1]);
                        printf("account interest rate %s \n",detailarray[turn][2]);
                        printf("account Min.Balance %s \n",detailarray[turn][3]);
                    }
                }
            }

        }
    }
    main();
}
//function to sort customer detail according to account type
void sortedDetail(){
    int checkcustomer,turn;
    for (turn = 0; turn < 4; turn++) {
        for (checkcustomer = 0; checkcustomer < 100; checkcustomer++) {
            if (customerarray[checkcustomer][0] != NULL) {
                if (strcmp(customerarray[checkcustomer][1],detailarray[turn][0])==0) {
                    printf("account number %s \n", customerarray[checkcustomer][0]);
                    printf("account type %s \n", customerarray[checkcustomer][1]);
                    printf("account NIC %s \n", customerarray[checkcustomer][2]);
                    printf("account Holder name %s \n", customerarray[checkcustomer][3]);
                }
            }
        }
    }
    main();
}
//function to save account data in text file
void saveExit(){
    FILE *fp;
    int prep;
    fp = fopen("./datafile.txt", "w");
    for(prep=0;prep<100;prep++) {
        if(customerarray[prep][0]!=NULL && customerarray[prep][1]!=NULL && customerarray[prep][2]!=NULL && customerarray[prep][3]!=NULL) {
            fprintf(fp,"%s \n",customerarray[prep][0]);
            fprintf(fp,"%s \n",customerarray[prep][1]);
            fprintf(fp,"%s \n",customerarray[prep][2]);
            fprintf(fp,"%s \n",customerarray[prep][3]);
            fprintf(fp,"%s \n",customerarray[prep][4]);
            printf("%s - Data stored.",customerarray[prep][0]);
        }
    }
    printf("System shutdown.");
    fclose(fp);
    exit(0);

}
//function to retrieve data from text file to array
void fillArray() {
    FILE *fp;
    int twoD=0;
    oneD=0;
    char str[900];
    char* filename = "./datafile.txt";
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file previous file %s . therefore new file created",filename);
        fp = fopen(filename, "w+");
        main();
    }
    while (!feof(fp)) {
        fgets(str, 100, fp);
        if(twoD>5 || twoD==5){
            twoD=0;
            oneD=oneD+1;
        }
        if(str!=NULL) {
            customerarray[oneD][twoD] = str;
            twoD++;
            strcpy(str, "");
        }

    }

    fclose(fp);

}
