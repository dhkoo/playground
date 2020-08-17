#include <iostream>
#include <memory>
#include <string>

#include <stdio.h>

int main() {
  uint8_t* raw_ptr = new uint8_t[5];
  std::unique_ptr<uint8_t> unique;
  unique.reset(raw_ptr);
  auto tmp = unique.get();
  auto str = "abcdefghij";
  tmp[0] = str[0];
  std::cout << *tmp << std::endl;

  uint8_t* new_raw_ptr = (uint8_t*)realloc(tmp, 10);
  unique.reset(new_raw_ptr);
  printf("raw_ptr : %p, new_raw_ptr : %p\n", tmp, new_raw_ptr);
  for (int i = 0; i < 10; i++) {
    tmp[i] = str[i];
  }
  std::cout << tmp << std::endl;
}
