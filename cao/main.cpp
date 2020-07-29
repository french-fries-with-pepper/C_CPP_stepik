#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
class Box{
// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);
public:
    Box(){
        l=0;
        b=0;
        h=0;
    }
    Box(int A, int B, int C){
        l=A;
        b=B;
        h=C;
    }
    Box(const Box &another){
        l=another.l;
        b=another.b;
        h=another.h;
    }

int getLength(){  // Return box's length
    return l;
}; 

int getBreadth (){  // Return box's breadth
    return b;
};

int getHeight (){  //Return box's height
    return h;
};

long long CalculateVolume(){ // Return the volume of the box
    return static_cast<long long>(l)*b*h;
};

bool operator<(const Box &another){
    bool flag = false;
    if (l<another.l)
    {
        flag = true;
        return flag;
    };
    if(b<another.b&&l==another.l)
    {
        flag = true;
        return flag;
    };
    if(h<another.h&&l==another.l&&b==another.b)
    {
        flag = true;
        return flag;
    };
    return flag;
};



friend ostream& operator<<(ostream& out, Box& B){
    out << B.l << " " << B.b << "" << B.h;
    return out; 
}

//l,b,h are integers representing the dimensions of the box
private:
    int l;
    int b;
    int h;
};

// The class should have the following functions : 




// int getBreadth (); 
//   
//  

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}