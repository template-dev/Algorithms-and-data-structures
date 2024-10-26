#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>

namespace Algorithms {
  class LuckyTikets {
  public:
    int64_t Run(int64_t number);
    int64_t RunRecursion(int64_t number);

  private:
    int64_t m_tickets(int64_t digits);
    int64_t m_recursiveTickets(int64_t digits, int64_t firstPart = 0, int64_t secondPart = 0);
  };
}

#endif // SOLUTION_HPP
