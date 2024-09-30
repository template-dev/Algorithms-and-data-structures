#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>

namespace Solution {
  class LuckyTikets {
  public:
    int64_t Run(int number);
    int64_t RunRecursion(int number);

  private:
    int64_t m_tickets(int digits);
    int64_t m_recursiveTickets(int digits, int firstPart = 0, int secondPart = 0);
  };
}

#endif // SOLUTION_HPP
