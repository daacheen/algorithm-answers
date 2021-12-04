#include "cppincludes.h"

struct Node {
    unordered_map<char, Node *> edges;
    bool end = false;
};

class StreamChecker {

    Node *root;

    string letters;

  public:
    StreamChecker(vector<string> &words) {
        // create state machine
        root = new Node();

        for (string &word : words) {
            reverse(word.begin(), word.end());
            Node *r = root;
            for (char c : word) {
                if (r->edges.find(c) == r->edges.end()) {
                    r->edges[c] = new Node();
                }
                r = r->edges[c];
            }
            r->end = true;
        }
    }

    bool query(char letter) {
        letters.push_back(letter);

        Node *r = root;

        for (int i = letters.size() - 1; i >= 0; i--) {
            char c = letters[i];
            if (r->edges.find(c) != r->edges.end()) {
                r = r->edges[c];
                if (r->end) {
                    return true;
                }
            } else {
                return false;
            }
        }

        return false;
    }
};