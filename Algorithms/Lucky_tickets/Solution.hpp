#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>

namespace Solution {
  class LuckyTikets {
  public:
    long Run(int number);
    long RunRecursion(int number);

  private:
    long m_tickets(int digits);
    long m_recursiveTickets(int digits, int firstPart = 0, int secondPart = 0);
  };
}

#endif // SOLUTION_HPP
