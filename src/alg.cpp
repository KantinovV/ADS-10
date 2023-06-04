#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
std::vector<char> getPerm(const Tree& tree, int n) {
  std::string R = tree[n - 1];
  std::vector<char> lol;
  for (int i = 0; i < R.length(); i++) {

    lol.push_back(R[i]);
  }
  return lol;
}
