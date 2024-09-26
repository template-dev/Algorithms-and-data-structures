#include "Solution.hpp"

long Solution::LuckyTikets::Run() {
  int amount{};
  std::cout << "---[ Non-Recursion Mode ]---" << std::endl;
  std::cout << "Enter the input data: ";
  std::cin >> amount;
  return m_tickets(amount);
}

long Solution::LuckyTikets::RunRecursion() {
  int amount{};
  std::cout << "---[ Recursion Mode ]---" << std::endl;
  std::cout << "Enter the input data: ";
  std::cin >> amount;
  return m_recursiveTickets(amount);
}

long Solution::LuckyTikets::m_tickets(int digit) {
  long count{};
  switch (digit) {
  case 0:
    return 1;
  case 1:
    for (int a1 = 0; a1 < 10; ++a1) {
      for (int b1 = 0; b1 < 10; ++b1) {
        if (a1 == b1) {
          ++count;
        }
      }
    }
    return count;
  case 2:
    for (int a1 = 0; a1 < 10; ++a1) {
      for (int a2 = 0; a2 < 10; ++a2) {
        int sumA = a1 + a2;
        for (int b1 = 0; b1 < 10; ++b1) {
          int b2 = sumA - b1;
          if (b2 >= 0 && b2 < 10) {
            ++count;
          }
        }
      }
    }
    return count;
  case 3:
    for (int a1 = 0; a1 < 10; ++a1) {
      for (int a2 = 0; a2 < 10; ++a2) {
        for (int a3 = 0; a3 < 10; ++a3) {
          int sumA = a1 + a2 + a3;
          for (int b1 = 0; b1 < 10; ++b1) {
            for (int b2 = 0; b2 < 10; ++b2) {
              int b3 = sumA - b1 - b2;
              if (b3 >= 0 && b3 < 10) {
                ++count;
              }
            }
          }
        }
      }
    }
    return count;
  case 4:
    for (int a1 = 0; a1 < 10; ++a1) {
      for (int a2 = 0; a2 < 10; ++a2) {
        for (int a3 = 0; a3 < 10; ++a3) {
          for (int a4 = 0; a4 < 10; ++a4) {
            int sumA = a1 + a2 + a3 + a4;
            for (int b1 = 0; b1 < 10; ++b1) {
              for (int b2 = 0; b2 < 10; ++b2) {
                for (int b3 = 0; b3 < 10; ++b3) {
                  int b4 = sumA - b1 - b2 - b3;
                  if (b4 >= 0 && b4 < 10) {
                    ++count;
                  }
                }
              }
            }
          }
        }
      }
    }
    return count;
  case 5:
    for (int a1 = 0; a1 < 10; ++a1) {
      for (int a2 = 0; a2 < 10; ++a2) {
        for (int a3 = 0; a3 < 10; ++a3) {
          for (int a4 = 0; a4 < 10; ++a4) {
            for (int a5 = 0; a5 < 10; ++a5) {
              int sumA = a1 + a2 + a3 + a4 + a5;
              for (int b1 = 0; b1 < 10; ++b1) {
                for (int b2 = 0; b2 < 10; ++b2) {
                  for (int b3 = 0; b3 < 10; ++b3) {
                    for (int b4 = 0; b4 < 10; ++b4) {
                      int b5 = sumA - b1 - b2 - b3 - b4;
                      if (b5 >= 0 && b5 < 10) {
                        ++count;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return count;
  case 6:
    for (int a1 = 0; a1 < 10; ++a1) {
      for (int a2 = 0; a2 < 10; ++a2) {
        for (int a3 = 0; a3 < 10; ++a3) {
          for (int a4 = 0; a4 < 10; ++a4) {
            for (int a5 = 0; a5 < 10; ++a5) {
              for (int a6 = 0; a6 < 10; ++a6) {
                int sumA = a1 + a2 + a3 + a4 + a5 + a6;
                for (int b1 = 0; b1 < 10; ++b1) {
                  for (int b2 = 0; b2 < 10; ++b2) {
                    for (int b3 = 0; b3 < 10; ++b3) {
                      for (int b4 = 0; b4 < 10; ++b4) {
                        for (int b5 = 0; b5 < 10; ++b5) {
                          int b6 = sumA - b1 - b2 - b3 - b4 - b5;
                          if (b6 >= 0 && b6 < 10) {
                            ++count;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    return count;
  case 7:
    return count;
  case 8:
    return count;
  case 9:
    return count;
  default:
    std::cout << "Incorrect data!" << std::endl;
    return -1;
  }
}

long Solution::LuckyTikets::m_recursiveTickets(int digits, int firstPart /* = 0 */, int secondPart /* = 0 */) {
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
