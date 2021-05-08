#include <iostream>
#include "draw_hangman.h"
#include <string>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

string selectedWord, guessed = "";
char choice;
int remainingLifes = 6;
vector<char> lettersUsed;

void selectWord()
{
    vector<string> words;
    string word;
    ifstream file("words.txt");
    while (getline(file, word))
    {
        words.push_back(word);
    }
    srand(time(NULL));
    int random = (rand() % words.size());
    selectedWord = words.at(random);
}

void showLettersUsed()
{
    if (find(lettersUsed.begin(), lettersUsed.end(), choice) == lettersUsed.end())
    {
        lettersUsed.push_back(choice);
    }
    cout << "Letters used:";
    for (int i = 0; i < lettersUsed.size(); i++)
    {
        cout << lettersUsed[i] << " ";
    }
    cout << endl;
}

void makeDisplay()
{
    for (int i = 0; i < selectedWord.length(); i++)
    {
        guessed = guessed + "_";
    }
    for (int i = 0; i < guessed.size(); i++)
    {
        cout << guessed[i] << " ";
    }
    cout << endl;
}

void chooseWord()
{
    drawHangman(remainingLifes);
    bool found = false;
    cout << endl;
    showLettersUsed();
    cout << "Introduce a letter => ";
    cin >> choice;
    system("cls");
    for (int i = 0; i < selectedWord.size(); i++)
    {
        if (selectedWord[i] == choice)
        {
            guessed[i] = choice;
            found = true;
        }
    }
    if (guessed == selectedWord)
    {
        cout << endl
             << R"""(
    #     #                                       
     #   #   ####  #    #    #    #  ####  #    # 
      # #   #    # #    #    #    # #    # ##   # 
       #    #    # #    #    #    # #    # # #  # 
       #    #    # #    #    # ## # #    # #  # # 
       #    #    # #    #    ##  ## #    # #   ## 
       #     ####   ####     #    #  ####  #    # 
        )"""
             << endl;
        drawHangman(remainingLifes);
        cout << endl
             << "The word to guess was: " << selectedWord;
        exit(1);
    }
    if (found == false)
        remainingLifes--;

    for (int i = 0; i < guessed.size(); i++)
    {
        cout << guessed[i] << " ";
    }

    cout << endl;
}

void startGame()
{
    cout << "Press enter to start";
    getchar();
    system("cls");
    selectWord();
    makeDisplay();
    while (remainingLifes != 0)
    {
        chooseWord();
    }
    if (remainingLifes == 0)
    {
        system("cls");
        cout << endl
             << R"""(
             #####                                                      
            #     #   ##   #    # ######     ####  #    # ###### #####  
            #        #  #  ##  ## #         #    # #    # #      #    # 
            #  #### #    # # ## # #####     #    # #    # #####  #    # 
            #     # ###### #    # #         #    # #    # #      #####  
            #     # #    # #    # #         #    #  #  #  #      #   #  
            #####   #    # #    # ######     ####    ##   ###### #    # 
        )""" << endl;
        drawHangman(0);
        cout << endl
             << "The word to guess was: " << selectedWord;
    }
}

int main()
{
    cout << R"""( 

  _  _   _   _  _  ___ __  __   _   _  _ 
| || | /_\ | \| |/ __|  \/  | /_\ | \| |
| __ |/ _ \| .` | (_ | |\/| |/ _ \| .` |
|_||_/_/ \_\_|\_|\___|_|  |_/_/ \_\_|\_|  
                                         

                ___________..___________    
| .__________))______|
| | / /      ||
| |/ /       ||
| | /        ||.-''.
| |/         |/  _  \
| |          ||  `/,|
| |          (\\`_.'
| |         .-`--'.
| |        /Y . . Y\
| |       // |   | \\
| |      //  | . |  \\
| |     ')   |   |   (`                             
| |          ||'||
| |          || ||
| |          || ||
| |          || ||
| |         / | | \
""""""""""|_`-' `-' |"""|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .
)""";

    startGame();

    return 0;
}
