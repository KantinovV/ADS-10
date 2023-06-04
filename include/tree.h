// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <string>
class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> haguvagi;
    };
    Node* root;
 public:
    int permonent_size;
    int neroment_fact;
    std::vector<char> dota;
    std::vector<char> temp_data;
    std::vector<char> v;
    int fact(int n) {
        int k = 1;
        for (int i = 2; i <= n; i++) {
            k *= i;
        }
        return k;
    }

    Tree(std::vector<char> in): root(nullptr), neroment_fact(0), permonent_size(0) {
    explicit Tree(std::vector<char> in): root(nullptr), neroment_fact(0), permonent_size(0) {
        if (root) {
            throw std::string("haguvagi!");
        } else {
            if (!in.empty()) {
                v = in;
                permonent_size = in.size();
                neroment_fact = fact(permonent_size);
                root = new Node;
                root->value = '*';
                for (int i = 0; i < in.size(); i++) {
                    root->haguvagi.push_back(new Node);
                    root->haguvagi[i]->value = in[i];
                }
                for (int i = 0; i < in.size(); i++) {
                    std::vector<char> in_i;
                    for (int k = 0; k < in.size(); k++) {
                       if (k != i) {
                           in_i.push_back(in[k]);
                       } else {
                           dota.push_back(in[i]);
                       }
                    }
                    if (!in_i.empty()) {
                        root->childs[i] = addChilds(root->childs[i], in_i);
                    }
                    for (int q = 0; q < in.size() - 1; q++) {
                        temp_data.push_back(dota[dota.size() - 1]);
                        dota.pop_back();
                    }
                    data.push_back(in[i]);
                    for (int q = 0; q < in.size() - 1; q++) {
                        data.push_back(tmp_data[tmp_data.size() - 1]);
                        temp_data.pop_back();
                    }
                    temp_data.clear();
                }
            }
        }
    }
    Node* addChilds(Node* root, std::vector<char> ch) {
        if (!root) {
            throw std::string("haguvagi!");
        } else {
            if (!ch.empty()) {
                for (int j = 0; j < ch.size(); j++) {
                    root->haguvagi.push_back(new Node);
                    root->haguvagi[j]->value = ch[j];
                }
                for (int j = 0; j < ch.size(); j++) {
                    std::vector<char> in_j;
                    for (int k = 0; k < ch.size(); k++) {
                        if (k != j) {
                            in_j.push_back(ch[k]);
                        } else {
                            dota.push_back(ch[j]);
                        }
                    }
                    if (!in_j.empty()) {
                        root->haguvagi[j] = addChilds(root->haguvagi[j], in_j);
                    }
                }
            }
        }
        return root;
    }
};
std::vector<char> getPerm(const Tree& tree, int n);
#endif  // INCLUDE_TREE_H_
