#include "tree.h"

//returns the height 

unsigned char tree::height(tree* point)
{
	return point ? point->heighht : 0;
}

//it finds the height of the tree

void tree::find_height(tree* point)
{

	if (point == NULL)
	{
		cout << "empty";
	}
	else
	{
		char LeftHeight = height(point->left);
		char RightHeight = height(point->right);
		point->heighht = (RightHeight > LeftHeight ? RightHeight : LeftHeight) + 1;
	}
}

//calculats the balance factor

int tree::balance_factor(tree* point)
{   
	
	return height(point->right) - height(point->left);
	
	
}

//checks for the balance factor

tree* tree:: balance(tree* point)
{

	if (balance_factor(point) == 2)
	{
		if (balance_factor(point->right) < 0)

			rotate_left(point->right);
		return rotate_right(point);
	
	}
	if (balance_factor(point) == -2)
	{
		if (balance_factor(point->left) < 0)

			rotate_right(point->left);
		return rotate_left(point);

	}
	return point;
}

//insert the value into the tree

void tree::insert(tree* &point,float cost,string name )
{
	if (point == NULL)
	{
		point = new tree;
		point->price = cost;
		pric.push_back(cost);
		point->name = name;
		Name.push_back(name);
		value = 1;
		point->left = NULL;
		point->right = NULL;
		
		
	}
	else if (point->price>cost)
	{
		
	    insert(point->left, cost,name);
	
	}
	else if (point->price < cost)
	{
		insert(point->right, cost, name);
	}
	else if (cost == point->price)
	{
		Name.push_back(name);
		pric.push_back(cost);
		//checks for the condition

	/*	if (name != point->name)
		{
			Name.push_back(name);
			pric.push_back(cost);
			if (point->price >cost)
			{
				insert(point->left, cost, name);
			}
			else
			{
				insert(point->right, cost, name);
			}
		}*/
	}
  balance(point);
}

//it rotates the tree left

 tree* tree::rotate_left(tree* point)
{
	tree* rotate;
	rotate = point->right;
	point->right = point->left;
	point->left = rotate;
	find_height(point);
	find_height(rotate);
	return point;

}

 //it rotates the tree right

 tree* tree:: rotate_right(tree* point)
{
	tree* rotate;
	rotate = point->left;
	point->left = point->right;
	point->right = rotate;
	find_height(point);
	find_height(rotate);
	return rotate;

}
 
 //prints the tree as inorder 

void tree::inorder(tree* point)
{ if (point!=NULL)
	{
		inorder(point->left);
		cout << "\nThe name is" << point->name;
		cout << "\nThe price is" << point->price;
		inorder(point->right);
		value++;
	
	}
}

//creates new tree and copies the value into it

void tree::copy_tree(tree *&copy, tree *&point)
{
	 if (point != NULL)
		
	{
		copy = new tree;
		copy->price = point->price;
		copy->name = point->name;
		copy_tree(copy->left, point->left);
		copy_tree(copy->right, point->right);
		value++;
		
	}
	
	
}

//makes the mirror copy 

void tree::mirror_copy(tree* copy)
{
	tree *temp;
	 if (copy != NULL)

	{
		mirror_copy(copy->left);
		mirror_copy(copy->right);
		temp = copy->left;
		copy->left = copy->right;
		copy->right = temp;
		value++;
	}

}

//display the products

void tree::display(tree* point,float price)
{
	int count = 0;
		for (int iterate = 0; iterate < pric.size(); iterate++)
		{
			if (price == pric.at(iterate))
			{
				cout << "\nthe price of the product is" <<endl<< pric.at(iterate);
				cout << endl << "The Name of the product is" << endl << Name.at(iterate);
				count++;
			}
		}
		
			if (count == 0)
			{
				cout << "\nelement not found";
			}

		
	
}

//number of products 

int tree::no_of_products(tree* &point, float cost)
{
	int iterat = 1;
	int temp=0;
	
	if (point != NULL)
	{
		
		 if (cost < point->price)
		{
			temp= no_of_products(point->left, cost);

		}
		else if (cost > point->price)
		{

			temp= no_of_products(point->right, cost);

		}
		else if (point->price == cost)
		{
			return point->Name.size();
			
		}
		
		
	}

	return temp;
	
}

int main()
{
	tree tre;
	tree *root = NULL; tree *rt;
	char choice;
	float price = 0.0;
	string name ;
	int iterat = 0;
	
	while (1)
	{
		cout << "\na.insert the values\nb.mirror copy\nc.sorting\nd.display number of products\n";
		cout << "Enter the  choice\n";
		cin >> choice;
		if (choice == 'a' || choice == 'b' || choice == 'c'||choice=='d')
		{
			switch (choice)
			{
			case 'a':
				cout << "\nEnter the product name";
				cin.ignore(10000, '\n');
				getline(cin, name);
				cout << "\nEnter the product price";
				cin >> price;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "invalid input for price";
				}
				if (!cin.fail())
				{
					tre.insert(root, price, name);
				}
				break;
			case 'b':
				cout << "mirror copy";
				if (tre.value == 0)
				{
					cout << "\n tree is empty";

				}

				else
				{
					tre.copy_tree(rt, root);
					tre.mirror_copy(rt);
					tre.inorder(rt);
				}
				break;
			case 'c':
				cout << "\nsorting by price";
				if (tre.value == 0)
				{

					cout << "\ntree is empty";
				}
				else
				{
					tre.inorder(root);
				}
				break;
			case 'd':
				if (tre.value == 0)
				{
					cout << "\ntree isempty";
				}
				else
				{
					cout << "Number of products\n";
					cout << "enter the price\n";
					cin >> price;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Invalid price";
					}
					else
					{
						tre.no_of_products(root, price);
						tre.display(root, price);
					}
				}
				break;
			}
		}
		else
		{
			cout << "Invalid choice";
			system("pause");
		}
	}
}
