#include <iostream>

template <typename T>
struct Node {
	T key;
	Node* left;
	Node* right;
	Node(T key) {
		this.key = key;
		left = right = NULL;
	}
};

// inorder tree walk to print out all the keys in a BST in sorted order
template <typename T>
void inorderTreeWalk(Node<T>* root) {
	if(root == NULL) {
		return;
	}
	inorderTreeWalk(root->left);
	std::cout << root->key << "\n";
	inorderTreeWalk(root->right);
}


// fn to insert a new node with the given key in BST
template <typename T>
Node<T>* insert(Node<T>* node, int key) {

	// If ke
}

// function to search a key in BST, recursive method
template <typename T>
Node<T>* search(Node<T>* root, T key) {

	// Base cases: root is null or key is present at root
	// If root is null that means key is not found in tree
	if(root == NULL || key == root->key)
		return root;
	
	// Key is lesser than roots key
	if(key < root->key)
		return search(root->left, key);
	else 
		return search(root->right, key);
}



int main() {
	return 0;
}