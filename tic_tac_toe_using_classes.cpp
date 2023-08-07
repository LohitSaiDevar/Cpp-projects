#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

static int player = 1,i,choice;
static char sign;
static char t[9] = {'1','2','3','4','5','6','7','8','9'};
class Tic
{
	public:
	
	void table();
	void replace();
	int winner();
};

//Functions of class Tic
void Tic::table()//To create the Tic Tac Toe field
{
	system ("CLS");
		
		cout<<"\n\n\tTic Tac Toe\n\n";
	    cout<<"Player 1 (X)  -  Player 2 (O)\n\n\n";
	    
		
		cout<<"       |       |       "<<endl;
		cout<<"   "<<t[0]<<"   |   "<<t[1]<<"   |   "<<t[2]<<"   "<<endl;
		cout<<"_______|_______|_______"<<endl;
		cout<<"       |       |       "<<endl;
		cout<<"   "<<t[3]<<"   |   "<<t[4]<<"   |   "<<t[5]<<"   "<<endl;
		cout<<"_______|_______|_______"<<endl;
		cout<<"       |       |       "<<endl;
		cout<<"   "<<t[6]<<"   |   "<<t[7]<<"   |   "<<t[8]<<"   "<<endl;
		cout<<"       |       |       "<<endl;
}
void Tic::replace()//To replace the integer 'choice' with 'X' or 'O'
{
	player = (player % 2) ? 1 : 2;
		
		cout<<"Player "<<player<<":\nPick ur place to enter: ";
		cin>>choice;
		
		sign = (player == 1) ? 'X' : 'O';
		if(choice == 1 && t[0] == '1')
		{
			t[0] = sign;
		}
		else if(choice == 2 && t[1] == '2')
		{
			t[1] = sign;
		}
		else if(choice == 3 && t[2] == '3')
		{
			t[2] = sign;
		}
		else if(choice == 4 && t[3] == '4')
		{
			t[3] = sign;
		}
		else if(choice == 5 && t[4] == '5')
		{
			t[4] = sign;
		}
		else if(choice == 6 && t[5] == '6')
		{
			t[5] = sign;
		}
		else if(choice == 7 && t[6] == '7')
		{
			t[6] = sign;
		}
		else if(choice == 8 && t[7] == '8')
		{
			t[7] = sign;
		}
		else if(choice == 9 && t[8] == '9')
		{
			t[8] = sign;
		}
		else
		{
			cout<<"Invalid Input!\nTry again"<<endl;
		
			player--;
			getchar();
		}
}
int Tic::winner()//To check whether one of the players is the winner or not
{
	if(t[0] == t[1] && t[1] == t[2])
		{
			return 1;
		}
		else if(t[0] == t[3] && t[3] == t[6])
		{
			return 1;
		}
		else if(t[0] == t[4] && t[4] == t[8])
		{
			return 1;
		}
		else if(t[1] == t[4] && t[4] == t[7])
		{
			return 1;
		}
		else if(t[2] == t[5] && t[5] == t[8])
		{
			return 1;
		}
		else if(t[3] == t[4] && t[4] == t[5])
		{
			return 1;
		}
		else if(t[6] == t[4] && t[4] == t[2])
		{
			return 1;
		}
		else if(t[6] == t[7] && t[7] == t[8])
		{
			return 1;
		}
		else if(t[0] != '1' && t[1] != '2' && t[2] != '3' && t[3] != '4' && t[4] != '5' && t[5] != '6' && t[6] != '7' && t[7] != '8' && t[8] != '9')
		{
			return 0;
		}
		else
		{
			return -1;
		}
}
int main()
{
	Tic p;
	do
	{
		p.table();
		p.replace();
		p.table();
		i = p.winner();
		player++;
	}while(i == -1);//The game won't stop until i != -1
	
	if(i == 1)
	{
		--player;
		cout<<"Winner is player "<<player<<"\nPress any key to exit:";
	}
	else
	{
		cout<<"Game is draw\nPress any key to exit:";
	}
	return 0;
}
