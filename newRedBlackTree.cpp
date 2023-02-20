#include <iostream>

# define BOLDBLACK	"\033[1m\033[30m"      /* Bold Black */
# define BOLDRED	"\033[1m\033[31m"      /* Bold Red */
# define RESET		"\033[0m"
# define COUNT 		10

#define BLACK (0)
#define RED (1)

#include <map>

enum Events
{
    RR = 1,
    LR,
    LRR,
    RLR,
};

struct Node
{
    int data;
    int event;
    int color;
    Node *left;
    Node *right;
    Node *parent;
    std::map<int, std::string> map;
    Node()
        : data(0), right(NULL), left(NULL), parent(NULL), event(0), color(RED)
    {
        map.insert(std::make_pair(RR, "RIGHTROTATION"));
        map.insert(std::make_pair(LR, "LEFTROTATION"));
        map.insert(std::make_pair(LRR, "LEFTRIGHTROTATION"));
        map.insert(std::make_pair(RLR, "RIGHTLEFTROTATION"));
        
    }
    Node(int data, Node * parent)
        : data(data), right(NULL), left(NULL), parent(parent), event(0), color(RED)
    {
        map.insert(std::make_pair(RR, "RIGHTROTATION"));
        map.insert(std::make_pair(LR, "LEFTROTATION"));
        map.insert(std::make_pair(LRR, "LEFTRIGHTROTATION"));
        map.insert(std::make_pair(RLR, "RIGHTLEFTROTATION"));
        this->color = parent ? RED : BLACK;
    }
    Node * getUncle(void) {
        Node * grandParent;

        if (this->parent)
        {
            grandParent = this->parent->parent;
            // std::cout << "getUncle"<< this << grandParent << std::endl;
        }
        if (grandParent)
        {
            
            if (parent->isRightChild())
                return grandParent->left;
            return grandParent->right;
        }
        return (NULL);
    }
    bool isRightChild(void) {
        if (this->parent)
            return this->parent->right == this;
        return false;
    }
    void recolor(void) {
        this->color = this->color == RED ? BLACK : RED;
    }
    bool isRoot(void) {
        return (this->parent == NULL);
    }
    Node * getGrandFather(void) {
        return this->parent && this->parent->parent ? this->parent->parent : NULL;
    }
    std::string getColor(void) const {
        return (this->color == BLACK ? BOLDBLACK : BOLDRED);
    }
    bool isRedRed(void) {
        return this->parent ? this->parent->color == RED && this->color == RED : false;
    }
    Node * min() {
        Node * _min = this;
        while (_min->left)
            _min = _min->left;
        return _min;
    }
    Node * max() {
        Node * _max = this;
        while (_max->right)
            _max = _max->right;
        return _max;
    }
    Node * successor() {
        Node * _successor = this->right;
        if (!_successor)
            return parent;
        return _successor->min();
    }
    Node * predecessor() {
        Node * _predecessor = this->left;
        if (!_predecessor)
            return parent;
        return _predecessor->max();
    }
    Node * hasOneChild(void) {
        if (hasNoChilds() || hasTwoChilds())
            return NULL;
        return this->left ? this->left : this->right;
    }
    bool hasNoChilds(void) {
        return this->left == NULL && this->right == NULL;
    }
    bool hasTwoChilds(void) {
        return this->left != NULL && this->right != NULL;
    }
    friend std::ostream& operator<<(std::ostream& os, const Node * node);
};

std::ostream& operator<<(std::ostream& os, const Node * node)
{
    os << " " << node->getColor() << node->data  << " " << RESET;
    return os;
}

class RedBlackTree
{
    public:
        Node *root;
    private:

        Node* leftRotate(Node* x)
        {
            Node* y = x->right;
            Node* T2 = y->left;

            // Perform rotation
            y->left = x;
            x->right = T2;

            // Update parent pointers
            y->parent = x->parent;
            if (x->parent == nullptr) {
                root = y;
            } else if (x == x->parent->left) {
                x->parent->left = y;
            } else {
                x->parent->right = y;
            }
            x->parent = y;
            if (T2 != nullptr) {
                T2->parent = x;
            }

            return y;
        }


        Node* rightRotate(Node* y)
        {
            Node* x = y->left;
            Node* T2 = x->right;

            // Perform rotation
            x->right = y;
            y->left = T2;

            // Update parent pointers
            x->parent = y->parent;
            if (y->parent == nullptr) {
                root = x;
            } else if (y == y->parent->left) {
                y->parent->left = x;
            } else {
                y->parent->right = x;
            }
            y->parent = x;
            if (T2 != nullptr) {
                T2->parent = y;
            }

            return x;
        }

        int		getRotationType(Node * root, Node * newnode)
        {
            if (!newnode || !root)
                return 0;
            if (root->isRightChild() && newnode->isRightChild())
                return LR;
            else if (!root->isRightChild() && !newnode->isRightChild())
                return RR;
            else if (!root->isRightChild() && newnode->isRightChild())
                return LRR;
            else if (root->isRightChild() && !newnode->isRightChild())
                return RLR;
            return 0;
        }

        Node * blanceTree(Node *node) {
            if (node->isRoot())
                node->color = BLACK;
            else if (node->isRedRed())
            {
                Node * uncle = node->getUncle();
                if (uncle && uncle->color == RED)
                {
                    Node * grandParent = node->getGrandFather();
                    node->parent->recolor();
                    uncle->recolor();
                    if (grandParent)
                        grandParent->recolor();
                    node->event = 0;
                }
                else if (!uncle || uncle->color == BLACK)
                {
                    int rotation = getRotationType(node->parent, node);
                    if (node->parent->parent)
                        node->parent->parent->event = rotation;
                }
            }
            return node;
        }
        Node * insert(Node * node, int data, Node * parent) {
            if (!node)
                return new Node(data, parent);
            else if (node->data < data)
            {
                node->right = insert(node->right, data, node);
                node->right =  blanceTree(node->right);

            }
            else if (node->data > data)
            {
                node->left = insert(node->left, data, node);
                node->left = blanceTree(node->left);
            }
            else if (node->data == data)
                return node;
            if (node->event)
            {
                if (node->event == RR)
                {
                    node->event = 0;
                    node = rightRotate(node);
                    node->recolor();
                    if (node->right)
                        node->right->recolor();
                }
                else if (node->event == LR)
                {
                    node->event = 0;
                    node = leftRotate(node);
                    node->recolor();
                    if (node->left)
                        node->left->recolor();
                }
                else if (node->event == RLR)
                {
                    node->event = 0;
                    node->right = rightRotate(node->right);
                    node = leftRotate(node);
                    node->recolor();
                    if (node->left)
                        node->left->recolor();
                }
                else if (node->event == LRR)
                {
                    node->event = 0;
                    node->left = leftRotate(node->left);
                    node = rightRotate(node);
                    node->recolor();
                    if (node->right)
                        node->right->recolor();
                }
            }
            return blanceTree(node);
        }
        bool isBalancedUtil(Node *root, int &maxh, int &minh)
        {
            // Base case
            if (root == NULL)
            {
                maxh = minh = 0;
                return true;
            }
        
            int lmxh, lmnh; // To store max and min heights of left subtree
            int rmxh, rmnh; // To store max and min heights of right subtree
        
            // Check if left subtree is balanced, also set lmxh and lmnh
            if (isBalancedUtil(root->left, lmxh, lmnh) == false)
                return false;
        
            // Check if right subtree is balanced, also set rmxh and rmnh
            if (isBalancedUtil(root->right, rmxh, rmnh) == false)
                return false;
        
            // Set the max and min heights of this node for the parent call
            maxh = std::max(lmxh, rmxh) + 1;
            minh = std::min(lmnh, rmnh) + 1;
        
            // See if this node is balanced
            if (maxh <= 2*minh)
                return true;
        
            return false;
        }
        
        // A wrapper over isBalancedUtil()
        bool isBalanced(Node *root)
        {
            int maxh, minh;
            return isBalancedUtil(root, maxh, minh);
        }
        void replace_node(Node* node, Node* child) {
            child->parent = node->parent;
            if (node->parent == NULL) {
                // node is the root
                root = child;
            } else if (node == node->parent->left) {
                node->parent->left = child;
            } else {
                node->parent->right = child;
            }
        }
        Node * fixDoubleBlack(Node * node, int data) {
            if (!node)
                return root;
            else if (node->data < data)
                node->right = this->fixDoubleBlack(node->right, data);
            else if (node->data > data)
                node->left = this->fixDoubleBlack(node->left, data);
            
            return node;
        }
        Node * _delete(Node * node, int data) {
            if (!node)
                return root;
            else if (node->data < data)
                node->right = this->_delete(node->right, data);
            else if (node->data > data)
                node->left = this->_delete(node->left, data);
            if (node->data == data)
            {
                Node * child, *temp, *successor;
                if (node->hasNoChilds() && node->color == RED) {
                    delete node;
                    return NULL;
                }
                // else if (node->hasNoChilds() && node->color == BLACK)
                // {
                //     node->getUncle()->recolor();
                //     node->parent->recolor();
                    
                //     delete node;
                //     return NULL;
                // }
                else if ((child = node->hasOneChild()))
                {
                    temp = node ;
                    node = child;
                    child = NULL;
                    node->recolor();
                    delete temp; 
                    return node;
                }
                else if (node->hasTwoChilds()) {
                    successor = node->successor();
                    if (successor && successor->hasNoChilds() && successor->color == BLACK) {
                        node->data = successor->data;
                        successor->data = data;
                        node->right = _delete(node->right, data);
                    }
                    else if (successor && successor->hasNoChilds() && successor->color == RED) {
                        node->data = successor->data;
                        successor->data = data;
                        node->recolor();
                        node->right = _delete(node->right, data);
                    }
                }
            }
            return node;
        }
        void __clear(Node * node) {
            if (!node)
                return ;
            __clear(node->left);
            __clear(node->right);
            delete node; 
        }
    public:
        void clear(void) {
            __clear(this->root);
        }
        RedBlackTree()
            : root()
        {}
        ~RedBlackTree()
        {
            // this->clear();
        }
        void    set(int data) {
            this->root = insert(this->root, data, NULL);
        }
        void    erase(int data) {
            this->root = _delete(this->root, data);
        }
        // has , clear
        void	Inorder(Node * root, int before)
        {
            if (!root)
                return ;
            Inorder(root->right, before + COUNT);
            for (int i = 0; i < before; i++)
                std::cout << " ";
            std::cout << root;
            std::cout << std::endl;
            Inorder(root->left, before + COUNT);
        }

        void	Inorder(void) {
            Inorder(this->root, 0);
        }

        bool IsBlanced(void) {
            return isBalanced(root);
        }

};
#include <set>
#include <vector>
#include <algorithm>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <climits>
#include <unistd.h>
int main(void) {
    // std::vector
    // us
    RedBlackTree rbt;

    // rbt.set(3);
    // rbt.set(21);
    // rbt.set(32);
    // rbt.set(15);
    // rbt.set(4);
    // rbt.set(2);
    // rbt.set(1);
    // rbt.set(6);
    // rbt.set(8);
    // rbt.set(5);
    rbt.set(   38  ) ;
    rbt.set(   25  ) ;
    rbt.set(   30  ) ;
    rbt.set(   9   ) ;
    rbt.set(   2   ) ;
    // rbt.set(   5   ) ;
    rbt.set(   10   ) ;
    rbt.set(   40   ) ;

    int num = 2;
    rbt.erase(num);
    if (!rbt.IsBlanced())
    {
        std::cout << BOLDRED << "ERASED              " << num << "           FAILIER" << std::endl;
        rbt.Inorder();
        return 1;
    }
    // std::cout << "\033[1;32m ERASED              " << num << "           SUCCESSFULY" << std::endl;
    rbt.Inorder();
}