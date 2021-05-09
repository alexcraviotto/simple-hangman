# simple-hangman
![](https://i.imgur.com/T3vTfAK.gif)
### How to use
1. Create a txt file called "words.txt" and enter the words to guess in the game.
 > house

> car

> flower

> airplane

> computer

2. Compile the program `g++ -o hangman main.cpp draw_hangman.cpp`
------------

### Compatibility
It is only compatible with Windows as it uses its own system commands(cls). However you can run it on linux by changing `system("cls")` to `system("clear")` in the code.
