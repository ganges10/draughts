#include<iostream>
class Board{
public:
	int board[8][8];
	Board();
}Board;

Board::Board(){
	//Generates Board
	for (int i = 0; i<8 ; i++){
		for(int j = 0; j<8 ; j++)
			if(i<3 && ((i%2==0 && j%2!=0)||(i%2!=0 && j%2==0)))
				board[i][j] = 1;
			else if(i>4 && ((i%2!=0 && j%2==0)||(i%2==0 && j%2!=0)))
				board[i][j] = 2;
			else
				board[i][j] = 0;
	}
}

int main(){
	for(int i = 0 ; i<8 ; i++){
		for(int j = 0 ; j<8 ; j++){
			std::cout<<Board.board[i][j]<<" ";
		}
		std::cout<<"\n";
	}
}
