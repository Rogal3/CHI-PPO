#include <cstdio>

class Bt {
    struct Node {
        char val;
        Node *left, *right;
        Node() : left(), right() {}
    };
    public:
        Node* head;
        Bt() : head() {}
        Node *findOper(char val, Node *node);
        Node *find(char val) {
            if (head != NULL)
                return findOper(val, head);
            return NULL;
        }
        void add(char p, char l, char r) {
            Node *ptr = find(p);
            if (ptr == NULL) {
                head = new Node;
                ptr = head;
            }
            ptr->val = p;
            if (l != '.') {
                ptr->left = new Node;
                ptr->left->val = l;
            }
            if (r != '.') {
                ptr->right = new Node;
                ptr->right->val = r;
            }
        }
        void preorder(Node *node);
        void inorder(Node *node);
        void postorder(Node *node);
};

Bt::Node *Bt::findOper(char val, Bt::Node *node) {
    if (node->val == val) {
        return node;
    }
    Node *ptr;
    if (node->left != NULL) {
        ptr = findOper(val, node->left);
        if (ptr != NULL) {
            return ptr;
        }
    }
    if (node->right != NULL) {
        ptr = findOper(val, node->right);
        if (ptr != NULL) {
            return ptr;
        }
    }
    return NULL;
}

void Bt::preorder(Bt::Node *node) {
    putchar(node->val);
    if (node->left != NULL) {
        preorder(node->left);
    }
    if (node->right != NULL) {
        preorder(node->right);
    }
}

void Bt::inorder(Bt::Node *node) {
    if (node->left != NULL) {
        inorder(node->left);
    }
    putchar(node->val);
    if (node->right != NULL) {
        inorder(node->right);
    }
}

void Bt::postorder(Bt::Node *node) {
    if (node->left != NULL) {
        postorder(node->left);
    }
    if (node->right != NULL) {
        postorder(node->right);
    }
    putchar(node->val);
}

int main() {
    int N;
    scanf("%d", &N); getchar();
    Bt bt;
    for (int n = 0; n < N; ++n) {
        char c1, c2, c3;
        c1 = getchar(); getchar();
        c2 = getchar(); getchar();
        c3 = getchar(); getchar();
        bt.add(c1, c2, c3);
    }
    bt.preorder(bt.head); putchar('\n');
    bt.inorder(bt.head); putchar('\n');
    bt.postorder(bt.head); 
    return 0;
}
