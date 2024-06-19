# ATM-Simulator

ATM Simulator is a simple C-based console application that emulates the functionality of an Automated Teller Machine (ATM). The simulator allows users to withdraw and deposit cash, check their account balance, change their PIN, and view their transaction history.

## Features

- **Cash Withdrawal**: Withdraw cash in multiples of 50, with validations for sufficient account and ATM balance.
- **Cash Deposit**: Deposit cash into the account.
- **Balance Inquiry**: Check the current account balance.
- **PIN Change**: Change the ATM PIN with appropriate validations.
- **Transaction History**: View a detailed history of all transactions performed.

## Important Information


- **PIN Security:** The PIN is stored in the pin.txt file and has been set as 1234. The modified pin will also be saved to this file. The user has 3 attempts to enter the correct pin after inserting his card after which the account will be locked for security reasons.
  
- **Account Balance:** The balance is stored in the User_balance.txt file. Modify this file to set an initial balance if needed.
  
- **Transaction Limits:** The ATM is initialized with a balance of 20000. Modify the source code if you need to adjust this limit.
  
- **Transaction History:** The transaction history is stored in the Transaction_History.txt file. This file logs all deposits, withdrawals, and balance inquiries.
  
- **ATM Logo and Receipts:** The program displays an ATM logo and prints transaction receipts. The logo includes the current date and time.
  
- **Delay Function:** The waiting() function introduces delays to simulate real-world ATM processing times.
  
- **Beep Function:** The Beep() function alerts the user that incorrect information has been entered.
  
## File Structure


**pin.txt:** Stores the user's PIN.

**User_balance.txt:** Stores the user's account balance.

**Transaction_History.txt:** Stores the transaction history.

## Functions

**1. logo():** Displays the ATM logo and current date/time.

**2. menu():** Displays the main menu options.

**3. receipt():** Prints the transaction receipt.

**4. denominations():** Displays the available cash denominations.

**5. Pin(char ch[]):** Captures and masks the entered PIN.

**6. trans_id():** Generates a unique transaction ID.

**7. save_TransactionHistory(struct Transaction trans[], int cnt):** Saves the transaction history to a file.

**8. display_TransactionHistory():** Displays the saved transaction history.

**9. waiting(unsigned int mseconds):** Implements a delay.

# Getting Started

To run the project follow these steps:

  **1. Clone the repository:**

  ```
  git clone https://github.com/AbhayKamath03/Student_Management_System.git
  ```


  **2. Compile the program:**
  ```
  gcc ATM_Simulator.c
  ```


  **3. Run the program:**
  ```
  a
  ```

# Sample Screenshots

**First Screen**

![image](https://github.com/AbhayKamath03/ATM-Simulator/assets/92569661/3d45f3a5-1926-4d5d-b660-6dfb288af426)

**Main Menu**

![image](https://github.com/AbhayKamath03/ATM-Simulator/assets/92569661/bffd0888-e65b-4178-86cc-8decdfbe57d5)

**Sample Receipt**

![image](https://github.com/AbhayKamath03/ATM-Simulator/assets/92569661/4c4186e6-2be8-419c-b04e-4b802c59b22c)

**Transaction History**

![image](https://github.com/AbhayKamath03/ATM-Simulator/assets/92569661/1afae699-6139-49d3-b3a5-4dd58012371c)


