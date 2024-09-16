#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>

namespace Solution {
  class LuckyTikets {
  public:
    long Run();
    long RunRecursion();

  private:
    long m_tickets(int digits);
    long m_recursiveTickets(int digits, int firstPart, int secondPart);
  };
}

#endif // SOLUTION_HPP
