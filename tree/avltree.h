#pragma once
#include<iostream>
#include <string>
#include<vector>
using namespace std;

//tree contains the product name and price and mirror copy 

class tree
{
public:
	int iterat = 0;
	float price = 0.0;
	string name;
	tree* left;
	tree* right;
	unsigned char heighht = 0;
	vector<string>Name;
	vector<int>pric;
	int value = 0;

public:
	void insert(tree* &point,float cost,string name);
    void display(tree* point,float price);
	tree* balance(tree* point);
	int balance_factor(tree* point);
	tree* rotate_right(tree* point);
	tree* rotate_left(tree* point);
	
	unsigned char height(tree* point);
	void  find_height(tree* point);
	void mirror_copy(tree* point);
	void inorder(tree* point);
	int no_of_products(tree* &point,float cost);
	void copy_tree(tree *&copy,tree *&point);
	
	
	
};










