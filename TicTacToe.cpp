#include <iostream>
#include <string>
using namespace std;


class Game
{
private:
  char value;
public:
    Game ()
  {
    this->value = '-';
  }
  void setValue (char letter)
  {
    this->value = letter;
  }
  char getValue ()
  {
    return this->value;
  }
  void display (Game arr[9])
  {
    cout << endl << " " << arr[0].
      getValue () << " | " << arr[1].getValue () << " | " << arr[2].
      getValue () << " " << endl;
    cout << " " << arr[3].
      getValue () << " | " << arr[4].getValue () << " | " << arr[5].
      getValue () << " " << endl;
    cout << " " << arr[6].
      getValue () << " | " << arr[7].getValue () << " | " << arr[8].
      getValue () << " " << endl;
  }
};

string
statusx (Game arr[])
{
  string status;
  if (arr[0].getValue () != '-' && arr[1].getValue () != '-'
      && arr[2].getValue () != '-' || arr[3].getValue () != '-'
      && arr[4].getValue () != '-' && arr[5].getValue () != '-'
      || arr[6].getValue () != '-' && arr[7].getValue () != '-'
      && arr[8].getValue () != '-' || arr[0].getValue () != '-'
      && arr[4].getValue () != '-' && arr[8].getValue () != '-'
      || arr[2].getValue () != '-' && arr[4].getValue () != '-'
      && arr[6].getValue () != '-' || arr[0].getValue () != '-'
      && arr[3].getValue () != '-' && arr[6].getValue () != '-'
      || arr[1].getValue () != '-' && arr[4].getValue () != '-'
      && arr[7].getValue () != '-' || arr[2].getValue () != '-'
      && arr[5].getValue () != '-' && arr[8].getValue () != '-')
    {
      if (arr[0].getValue () == 'X' && arr[1].getValue () == 'X'
	  && arr[2].getValue () == 'X' || arr[3].getValue () == 'X'
	  && arr[4].getValue () == 'X' && arr[5].getValue () == 'X'
	  || arr[6].getValue () == 'X' && arr[7].getValue () == 'X'
	  && arr[8].getValue () == 'X' || arr[0].getValue () == 'X'
	  && arr[4].getValue () == 'X' && arr[8].getValue () == 'X'
	  || arr[2].getValue () == 'X' && arr[4].getValue () == 'X'
	  && arr[6].getValue () == 'X' || arr[0].getValue () == 'X'
	  && arr[3].getValue () == 'X' && arr[6].getValue () == 'X'
	  || arr[1].getValue () == 'X' && arr[4].getValue () == 'X'
	  && arr[7].getValue () == 'X' || arr[2].getValue () == 'X'
	  && arr[5].getValue () == 'X' && arr[8].getValue () == 'X')
	{
	  status = "X wins!";
	}
      else if (arr[0].getValue () == 'O' && arr[1].getValue () == 'O'
	  && arr[2].getValue () == 'O' || arr[3].getValue () == 'O'
	  && arr[4].getValue () == 'O' && arr[5].getValue () == 'O'
	  || arr[6].getValue () == 'O' && arr[7].getValue () == 'O'
	  && arr[8].getValue () == 'O' || arr[0].getValue () == 'O'
	  && arr[4].getValue () == 'O' && arr[8].getValue () == 'O'
	  || arr[2].getValue () == 'O' && arr[4].getValue () == 'O'
	  && arr[6].getValue () == 'O' || arr[0].getValue () == 'X'
	  && arr[3].getValue () == 'O' && arr[6].getValue () == 'O'
	  || arr[1].getValue () == 'O' && arr[4].getValue () == 'O'
	  && arr[7].getValue () == 'O' || arr[2].getValue () == 'O'
	  && arr[5].getValue () == 'O' && arr[8].getValue () == 'O')
	{
	  status = "O wins!";
	}
      else if (arr[0].getValue () != '-' && arr[1].getValue () != '-'
	  && arr[2].getValue () != '-' && arr[3].getValue () != '-'
	  && arr[4].getValue () != '-' && arr[5].getValue () != '-'
	  && arr[6].getValue () != '-' && arr[7].getValue () != '-'
	  && arr[8].getValue () != '-')
	{
	  status = "draw";
	}
      else
	{
	  status = "playing";
	}
    }
  else
    {
      status = "playing";
    }

  return status;
};

int
occupied (int x, Game arr[])
{
  if (arr[x].getValue () == 'O' || arr[x].getValue () == 'X')
    {
      return 1;
    }
  else
    {
      return 0;
    }
};



int
main ()
{
  string status = "playing";
  Game dummy;
  Game sq0, sq1, sq2, sq3, sq4, sq5, sq6, sq7, sq8;
  Game arr[9];
  Game ();
  arr[0] = sq0, arr[1] = sq1, arr[2] = sq2, arr[3] = sq3, arr[4] =
    sq4, arr[5] = sq5;
  arr[6] = sq6, arr[7] = sq7, arr[8] = sq8;
  dummy.display (arr);

  while (status == "playing")
    {
      int xmove;
      int omove;
      cout << endl << "X to move: " << endl << "move: ";
      cin >> xmove;
      if (occupied (xmove, arr) == 1)
	{
	  cout << "That square is alread taken. Try again. " << endl;
	  cin >> xmove;
	}
      arr[xmove].setValue ('X');
      dummy.display (arr);
      status = statusx (arr);
      cout << status << endl;
      if (status != "playing")
	{
	  break;
	}
      cout << endl << "O to move: " << endl << "move: ";
      cin >> omove;
      if (occupied (omove, arr) == 1)
	{
	  cout << "That square is already taken. Try again. " << endl;
	  cin >> omove;
	}
      arr[omove].setValue ('O');
      dummy.display (arr);
      status = statusx (arr);
      cout << status << endl;
    }

  return 0;
}
