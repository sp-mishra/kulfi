#include "utils/Log.hpp"

using namespace std;

int main() {
  using namespace grkl;
  info("{}", "Hello Info!");
  warn("{}", "Hello Warn!");
  debug("{}", "Hello Debug!");
  error("{}", "Hello Error!!");
  return 0;
}
