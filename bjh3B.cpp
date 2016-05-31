// Ben Haase
// 12/2/15
// CS3130 project 3 part B
// Finding average height for varying number of BSTs with elements of 100, 500, and 1000

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <time.h>
using namespace std;

struct node{
	node * left;
	node * right;
	int key;
};

struct bst{
	node * root;
	int n;
};

bst * buildTree(int *, int);
void insert(bst*, int);
int height(node *);
void viewArray(int *, int);
int * copyArray(int *, int s);
void resetArr(int ***, int ***, int *);
void avgHeights(char);
int main(int argc, char* argv[])
{
	srand(time(NULL));
	if (argv[1] != NULL) avgHeights(*argv[1]);
	else avgHeights('0');

	return 0;
}

//function to build a tree from an array
bst * buildTree(int * a, int n){
	bst * x = new bst;
	x->root = NULL;
	x->n = 0;
	for (int i = 0; i < n; i++){
		insert(x, a[i]);
	}
	return x;
}

//function to insert a node into the BST
void insert(bst * x, int a){
	node * s = x->root;
	node * p = NULL;
	if (x->root != NULL){
		while (s != NULL){
			p = s;
			if (s->key > a){
				s = s->left;
			}
			else{
				s = s->right;
			}
		}
		node * t = new node;
		t->right = NULL;
		t->left = NULL;
		t->key = a;
		if (p->key > a) p->left = t;
		else p->right = t;
	}
	else {
		x->root = new node;
		x->root->key = a;
		x->root->left = NULL;
		x->root->right = NULL;
	}
	x->n = x->n + 1;
}

//function to find the height of the bst
int height(node * x){
	int c = 1;
	int d = 1;
	if (x->left != NULL) c += height(x->left);
	if (x->right != NULL) d += height(x->right);
	if (c > d) return c;
	else return d;
}

//function to copy an array
int * copyArray(int * a, int s){
	int * b = new int[s];
	for (int i = 0; i < s; i++) b[i] = a[i];
	return b;
}

//function to reset sorted array to original unsorted array
void resetArr(int *** a, int *** b, int * s){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 10; j++){
			delete[] b[i][j];
			b[i][j] = copyArray(a[i][j], s[i]);
		}
	}
}

//function to generate an array of random numbers
int * randomArrGen(int s){
	int * a = new int[s];
	for (int i = 0; i < s; i++){
		a[i] = rand() % 9000 + 1000;
	}
	return a;
}

//function to find the average heights of binary search trees
void avgHeights(char o){
	if (o == '0'){
		bst * t;
		int tn = 10;
		int n = 500;
		int * a[10];
		double b = 0;
		for (int i = 0; i < tn; i++){
			a[i] = randomArrGen(n);
			t = buildTree(a[i], n);
			b = b + height(t->root) - 1;
		}
		b = b / tn;
		cout << "t = 10" << endl << "N = 500" << endl << "Average height = " << b << endl;
	}
	else{
		bst * t;
		int tn[3] = { 5, 10, 15 };
		int n[3] = { 100, 500, 1000 };
		int * a[3][5];
		int * b[3][10];
		int * c[3][15];
		double ha[3];
		double hb[3];
		double hc[3];
		for (int i = 0; i < 3; i++){
			ha[i] = hb[i] = hc[i] = 0;
			for (int j = 0; j < 5; j++){
				a[i][j] = randomArrGen(n[i]);
				t = buildTree(a[i][j], n[i]);
				ha[i] += height(t->root) - 1;
			}
			for (int j = 0; j < 10; j++){
				b[i][j] = randomArrGen(n[i]);
				t = buildTree(b[i][j], n[i]);
				hb[i] += height(t->root) - 1;
			}
			for (int j = 0; j < 15; j++){
				c[i][j] = randomArrGen(n[i]);
				t = buildTree(c[i][j], n[i]);
				hc[i] += height(t->root) - 1;
			}
			ha[i] = ha[i] / 5;
			hb[i] = hb[i] / 10;
			hc[i] = hc[i] / 15;
		}
		cout << "t = 5" << endl;
		for (int i = 0; i < 3; i++) cout << "n = " << n[i] << ": " << ha[i] << endl;
		cout << endl << "t = 10" << endl;
		for (int i = 0; i < 3; i++) cout << "n = " << n[i] << ": " << hb[i] << endl;
		cout << endl << "t = 15" << endl;
		for (int i = 0; i < 3; i++) cout << "n = " << n[i] << ": " << hc[i] << endl;
	}
}
