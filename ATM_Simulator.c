#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

#define MAX_TRANSACTIONS 100

struct Transaction 
{
    char type;  // 'D' for deposit, 'W' for withdrawal
    float amount;
    int id;
};

void logo();
void menu();
void receipt();
void denominations();
void Pin(char ch[]);
int trans_id();
void save_TransactionHistory(struct Transaction trans[], int cnt);
void display_TransactionHistory();

void waiting(unsigned int mseconds)
	{
		clock_t goal = mseconds + clock();
		while (goal > clock());
	}

void main()
{
    FILE *fp;
    FILE *fc;
    FILE *fb;
    FILE *fx;
    FILE *fy;
    FILE *ft;


    system("color 3F");
    int option,count=0,amount=1,i;
    int balance;
    int ATM_balance = 20000;
    int continueTransaction = 1;
    int cnt=0;
    char pin[5],enteredPin[5],temp[10];
    char ch;
    struct Transaction trans[MAX_TRANSACTIONS];
    fp=fopen("pin.txt","r");
    fscanf(fp,"%s",pin);
    fclose(fp);

    fb=fopen("User_balance.txt","r");
    fscanf(fb,"%s",temp);
    fclose(fb);
    balance=atoi(temp);

    logo();
    //printf("\n\n\n");

    printf("\n\n\t\t   Please INSERT your Card [Press ENTER to insert card]: ");
    scanf("%c",&ch);

    logo();
    while(strcmp(pin,enteredPin) != 0)
    {
        printf("\n\n\t\t   Please type Personal Identification Number(PIN) : ");
        Pin(enteredPin);

        if(strcmp(pin,enteredPin) != 0)
        {
            Beep(610,500);
            printf("\n\n\t\t   Invalid PIN. Please try again!");
            waiting(1000);
            logo();
        }
        count++;
        if(count==3 && strcmp(pin,enteredPin) != 0)
        {
            printf("\n\n\t\t   Account locked for security reasons.\n\n");
            exit(0);
        }
    }
    //label:
    while(continueTransaction == 1)
    {

        menu();
        scanf("%d",&option);

        int flag = 0;
        switch(option)
        {
            case 1:
                while(amount % 50 != 0)
                {
                    fx=fopen("User_balance.txt","w");
                    denominations();
                    scanf("%d",&amount);
                    if(amount % 50 != 0)
                    {
                        Beep(610,500);
                        printf("\n\t\t   The amount should be a multiple of 50.\n");
                        waiting(1500);
                        continue;
                    }

                    if(balance < amount)
                    {
                        Beep(610,500);
                        printf("\n\t\t   Sorry insufficient account balance.\n");
                        waiting(1500);
                        amount = 1;
                        continue;
                    }
                    else if(ATM_balance < amount)
                    {
                        Beep(610,500);
                        printf("\n\t\t   Sorry insufficient ATM balance.\n");
                        waiting(1500);
                        amount = 1;
                        continue;
                    }
                    else
                    {
                        balance -= amount;
                        ATM_balance -= amount;
                        receipt();
                        printf("\n\t\t\t\t\t|TRANSACTION:\t\t     CASH WITHDRAWAL  |");
      						 	    printf("\n\t\t\t\t\t|AMOUNT:\t\t     %d.00\t      |",amount);
      						 	    printf("\n\t\t\t\t\t|CURRENT BAL:\t\t     %d.00\t      |",balance);
      							    printf("\n\t\t\t\t\t|AVAILABLE BAL:\t\t     %d.00\t      |",balance);
      							    printf("\n\t\t\t\t\t|\t\t\t\t\t      |\n\t\t\t\t\t|\tDO NOT SHARE THE PIN TO OTHERS.\t      |");
                        printf("\n\t\t\t\t\t|\t\t\t\t\t      |");
      							    printf("\n\t\t\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|\n");
      							    waiting(10000);
                        fprintf(fx,"%d",balance);
                        fclose(fx);


                    //printf("\n\t\t   You have withdrawn Rs.%d. Your new balance is %.2f\n",amount,balance);
                        trans[cnt].amount=amount;
                        trans[cnt].type='W';
                        trans[cnt].id=trans_id();
                        save_TransactionHistory(trans, cnt);
                        amount=1;
                        cnt++;
                        break;
                    }
                }
                break;

            case 2:
                fy=fopen("User_balance.txt","w");
                logo();
                printf("\n\t\t   Please enter the amount : ");
                scanf("%d",&amount);
                balance += amount;
                receipt();

                printf("\n\t\t\t\t\t|TRANSACTION:\t\t     CASH DEPOSIT     |");
                printf("\n\t\t\t\t\t|AMOUNT:\t\t     %d.00\t      |",amount);
                printf("\n\t\t\t\t\t|CURRENT BAL:\t\t     %d.00\t      |",balance);
                printf("\n\t\t\t\t\t|AVAILABLE BAL:\t\t     %d.00\t      |",balance);
                printf("\n\t\t\t\t\t|\t\t\t\t\t      |\n\t\t\t\t\t|\tDO NOT SHARE THE PIN TO OTHERS.\t      |");
                printf("\n\t\t\t\t\t|\t\t\t\t\t      |");
                printf("\n\t\t\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|\n");
                waiting(10000);
                fprintf(fy,"%d",balance);
                fclose(fy);


                //printf("\n\n\t\t   You have deposited Rs.%d. Your new balance is %.2f\n",amount,balance);
                trans[cnt].amount=amount;
                trans[cnt].type='D';
                trans[cnt].id=trans_id();
                save_TransactionHistory(trans, cnt);
                amount = 1;
                cnt++;
                break;

            case 3:
                //printf("\n\t\t   Your balance is Rs.%.2f\n",balance);
                receipt();

                printf("\n\t\t\t\t\t|TRANSACTION:\t\t     BALANCE CHECK    |");
                //printf("\n\t\t\t\t|AMOUNT:\t\t      %d.00\t      |",amount);
                printf("\n\t\t\t\t\t|CURRENT BAL:\t\t     %d.00\t      |",balance);
                printf("\n\t\t\t\t\t|AVAILABLE BAL:\t\t     %d.00\t      |",balance);
                printf("\n\t\t\t\t\t|\t\t\t\t\t      |\n\t\t\t\t\t|\tDO NOT SHARE THE PIN TO OTHERS.\t      |");
                printf("\n\t\t\t\t\t|\t\t\t\t\t      |");
                printf("\n\t\t\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|\n");


                waiting(10000);

                break;

            case 4:
                  fc=fopen("pin.txt","w");
                  logo();
                  char newPin[5]="a",checkPin[5]="b";
                  count=0;
                  while(flag==0)
                  {
                    printf("\n\t\t   Enter your old PIN : ");
                    Pin(enteredPin);

                    if(strcmp(pin,enteredPin) != 0)
                    {
                      Beep(610,500);
                      printf("\n\n\t\t   Invalid PIN. Please try again!\n\n");
                      waiting(2000);
                      logo();
                      count++;
                      if(count==3)
                      {
                        Beep(610,500);
                        printf("\n\n\t\t   Too many attempts taken! Please try again later.");
                        waiting(2000);
                        break;
                      }
                    }
                    else
                    {
                      logo();
                      count=0;
                      while(strcmp(newPin,checkPin) != 0)
                      {
                        printf("\n\t\t   Enter your new PIN : ");
                        Pin(newPin);

                        if(strcmp(pin,newPin) == 0)
                        {
                          Beep(610,500);
                          printf("\n\t\t   New pin cannot be the same as the exisiting PIN. Please enter a new PIN!\n\n");
                          waiting(1500);
                          logo();
                          count++;
                          if(count==3)
                          {
                            Beep(610,500);
                            printf("\n\n\t\t   Too many attempts taken! Please try again later.");
                            waiting(2000);
                            break;
                          }
                          continue;
                        }
                        printf("\n\t\t   Enter your new PIN again : ");

                        Pin(checkPin);

                        if(strcmp(newPin,checkPin) != 0)
                        {
                          Beep(610,500);
                          printf("\n\t\t   Invalid PIN. Please try again!\n\n");
                          waiting(1500);
                          logo();
                          count++;
                          if(count==3)
                          {
                            Beep(610,500);
                            printf("\n\n\t\t   Too many attempts taken! Please try again later.");
                            waiting(2000);
                            break;
                          }
                        }
                        else
                        {
                          fprintf(fc,"%s",newPin);
                          printf("\n\t\t   PIN changed successfully.\n\n");
                          for(i=0;i<4;i++)
                          {
                            pin[i]=newPin[i];
                          }
                          waiting(3000);
                          fclose(fc);
                        }
                      }
                      flag=1;
                    }
                  }

                  break;

            case 5:
                  display_TransactionHistory();
                  waiting(10000);
                  break;

            case 6:
                  printf("\n\n\n\t\t   ===========================*Thank you for banking with us*===============================\n\n");
                  FILE *ft = fopen("Transaction_History.txt", "w");
                  exit(0);
                  break;

            default:
                Beep(610,500);
                printf("\n\t\t   Invalid Option. Please try again!\n\n");
                waiting(1000);
        }


    }

}
void logo()
{
  time_t now;
  time(&now);
  system("cls");
  printf("\n");
  printf("\t\t\t              **             ****************        **               ** \n");
  printf("\t\t\t            **  **                  **               ** *           * ** \n");
  printf("\t\t\t          **      **                **               **   *       *   ** \n");
  printf("\t\t\t        **          **              **               **     *   *     ** \n");
  printf("\t\t\t      *****************             **               **       *       ** \n");
  printf("\t\t\t      **             **             **               **               ** \n");
  printf("\t\t\t      **             **             **               **               ** \n");
  printf("\t\t\t      **             **             **               **               ** \n");
  printf("\t\t\t      **             **             **               **               ** \n\n\n");

  printf("\t\t\t\t\t\t %s\n",ctime(&now));

  printf("\n\t\t   =============================*Welcome to ATM Simulator*==================================\n\n\n");

}

void receipt()
{
    system("cls");
    logo();
    //char date[9];
    //char time[9];
    time_t t;
    t = time(NULL);
    struct tm tm;
	  tm = *localtime(&t);
    //printf("Current Time: %d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    //printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    //_strdate(date);
    //_strtime(time);
    printf("\n\n\t\t\t\t\t PRINTING RECEIPT . . .\n");
    waiting(3000);
    system("cls");
    logo();

    printf("\n\n\n\t\t\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANK ORDER \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|");
    printf("\n\t\t\t\t\t|\t\t\t\t\t      |");
    printf("\n\t\t\t\t\t|\t     ATM TRANSACTION RECORD\t      |");
    printf("\n\t\t\t\t\t|\t\t\t\t\t      |");
    printf("\n\t\t\t\t\t|DATE:\t\t\t     %d-%d-%d\t      |", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("\n\t\t\t\t\t|TIME:\t\t\t     %d:%d:%d\t      |", tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("\n\t\t\t\t\t|LOCATION:\t\t     BANGALORE        |");
    printf("\n\t\t\t\t\t|CARD NUM:\t\t     ************6587 |");
}

void menu()
{
  system("cls");
  logo();
  printf("\n\t\t   ===============================*Available Transactions*==================================");
  printf("\n\n\t\t   [ 1 ] Withdraw");
  printf("\n\t\t   [ 2 ] Deposit");
  printf("\n\t\t   [ 3 ] Check Balance");
  printf("\n\t\t   [ 4 ] Change PIN");
  printf("\n\t\t   [ 5 ] Transaction History");
  printf("\n\t\t   [ 6 ] Exit ATM");
  printf("\n\n\t\t   _________________________________________________________________________________________");

  printf("\n\n\t\t   Please select the option : ");

}

void denominations()
{
  system("cls");
  logo();
  printf("\n\t\t   ===============================*Available Denominations*=================================");
  printf("\n\n\t\t   [ 1 ] 2000 Rs");
  printf("\n\t\t   [ 2 ] 500 Rs");
  printf("\n\t\t   [ 3 ] 200 Rs");
  printf("\n\t\t   [ 4 ] 100 Rs");
  printf("\n\t\t   [ 5 ] 50 Rs");
  printf("\n\n\t\t   _________________________________________________________________________________________");

  printf("\n\n\t\t   Please enter the amount : ");

}

void Pin(char ch[])
{

  char c;
  int i;
  for (i = 0; i < 4; i++)
  {
  ch[i] = getch();
  printf("*");
  }
  ch[4] = '\0';
  scanf("%c",&c);
}

int trans_id()
{
   int rnum, start, end;
   start=100000000;
   end=999999999;
   srand(time(0));
   rnum = rand()%(end+1-start)+start;
   return rnum;
}

void save_TransactionHistory(struct Transaction trans[], int cnt) 
{
    FILE *ft = fopen("Transaction_History.txt", "a");
    if (ft == NULL) 
    {
        printf("Error: Unable to open transaction history file.\n");
        return;
    }
    time_t t;
    t = time(NULL);
    struct tm tm;
	  tm = *localtime(&t);

        char type = trans[cnt].type;
        float amount = trans[cnt].amount;
        FILE *fbal=fopen("User_balance.txt","r");
        char temp[10];
        fscanf(fbal,"%s",temp);
        fclose(fbal);
        int b=atoi(temp);
        float bal=(float)b;
        if (type == 'D') 
        {
          fprintf(ft, "\n\n\t\t   %02d\t\t%.2f\t\t   Deposit\t%.2f\t%02d-%02d-%04d\t%02d:%02d:%02d\n", cnt + 1, amount, bal, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
        } 
        else  
        {
          fprintf(ft, "\n\n\t\t   %02d\t\t%.2f\t\t   Withdraw\t%.2f\t%02d-%02d-%04d\t%02d:%02d:%02d\n", cnt + 1, amount, bal, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
        }


    fclose(ft);
}

void display_TransactionHistory()
{
  system("cls");
  logo();
  printf("\n\t\t   =================================*Transaction History*===================================");
  printf("\n\n\t\t   %s\t%s\t   %s\t\t%s\t\t  %s\t\t%s\n", "Index", "Amount (Rs)", "Type", "Balance", "Date", "Time");

  printf("\n");
  FILE *ft = fopen("Transaction_History.txt", "r");
  if (ft == NULL) 
  {
    printf("Transaction history file not found.\n");
    return;
  }

  char line[100];
  while (fgets(line, sizeof(line), ft)) 
  {
    printf("%s", line);
  }

  fclose(ft);
  printf("\n\n\t\t   _________________________________________________________________________________________");
}