#include <bits/stdc++.h>
using namespace std;

class Products	
{
	int pcode, pstock;
	char pname[20], pcategory[10], ptype[10], porigin[20];
	float pprice;
	public:
		void enterdata()	
	{
		cout << "\nEnter product code: ";
		cin >> pcode;
		cout << "Enter product name: ";
		cin >> pname;
		cout << "Enter product category (M=Meat/P=Poultry/V=Vegetable): ";
		cin >> pcategory;
		cout << "Enter product type (F=Frozen/C=Chilled/D=Dry): ";
		cin >> ptype;
		cout << "Enter product stock: ";
		cin >> pstock;
		cout << "Enter product price: ";
		cin >> pprice;
		cout << "Enter country of origin for the product: ";
		cin >> porigin;
	}

	void putdata()	
	{
		cout << "Product code: " << pcode << endl;
		cout << "Product name: " << pname << endl;
		cout << "Product category: " << pcategory << endl;
		cout << "Product type: " << ptype << endl;
		cout << "Product stock: " << pstock << endl;
		cout << "Product price: " << pprice << endl;
		cout << "Product origin: " << porigin << endl;
	}

	void calculate()	//function to calculate price for order
	{
		int n;
		float d = 0.0, tp, sp, dp;
		cout << "\nEnter no of Product stock to order: ";
		cin >> n;
		if (n >= 500 && n < 1000)
		{
			d = 5;
		}
		else if (n > 1000)
		{
			d = 15;
		}

		sp = pprice * n;
		dp = d / 100;
		tp = sp - (sp *dp);
		cout << "\nDiscount rate is: " << d << "%" << endl;
		cout << "Discount offered: " << sp * dp << endl;
		cout << "Total Price after discount(if eligible) is: ";
		cout << tp << endl;
		cout << "Product placed on order\n";
		pstock = pstock - n;
	}

	int locatedata()	//returns pcode
	{
		return pcode;
	}
};
void add()	//function to add new products
{
	ofstream x;
	x.open("Products.dat", ios::binary | ios::app);
	Products p;
	int n;
	cout << "\nEnter no of records to enter: ";
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		p.enterdata();
		x.write((char*) &p, sizeof(p));
	}

	x.close();
}

void update()	//function to update existing details
{
	ifstream x;
	ofstream y;
	x.open("Products.dat", ios::binary);
	y.open("temp.dat", ios::binary);
	int a;
	cout << "\nEnter Product code whose details have to be changed: ";
	cin >> a;
	Products P;
	while (x.read((char*) &P, sizeof(P)))
	{
		if (a == P.locatedata())
		{
			P.enterdata();
			y.write((char*) &P, sizeof(P));
		}
		else
		{
			y.write((char*) &P, sizeof(P));
		}
	}

	x.close();
	y.close();
	remove("Products.dat");
	rename("temp.dat", "Products.dat");
	cout << "Product details updated\n";
}

void order()	//function to order product stock
{
	ifstream x;
	ofstream y;
	x.open("Products.dat", ios::binary);
	y.open("temp.dat", ios::binary);
	int a;
	cout << "Enter the Product's code: ";
	cin >> a;
	Products P;
	while (x.read((char*) &P, sizeof(P)))
	{
		if (a == P.locatedata())
		{
			P.calculate();
			y.write((char*) &P, sizeof(P));
		}
		else
		{
			y.write((char*) &P, sizeof(P));
		}
	}

	cout << "Product details updated\n";
	x.close();
	y.close();
	remove("Products.dat");
	rename("temp.dat", "Products.dat");
}

void pdisplay()	//function to display specific product details
{
	ifstream x;
	x.open("Products.dat", ios::binary);
	int a;
	cout << "\nEnter Product code whose details have to be displayed: ";
	cin >> a;
	Products P;
	while (x.read((char*) &P, sizeof(P)))
	{
		if (a == P.locatedata())
		{
			P.putdata();
		}

		x.close();
	}
}

void display()	//function to display all products
{
	Products P;
	ifstream x;
	x.open("Products.dat", ios::binary);
	while (x.read((char*) &P, sizeof(P)))
	{
		P.putdata();
	}

	x.close();
}

void del()	//function to delete entire product details
{
	remove("Products.dat");
	cout << "Product info deleted\n";
}

int main()	//main function
{
	int n;
	while (1)
	{
		cout << "Welcome to Gulf Foods \n\n";
		cout << "1. Add Products\n";
		cout << "2. Update details of a particular product\n";
		cout << "3. Place an order for a Product\n";
		cout << "4. Display details of a Product\n";
		cout << "5. Display details of all Products\n";
		cout << "6. Remove details of all Products\n";
		cout << "7. Exit\n";
		cout << "\nEnter your choice: ";
		cin >> n;
		switch (n)
		{
			case 1:
				add();
				break;
			case 2:
				update();
				break;
			case 3:
				order();
				break;
			case 4:
				pdisplay();
				break;
			case 5:
				display();
				break;
			case 6:
				del();
				break;
			case 7:
				exit(0);
		}
	}
}