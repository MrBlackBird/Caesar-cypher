#include <iostream>
#include <string>

class Cesar {
private:
  std::string text_;
  int offset_;
  int alphabetSize_ = 26;
  int asciiOffset_ = 96;

public:
  void get_input() {
    std::cout << "Enter your phrase below:\n";
    std::getline(std::cin, text_);
    std::cout << "Enter the desired letter offset:\n";
    std::cin >> offset_;
  }

  void cypher() {
    for (auto &ch : text_) {
      if (isalnum(ch)) {
        ch = tolower(ch);
        ch =
            (int)(ch - asciiOffset_ + offset_ + alphabetSize_) % alphabetSize_ +
            asciiOffset_;
      }
    }
  }

  void decypher() {
    for (auto &ch : text_) {
      if (isalnum(ch)) {
        ch = tolower(ch);
        ch =
            (int)(ch - asciiOffset_ - offset_ + alphabetSize_) % alphabetSize_ +
            asciiOffset_;
      }
    }
  }

  void print_result() { std::cout << "Processed phrase:\n" << text_ << "\n"; }
};

char action() {
  char act;
  std::cout << "Enter the desired operation: ";
  std::cin >> act;
  return act;
}

int main() {

  Cesar cesar;
  cesar.get_input();
  char act = action();

  if (act == 'e') {
    cesar.cypher();
  } else if (act == 'd') {
    cesar.decypher();
  } else {
    std::cout << "Invalid operation, terminating...\n";
  }

  cesar.print_result();

  return 0;
}
