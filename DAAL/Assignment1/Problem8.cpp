#include<iostream>
#include <iomanip>
using namespace std;

struct Node{
    int data;
    int left_count;
    int right_count;
    int height;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left_count = 0;
        right_count = 0;
        height = 1;
        left = right = nullptr;
    }
};

class RankTracker{
    public:
        void track(int x){
            root = insert(root, x);
        }
        
        int getRankOfNumber(int x){
            return getRank(root, x);
        }
        void printTree() {
            cerr << "AVL Tree:" << endl;
            printInOrder(root, 0);
        }

    private:
        Node* root;

        // Helper method for in-order traversal and printing
        void printInOrder(Node* node, int indent) {
            if (node == nullptr) {
                return;
            }

            printInOrder(node->right, indent + 4);
            cerr << setw(indent) << " " << node->data << endl;
            printInOrder(node->left, indent + 4);
        }
        int getHeight(Node* node){
            if(node == nullptr){
                return 0;
            }
            return node -> height;
        }

        int getBalanceFactor(Node* node){
            if(node == nullptr){
                return 0;
            }
            return getHeight(node -> left) - getHeight(node -> right);
        }

        Node* rightRotate(Node* y){
            Node* x = y -> left;
            Node* T2 = x -> right;

            // Perform rotation
            x -> right = y;
            y -> left = T2;

            // Update heights
            y -> height = max(getHeight(y -> left), getHeight(y -> right)) + 1;
            x -> height = max(getHeight(x -> left), getHeight(x -> right)) + 1;

            // Update left_count and right_count
            y -> left_count = ((y -> left != nullptr) ? (y -> left -> left_count + y -> left -> right_count + 1) : 0 );
            x -> right_count = ((x -> right != nullptr) ? (x -> right -> left_count + x -> right -> right_count + 1) : 0 );

            return x;
        }

        Node* leftRotate(Node* x){
            Node* y = x -> right;
            Node* T2 = y -> left;

            // Perform rotation
            y -> left = x;
            x -> right = T2;

            // Update heights
            y -> height = max(getHeight(y -> left), getHeight(y -> right)) + 1;
            x -> height = max(getHeight(x -> left), getHeight(x -> right)) + 1;

            // Update left_count and right_count
            y -> left_count = ((y -> left != nullptr) ? (y -> left -> left_count + y -> left -> right_count + 1) : 0 );
            x -> right_count = ((x -> right != nullptr) ? (x -> right -> left_count + x -> right -> right_count + 1) : 0 );

            return y;
        }

        Node* insert(Node* node, int x){
            if(node == nullptr){
                return new Node(x);
            }

            if(x <= node -> data){
                ++node -> left_count;
                node -> left = insert(node -> left, x);
            }
            else{
                node -> right = insert(node -> right, x);
            }

            // Update height of the current node
            node -> height = max(getHeight(node -> left), getHeight(node -> right)) + 1;

            // Get the balance factor to check if the node became unbalanced
            int balance = getBalanceFactor(node);

            // Perfomr rotations to balance the tree
            if(balance > 1 && x <= node -> left -> data){
                return rightRotate(node);
            }

            if(balance < -1 && x > node -> right -> data){
                return leftRotate(node);
            }

            if(balance > 1 && x > node -> left -> data){
                node -> left = leftRotate(node -> left);
                return rightRotate(node);
            }

            if(balance < -1 && x <= node -> right -> data){
                node -> right = rightRotate(node -> right);
                return leftRotate(node);
            }

            return node;
        }

        int getRank(Node* node, int x){
            if(node == nullptr){
                return 0;
            }

            if(x < node -> data){
                return getRank(node -> left, x);
            }
            else if(x > node -> data){
                return node -> left_count + 1 + getRank(node -> right, x);
            }
            else{
                return node -> left_count + 1;
            }
        }
};
int main(){
    RankTracker r;
    // number of queries
    int q;
    cin >> q;
    while(q--){
        int type, x;
        cin >> type >> x;
        if(type == 0){
            r.track(x);
        }
        else{
            cout << r.getRankOfNumber(x) - 1 << '\n';
        }
        r.printTree();
    }
    return 0;
}
