#include "cppincludes.h"

class UFNode {
  public:
    string name, email;
    UFNode *parent;

    UFNode(string name, string email, UFNode *parent = nullptr)
        : name(name), email(email), parent(parent) {
        if (parent == nullptr) {
            this->parent = this;
        }
    }
};

UFNode *find(UFNode *node) {
    return node->parent == node ? node : ((node->parent) = find(node->parent));
}

void merge(UFNode *node1, UFNode *node2) { find(node1)->parent = find(node2); }

class Solution {

    // email
    unordered_map<string, UFNode *> all_nodes;

  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        for (vector<string> &account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                if (all_nodes.find(account[i]) == all_nodes.end()) {
                    all_nodes[account[i]] = new UFNode(name, account[i]);
                }

                if (i >= 2) {
                    // merge following emails with first
                    merge(all_nodes[account[1]], all_nodes[account[i]]);
                }
            }
        }

        // root email
        unordered_map<string, vector<UFNode *>> roots;
        for (auto [email, node] : all_nodes) {
            UFNode *root = find(node);
            roots[root->email].push_back(node);
        }

        // construct result
        vector<vector<string>> result;
        for (auto [email, nodes] : roots) {
            UFNode *root = all_nodes[email];
            vector<string> r{root->name};
            result.push_back(r);

            sort(nodes.begin(), nodes.end(),
                 [](auto a, auto b) { return a->email < b->email; });
            for (UFNode *n : nodes) {
                result.back().push_back(n->email);
            }
        }

        return result;
    }
};