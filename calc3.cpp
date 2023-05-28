#include <iostream>
#include <cstdio>

using namespace std;


float add(float x, float y){
  return (x + y);
}

float subtract(float x, float y){
  return (x - y);
}

float multiply(float x, float y){
  return (x * y);
}

float divide(float x, float y){
  if(x == 0 || y == 0){
    return 0;
  }else{
    return (x / y);
  }
}

int main(){
  float num1,num2;
  char op;
  float  result;

  while(true){
  
  cout << "Enter your expression: \n";

  scanf("%e%c%e", &num1, &op, &num2);


  switch(op){
  case '+':
    result = add(num1, num2);
    break;
  case '-':
    result = subtract(num1, num2);
    break;
  case '*':
    result = multiply(num1, num2);
    break;
  case '/':
    result = divide(num1, num2);
    break;
  default:
    cout << "Sorry wrong formatting, exiting...\n";
    return 0;
    break;
  }

  cout << "val1: " << num1 << "\n";

  cout << "val2: " << num2 << "\n";

  cout << "operator : " << op << "\n";

  
  cout << "\nResult: " << result << "\n";
  }
  return 0;
}
