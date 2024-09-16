#include "Solution.hpp"

long Solution::LuckyTikets::Run() {
  int amount{};
  std::cout << "---[ Normal Mode ]---" << std::endl;
  std::cout << "Enter the input data: ";
  std::cin >> amount;
  return m_tickets(amount);
}

long Solution::LuckyTikets::RunRecursion() {
  int amount{};
  std::cout << "---[ Recursion Mode ]---" << std::endl;
  std::cout << "Enter the input data: ";
  std::cin >> amount;
  return m_recursiveTickets(amount, 0, 0);
}

long Solution::LuckyTikets::m_tickets(int digit) {
  switch (digit) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  default:
    return -1;
  }
}

long Solution::LuckyTikets::m_recursiveTickets(int digits, int firstPart, int secondPart) {
  long count{};

  if (digits == 0) {
    if (firstPart == secondPart) {
      return ++count;
    }
    return 0;
  }

  for (int first = 0; first < 10; ++first) {
    for (int second = 0; second < 10; ++second) {
      count += m_recursiveTickets(digits - 1, firstPart + first, secondPart + second);
    }
  }
  return count;
}
