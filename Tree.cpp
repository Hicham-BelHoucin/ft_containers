/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:32:49 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/02 12:31:32 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RedBlackTree.hpp"

typedef RedBlackTree<int, std::less<int>, std::allocator<int> >::Tree Nodeptr;
// bool isBalancedUtil(Nodeptr root, int &maxh, int &minh)
// {
//     // Base case
//     if (root == NULL)
//     {
//         maxh = minh = 0;
//         return true;
//     }

//     int lmxh, lmnh; // To store max and min heights of left subtree
//     int rmxh, rmnh; // To store max and min heights of right subtree

//     // Check if left subtree is balanced, also set lmxh and lmnh
//     if (isBalancedUtil(root->left, lmxh, lmnh) == false)
//         return false;

//     // Check if right subtree is balanced, also set rmxh and rmnh
//     if (isBalancedUtil(root->right, rmxh, rmnh) == false)
//         return false;

//     // Set the max and min heights of this node for the parent call
//     maxh = std::max(lmxh, rmxh) + 1;
//     minh = std::min(lmnh, rmnh) + 1;

//     // See if this node is balanced
//     if (maxh <= 2 * minh)
//         return true;

//     return false;
// }

bool isHeightBalanced(Nodeptr root, int &rootMax)
{
    // Base case
    if (root == nullptr) {
        return true;
    }

    // to hold the maximum height of the left and right subtree
    int leftMax = 0, rightMax = 0;

    // proceed only if both left and right subtrees are balanced
    if (isHeightBalanced(root->left, leftMax) &&
        isHeightBalanced(root->right, rightMax))
    {
        // calculate the minimum and maximum height of the left and right subtree
        int rootMin = std::min(leftMax, rightMax) + 1;
        rootMax = std::max(leftMax, rightMax) + 1;

        // return true if the root node is height-balanced
        return (rootMax <= 2*rootMin);
    }

    // return false if either left or right subtree is unbalanced
    return false;
}


// A wrapper over isBalancedUtil()
bool isBalanced(Nodeptr root)
{
    int maxh, minh;
    // return isBalancedUtil(root, maxh, minh);
    return isHeightBalanced(root, maxh);
}

int random(int min, int max)
{
	return std::rand() % max + min;
}

int main(void)
{
	RedBlackTree<int, std::less<int>, std::allocator<int> > Tree;
	// int myints[150] = {331, 472, 386, 466, 285, 255, 395, 371, 428, 485, 492, 391, 441, 432, 250, 478, 471, 340, 304, 266, 348, 429, 262, 284, 388, 316, 286, 422, 435, 282, 288, 383, 324, 496, 463, 252, 350, 437, 349, 480, 443, 354, 491, 374, 399, 386, 361, 498, 468, 483, 399, 497, 496, 275, 363, 263, 350, 291, 458, 372, 311, 393, 299, 428, 388, 384, 355, 336, 332, 315, 437, 301, 267, 494, 479, 392, 296, 460, 353, 338, 376, 283, 409, 406, 478, 262, 492, 418, 290, 355, 424, 326, 277, 409, 268, 338, 485, 406, 435, 251, 284, 327, 362, 406, 444, 381, 363, 458, 287, 336, 456, 317, 379, 447, 403, 317, 258, 435, 284, 474, 251, 373, 476, 340, 462, 262, 390, 298, 416, 412, 257, 342, 270, 382, 362, 456, 446, 361, 385, 331, 499, 293, 268, 344, 491, 429, 421, 476, 338, 457};
	// for (int i = 0; i < 1500; i++)
	// 	myints[i] = std::rand() % 10000 + 1;
	// srand(time(0));

	// Tree.root = Tree.insert(Tree.root, 10);
	// Tree.root = Tree.insert(Tree.root, 9);
	// Tree.root = Tree.insert(Tree.root, 85);
	// Tree.root = Tree.insert(Tree.root, 7);
	// Tree.root = Tree.insert(Tree.root, -66);
	// Tree.root = Tree.insert(Tree.root, 51);
	// Tree.root = Tree.insert(Tree.root, 40);
	// Tree.root = Tree.insert(Tree.root, -3);
	for (int i = 0; i < 174 ; i++)
		Tree.root = Tree.insert(Tree.root, random(15, 35000));
	// Tree.root = Tree.insert(Tree.root, 11);
	// Tree.root = Tree.insert(Tree.root, 12);


	Tree.Inorder(Tree.root, 0);
	isBalanced(Tree.root) ? std::cout << "Balanced\n" : std::cout << "Not Balanced\n";
	return 0;
}