#include <iostream>
using namespace std;

// Программа дає збій, оскільки після оператору виведення немає позначки " -> фікс шляхом введення цього знаку перед Is
// Також необхідно завершити рядок з об'єктом cout (рядок 10) знаком ";" -> фікс шляхом введення цього знаку в кінці рядка 
// До цього ж треба додати \n в кінці фрази в межах "" або << endl після стрічки

int main()
{
  cout << Is there a bug here?"
  return 0;
}    

