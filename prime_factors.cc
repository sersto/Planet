/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
	       https://www.onlinegdb.com/online_c++_compiler

*******************************************************************************/

#include <iostream>
#include <stack>  // подключаем библиотеку для стека
using namespace std;

stack <int> steck1;  // создаем стек1
stack <int> steck2;  // создаем стек2 (заполним в обратном порядке)

//Функция расскладывает натуральное число "n" на простые сомножители
//и добавляет их в стек "steck1" по возрастанию, начиная с 2 и пока z*z<=n
//Если остаток от деления на z равен нулю, z идет в стек "steck1.push(z)", 
//действие повторяется с частным от деления, если не ноль - z увеличивается и т.д.
void prime_factors(int n){
int z = 2;
while (z * z <= n){
    if (n % z == 0){   
        //cout << z << "*";
        steck1.push(z);  // добавляем число
        n = (n / z);
    }
    else{
        z++;
    }
}
if (n > 1){
    //cout << n << "\n";
    steck1.push(n);  // добавляем число
    }
}
int main() {
int x;
cout << "Введите натуральное число больше 1: ";
cin >> x;
prime_factors(x);
    int start=1;
    //Пока стек "steck1" не пустой
    while ( !(steck1.empty())) {
    steck2.push(steck1.top());//стек2 заполним в обратном порядке
    //печать пробела вместо звездочки перед первым сомножителем (как в задании)
    if (start) cout << " "; else cout << "*";
    //выводим на печать верхний элемент steck1 
    cout << steck1.top();
    steck1.pop();  // удаляем верхний элемент steck1
    start=0;
  }
    start=1;
    cout << "\n";
    while ( !(steck2.empty())) {
    if (start) cout << " "; else cout << "*";
    //выводим на печать верхний элемент steck2 
    cout << steck2.top();
    steck2.pop();  // удаляем верхний элемент steck2
    start=0;
  }

return 0;}



