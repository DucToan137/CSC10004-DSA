#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

struct Treenode {
    char data;
    Treenode* left, * right;

    Treenode(char data) : data(data), left(nullptr), right(nullptr) {}
};

struct Tree {
    Treenode* root;

    Tree() : root(nullptr) {}
};

int height(Treenode* root) {
    if (root == nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int getcol(int h) {
    if (h == 1)
        return 1;
    return getcol(h - 1) + getcol(h - 1) + 1;
}

void printTree(char** M, Treenode* root, int col, int row, int height) {
    if (root == nullptr)
        return;

    M[row][col] = root->data;

    printTree(M, root->left, col - static_cast<int>(pow(2, height - 2)), row + 1, height - 1);

    printTree(M, root->right, col + static_cast<int>(pow(2, height - 2)), row + 1, height - 1);
}

void TreePrinter(Tree tree) {
    int h = height(tree.root);
    int col = getcol(h);
    char** M = new char* [h];

    for (int i = 0; i < h; i++) {
        M[i] = new char[col];
        memset(M[i], ' ', col * sizeof(char));
    }

    printTree(M, tree.root, col / 2, 0, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < col; j++) {
            if (M[i][j] == ' ')
                cout << " ";
            else
                cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

Tree buildExpressionTree() {
    stack<Treenode*> stack;
    char ch;

    cout << "Enter a postfix expression: ";

    while (cin >> ch) {
        if (isalnum(ch)) {
            stack.push(new Treenode(ch));
        }
        else {
            Treenode* operand2 = stack.top();
            stack.pop();
            Treenode* operand1 = stack.top();
            stack.pop();

            Treenode* newNode = new Treenode(ch);
            newNode->left = operand1;
            newNode->right = operand2;

            stack.push(newNode);
        }

        if (cin.peek() == '\n') {
            break;
        }
    }

    Tree result;
    result.root = stack.top();
    return result;
}

int main() {
    Tree expressionTree = buildExpressionTree();

    TreePrinter(expressionTree);

    return 0;
}