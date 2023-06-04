// Copyright 2022 NNTU-CS
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> ret_per;
    int sdfghjkl = tree.permonent_size;
    int figihbu = tree.neroment_fact;
    if ((n <= figihbu) && (n > 0)) {
        n = (n - 1) * sdfghjkl;
        for (int i = 0; i < sdfghjkl; i++) {
            ret_per.push_back(tree.data[n + i]);
        }
    }
    return ret_per;
}
