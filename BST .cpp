
#include <bits/stdc++.h>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

node *newNode(int item) {
  node *temp = new node();
  temp->key = item;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " -> ";
    inorder(root->right);
  }
}

node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);

  if (key < node->key){
    node->left = insert(node->left, key);
  } else {
    node->right = insert(node->right, key);
  }

  return node;
}

node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

node *deleteNode(node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }

    node *temp = minValueNode(root->right);

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

void searchNode (node* root, int key) {
    if(root->key == key) {
        cout << "\n" << key << " Found.";
        return;
    } else if(key < root->key) {
        if(root->left == NULL) {
            cout << "\n" << key << " Not Found";
            return;
        }
        searchNode(root->left, key);
    } else {
        if(root->right == NULL) {
            cout << "\n" << key << " Not Found";
            return;
        }
        searchNode(root->right, key);
    }
}

int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);

  searchNode(root, 10);

  cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);

  searchNode(root, 10);

  cout << "\nInorder traversal: ";
  inorder(root);
}
