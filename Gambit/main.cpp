#include <iostream>

const int MAX_LINES = 3;
const int MIN_BET = 1;
const int MAX_BET = 100;
int InputInt()
{
    int validInt;
    do
    {
         std::cin >> validInt;
         if (!(std::cin))
         {
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cout << "Please Enter a Number!! " << std::endl;
             continue;
         }
         else
         {
             break;
         }
    } while (true);
    return validInt;
}
void Menu()
{
    std::cout << "\t\t______________________________________________\n";
    std::cout << "\t\t|                                            |\n";
    std::cout << "\t\t|             Welcome to Dead Gambit         |\n";
    std::cout << "\t\t----------------------------------------------\n";
    std::cout << "\t\t| 1. Deposit                                 |\n";
    std::cout << "\t\t| 2. Play The Gambit                         |\n";
    std::cout << "\t\t| 3. Withdraw                                |\n";
    std::cout << "\t\t| 4. Info                                    |\n";
    std::cout << "\t\t| 5. Logout                                  |\n";
    std::cout << "\t\t| 6. Exit                                    |\n";
    std::cout << "\t\t----------------------------------------------\n";

}
int GetDeposit()
{
    int amount;
    while (true)
    {   
        std::cout << "What would like to Deposit: $";
        amount = InputInt();
        if (amount > 0)
        {
            break;
        }
        else
        {
            std::cout << "Amount must be Greater Than 0" << std::endl;
        }
    }
    return amount;
}
int GetNumberOfLines()
{
    int lines;
    while (true)
    {
        std::cout << "Enter The Number of Lines to Bet on 1 -"<<MAX_LINES<<": ";
        lines = InputInt();
        if (lines >= 1 && lines <= MAX_LINES)
        {
            break;
        }
        else
        {
            std::cout << "Please Enter a Valid number of lines" << std::endl;
        }
    }
    return lines;
}
int GetBet()
{
    int amount;
    while (true)
    {
        std::cout << "What would like to Bet on each Lines($" << MIN_BET<<"-"<<MAX_BET<<"):$ ";
        amount = InputInt();
        if (amount >= MIN_BET && amount <= MAX_BET)
        {
            break;
        }
        else
        {
            std::cout << "Amount must be Betwen " << MIN_BET << "-" << MAX_BET << std::endl;
        }
    }
    return amount;
}
int main()
{   
    int totalMenu = 6;
    int choices, balance,bet,lines;
    int totalDeposit = 0;
    int totalBet = 0;
    do
    {
        m:
        system("CLS");
        Menu();
        std::cout << "Enter your choice: "; 
        choices = InputInt();
        if (choices == 1)
        {   
            int choice;
            depo:
            balance = GetDeposit();
            totalDeposit += balance;
            std::cout << "Your Deposit is: " << totalDeposit<<"$" << std::endl;
            std::cout << "You wanna deposit again? Press 1 to deposit again or press 2 to back to Menu: ";
            choice = InputInt();
            if (choice == 1)
            {
                goto depo;
            }
            else
            {
                goto m;
            }
        }
        else if (choices == 2)
        {   
            system("CLS");
            bet:
            lines = GetNumberOfLines();
            bet = GetBet();
            totalBet = lines * bet;
            if (totalBet < totalDeposit)
            {
                std::cout << "Your Total Bet is: " << totalBet << "$" << std::endl;
            }
            else
            {
                std::cout << "You dont have enaugh money to bet, your Balance is: " << totalDeposit << "$" << std::endl;
            }
        }
        else if(choices == 3)
        {   
            withdraw:
            std::cout << "Your balance is " << totalDeposit << " how much money do you want to withdraw:$";
            int amount = InputInt();
            if (totalDeposit < amount)
            {
                std::cout << "You dont have enaugh money to withdraw, your Balance is:$" << totalDeposit << std::endl;
            }
            else
            {
                totalDeposit -= amount;
                std::cout << "Your balance is $" << totalDeposit<<std::endl;
                std::cout << "You wanna Withdraw again? Press 1 to Withdraw again or press 2 to back to Menu: ";
                int choice = InputInt();
                if (choice == 1)
                {
                    goto withdraw;
                }
                else
                {
                    goto m;
                }
            }
        }
    } while (choices != totalMenu);

    return 0;
}
