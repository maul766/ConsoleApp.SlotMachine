#include <iostream>
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
int main()
{   
    int totalMenu = 6;
    int choices, balance;
    int totalDeposit = 0;
    do
    {
        m:
        Menu();
        std::cout << "Enter your choice: "; 
        choices = InputInt();
        if (choices == 1)
        {   
            int choice;
            system("CLS");
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
    } while (choices != totalMenu);

    return 0;
}
