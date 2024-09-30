#include "Solution.hpp"

int64_t Solution::LuckyTikets::Run(int number) {
  return m_tickets(number);
}

int64_t Solution::LuckyTikets::RunRecursion(int number) {
  return m_recursiveTickets(number);
}

int64_t Solution::LuckyTikets::m_tickets(int digit) {
  int64_t count{};
  switch (digit) {
  case 1:
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short b1 = 0; b1 < 10; ++b1) {
        if (a1 == b1) {
          ++count;
        }
      }
    }
    return count;
  case 2:
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short a2 = 0; a2 < 10; ++a2) {
        int sumA = a1 + a2;
        for (short b1 = 0; b1 < 10; ++b1) {
          int b2 = sumA - b1;
          if (b2 >= 0 && b2 < 10) {
            ++count;
          }
        }
      }
    }
    return count;
  case 3:
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short a2 = 0; a2 < 10; ++a2) {
        for (short a3 = 0; a3 < 10; ++a3) {
          int sumA = a1 + a2 + a3;
          for (short b1 = 0; b1 < 10; ++b1) {
            for (short b2 = 0; b2 < 10; ++b2) {
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
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short a2 = 0; a2 < 10; ++a2) {
        for (short a3 = 0; a3 < 10; ++a3) {
          for (short a4 = 0; a4 < 10; ++a4) {
            int sumA = a1 + a2 + a3 + a4;
            for (short b1 = 0; b1 < 10; ++b1) {
              for (short b2 = 0; b2 < 10; ++b2) {
                for (short b3 = 0; b3 < 10; ++b3) {
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
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short a2 = 0; a2 < 10; ++a2) {
        for (short a3 = 0; a3 < 10; ++a3) {
          for (short a4 = 0; a4 < 10; ++a4) {
            for (short a5 = 0; a5 < 10; ++a5) {
              int sumA = a1 + a2 + a3 + a4 + a5;
              for (short b1 = 0; b1 < 10; ++b1) {
                for (short b2 = 0; b2 < 10; ++b2) {
                  for (short b3 = 0; b3 < 10; ++b3) {
                    for (short b4 = 0; b4 < 10; ++b4) {
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
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short a2 = 0; a2 < 10; ++a2) {
        for (short a3 = 0; a3 < 10; ++a3) {
          for (short a4 = 0; a4 < 10; ++a4) {
            for (short a5 = 0; a5 < 10; ++a5) {
              for (short a6 = 0; a6 < 10; ++a6) {
                int sumA = a1 + a2 + a3 + a4 + a5 + a6;
                for (short b1 = 0; b1 < 10; ++b1) {
                  for (short b2 = 0; b2 < 10; ++b2) {
                    for (short b3 = 0; b3 < 10; ++b3) {
                      for (short b4 = 0; b4 < 10; ++b4) {
                        for (short b5 = 0; b5 < 10; ++b5) {
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
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short a2 = 0; a2 < 10; ++a2) {
        for (short a3 = 0; a3 < 10; ++a3) {
          for (short a4 = 0; a4 < 10; ++a4) {
            for (short a5 = 0; a5 < 10; ++a5) {
              for (short a6 = 0; a6 < 10; ++a6) {
                for (short a7 = 0; a7 < 10; ++a7) {
                  int sumA = a1 + a2 + a3 + a4 + a5 + a6 + a7;
                  for (short b1 = 0; b1 < 10; ++b1) {
                    for (short b2 = 0; b2 < 10; ++b2) {
                      for (short b3 = 0; b3 < 10; ++b3) {
                        for (short b4 = 0; b4 < 10; ++b4) {
                          for (short b5 = 0; b5 < 10; ++b5) {
                            for (short b6 = 0; b6 < 10; ++b6) {
                              int b7 = sumA - b1 - b2 - b3 - b4 - b5 - b6;
                              if (b7 >= 0 && b7 < 10) {
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
      }
    }
    return count;
  case 8:
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short a2 = 0; a2 < 10; ++a2) {
        for (short a3 = 0; a3 < 10; ++a3) {
          for (short a4 = 0; a4 < 10; ++a4) {
            for (short a5 = 0; a5 < 10; ++a5) {
              for (short a6 = 0; a6 < 10; ++a6) {
                for (short a7 = 0; a7 < 10; ++a7) {
                  for (short a8 = 0; a8 < 10; ++a8) {
                    int sumA = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8;
                    for (short b1 = 0; b1 < 10; ++b1) {
                      for (short b2 = 0; b2 < 10; ++b2) {
                        for (short b3 = 0; b3 < 10; ++b3) {
                          for (short b4 = 0; b4 < 10; ++b4) {
                            for (short b5 = 0; b5 < 10; ++b5) {
                              for (short b6 = 0; b6 < 10; ++b6) {
                                for (short b7 = 0; b7 < 10; ++b7) {
                                  int b8 = sumA - b1 - b2 - b3 - b4 - b5 - b6 - b7;
                                  if (b8 >= 0 && b8 < 10) {
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
          }
        }
      }
    }
    return count;
  case 9:
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short a2 = 0; a2 < 10; ++a2) {
        for (short a3 = 0; a3 < 10; ++a3) {
          for (short a4 = 0; a4 < 10; ++a4) {
            for (short a5 = 0; a5 < 10; ++a5) {
              for (short a6 = 0; a6 < 10; ++a6) {
                for (short a7 = 0; a7 < 10; ++a7) {
                  for (short a8 = 0; a8 < 10; ++a8) {
                    for (short a9 = 0; a9 < 10; ++a9) {
                      int sumA = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
                      for (short b1 = 0; b1 < 10; ++b1) {
                        for (short b2 = 0; b2 < 10; ++b2) {
                          for (short b3 = 0; b3 < 10; ++b3) {
                            for (short b4 = 0; b4 < 10; ++b4) {
                              for (short b5 = 0; b5 < 10; ++b5) {
                                for (short b6 = 0; b6 < 10; ++b6) {
                                  for (short b7 = 0; b7 < 10; ++b7) {
                                    for (short b8 = 0; b8 < 10; ++b8) {
                                      int b9 = sumA - b1 - b2 - b3 - b4 - b5 - b6 - b7 - b8;
                                      if (b9 >= 0 && b9 < 10) {
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
              }
            }
          }
        }
      }
    }
    return count;
  case 10:
    for (short a1 = 0; a1 < 10; ++a1) {
      for (short a2 = 0; a2 < 10; ++a2) {
        for (short a3 = 0; a3 < 10; ++a3) {
          for (short a4 = 0; a4 < 10; ++a4) {
            for (short a5 = 0; a5 < 10; ++a5) {
              for (short a6 = 0; a6 < 10; ++a6) {
                for (short a7 = 0; a7 < 10; ++a7) {
                  for (short a8 = 0; a8 < 10; ++a8) {
                    for (short a9 = 0; a9 < 10; ++a9) {
                      for (short a10 = 0; a10 < 10; ++a10) {
                        int sumA = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10;
                        for (short b1 = 0; b1 < 10; ++b1) {
                          for (short b2 = 0; b2 < 10; ++b2) {
                            for (short b3 = 0; b3 < 10; ++b3) {
                              for (short b4 = 0; b4 < 10; ++b4) {
                                for (short b5 = 0; b5 < 10; ++b5) {
                                  for (short b6 = 0; b6 < 10; ++b6) {
                                    for (short b7 = 0; b7 < 10; ++b7) {
                                      for (short b8 = 0; b8 < 10; ++b8) {
                                        for (short b9 = 0; b9 < 10; ++b9) {
                                          int b10 = sumA - b1 - b2 - b3 - b4 - b5 - b6 - b7 - b8 - b9;
                                          if (b10 >= 0 && b10 < 10) {
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
                  }
                }
              }
            }
          }
        }
      }
    }
    return count;
  default:
    std::cout << "Incorrect data!" << std::endl;
    return -1;
  }
}

int64_t Solution::LuckyTikets::m_recursiveTickets(int digits, int firstPart /* = 0 */, int secondPart /* = 0 */) {
  int64_t count{};

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
