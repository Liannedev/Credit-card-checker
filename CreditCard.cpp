#include <iostream>
using namespace std;

int getDigit(int number){
  return number % 10 + number/10;
}

int addEvenNumbers(string cardNumber){
  int sum=0;

  for(int i=cardNumber.size() - 2; i >=0; i-=2){
    sum += getDigit((cardNumber[i]- '0') * 2);
  }
  return sum;
}

int addOddNumbers(string cardNumber){
   int sum=0;

  for(int i=cardNumber.size() - 1; i >=0; i-=2){
    sum += getDigit((cardNumber[i]- '0'));
  }
  return sum;
}




int main(){
  string cardNumber;
  int result = 0;
  cout << "Enter your credit card number: ";
  cin >> cardNumber;
  

  result = addEvenNumbers(cardNumber) + addOddNumbers(cardNumber);
 
if (result % 10 == 0){
    cout << cardNumber << " is valid \n";
} else {
    cout << cardNumber << " is not valid \n";
}
    return 0;
} 