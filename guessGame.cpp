#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int randomNum;

int guess = 0;
int guessCount = 0;
int numRange = 100;
int numInitial = 1;

int main(){

  srand(time(NULL));

  randomNum = rand() % numRange + numInitial;

  cout << "The number selected is within the range of " << numRange << " and is greater than " << numInitial << "\n";
  cout << "Take a guess: \n";

  
  while(guess != randomNum){

    cin >> guess;

    guessCount++;

    if(guess > randomNum){
      cout << "Your guess is too high.\n";
    }else if(guess < randomNum){
      cout << "Your guess is too low.\n";
    }else{
      cout << "Congratulations the number was " << randomNum <<" , Your guess is correct!!!\nFinished with " << guessCount << " guesses!\n";
     return 0;
    }

  }

  return 0;
}
