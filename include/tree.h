// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>
class Tree {
 private:
  struct Node {
  char hyi;
  std::vector<Node*> greList;
  };
  Node* root;
  void buildTree(Node* root, std::vector<char> per) {
    if (!per.size())
      return;
    if (root->hyi != '*') {
      for (auto l = per.begin(); l != per.end(); l++)
        if (*l == root->hyi) {
          per.erase(l);
          break;
        }
    }
    for (size_t k = 0; k < per.size(); k++)
      root->greList.push_back(new Node());
    for (size_t a = 0; a < root->greList.size(); a++)
      root->greList[a]->hyi = per[a];
    for (size_t i = 0; i < root->greList.size(); i++)
      buildTree(root->greList[i], per);
  }
  std::vector<std::string> permutation;
  void prm(Node* root, std::string symbol = "") {
    if (!root->greList.size()) {
      symbol += root->hyi;
      permutation.push_back(symbol);
    }
    if (root->hyi != '*')
      symbol += root->hyi;
    for (size_t i = 0; i < root->greList.size(); i++)
      prm(root->greList[i], symbol);
  }
 public:
    std::string operator[](int i) const {
      if (i >= permutation.size())
        return "";
      return permutation[i];
    }
      explicit Tree(std::vector<char> hyi) {
      root = new Node();
      root->hyi = '*';
      buildTree(root, hyi);
      prm(root);
    }
};
#endif  // INCLUDE_TREE_H_
