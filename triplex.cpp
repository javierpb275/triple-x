#include <iostream>

void PrintIntroduction(int Difficulty)
{
    //Print welcome messages to the terminal:
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room... \nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    //cout: character output
    //<<: insertion operator
    //cin: character input
    //>>: extraction operator

    PrintIntroduction(Difficulty);

    //Declare 3 number code
    const int CodeA = rand();
    const int CodeB = rand();
    const int CodeC = rand();

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product to the terminal
    std::cout << std::endl;
    std::cout << "+ There are \"3 numbers\" in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    std::cout << "\nYou entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check if the player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agente! Try again! ***";
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)//loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();//Clears any errors
        std::cin.ignore();//Discard the buffer
        if (bLevelComplete)
        {
            //increase the level difficulty
            ++LevelDifficulty;
        }
    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there!\n";
    
    return 0;
}