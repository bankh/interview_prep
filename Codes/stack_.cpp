// stack::push/pop
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main ()
{
  std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...\n";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     //printf("Size: ");
     std::cout << " Size :" << mystack.size();
     mystack.pop();
     printf("\n");
  }
  
  
  std::cout << '\n';

  return 0;
}