#include "InputValidation.h"

char inputChar(std::string prompt, std::string where) {
  char input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument(
            "ERROR IN " + where +
            ": Invalid input. Must be a character type.\n");
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

char inputChar(std::string prompt, std::string listChars, std::string where) {
  char input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      input = tolower(input);
      if (std::cin.fail() || listChars.find(input) == std::string::npos) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument("ERROR IN " + where +
                                    ": Invalid input. Must be a character type "
                                    "and one of the following: " +
                                    listChars + ".\n");
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

char inputChar(std::string prompt, char yes, char no, std::string where) {
  char input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      input = tolower(input);
      if (std::cin.fail() || input != yes && input != no) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument("ERROR IN " + where +
                                    ": Invalid input. Must be a character type "
                                    "and one of the following: " +
                                    yes + " or " + no + ".\n");
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

char inputChar(std::string prompt, bool alphaOrDigit, std::string where) {
  char input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      if (std::cin.fail() || (alphaOrDigit && !isalpha(input) ||
                              (!alphaOrDigit && !isdigit(input)))) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument(
            "ERROR IN " + where +
            ": Invalid input. Must be a character type and " +
            (alphaOrDigit ? "a non-digit.\n" : "a digit.\n"));
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

int inputInteger(std::string prompt, std::string where) {
  int input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument(
            "ERROR IN " + where +
            ": Invalid input. Must be an integer type.\n");
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

int inputInteger(std::string prompt, bool posNeg, std::string where) {
  int input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      if (std::cin.fail() || (posNeg && input < 0 || (!posNeg && input > 0))) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument(
            "ERROR IN " + where +
            ": Invalid input. Must be an integer type and " +
            (posNeg ? "a positive number.\n" : "a negative number.\n"));
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

int inputInteger(std::string prompt, int startRange, int endRange,
                 std::string where) {

  int input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      if (std::cin.fail() || input < startRange || input > endRange) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument(
            "ERROR IN " + where +
            ": Invalid input. Must be an integer type and between " +
            std::to_string(startRange) + " and " + std::to_string(endRange) +
            ".\n");
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

double inputDouble(std::string prompt, std::string where) {
  double input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument(
            "ERROR IN " + where + ": Invalid input. Must be a double type.\n");
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

double inputDouble(std::string prompt, bool posNeg, std::string where) {
  double input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      if (std::cin.fail() || (posNeg && input < 0 || (!posNeg && input > 0))) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument(
            "ERROR IN " + where +
            ": Invalid input. Must be a double type and " +
            (posNeg ? "a positive number.\n" : "a negative number.\n"));
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

double inputDouble(std::string prompt, double startRange, double endRange,
                   std::string where) {
  double input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      if (std::cin.fail() || input < startRange || input > endRange) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument(
            "ERROR IN " + where +
            ": Invalid input. Must be a double type and between " +
            std::to_string(startRange) + " and " + std::to_string(endRange) +
            ".\n");
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);
  return input;
}

std::string inputString(std::string prompt, std::string where) {
  std::string input;
  do {
    std::cout << prompt;
    try {
      std::cin >> input;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        throw std::invalid_argument(
            "ERROR IN " + where + ": Invalid input. Must be a string type.\n");
      } else
        break;
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  } while (true);

  return input;
}
