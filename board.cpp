#include<iostream>
typedef struct pawn{
	int player;
	int b_posx,b_posy;
	int e_posx,e_posy;
}pawn;

class Board{
public:
	int board[8][8];
	const int player; //player is designated with number 2 for easier reference throught the code
	const int bot; //similarily designated with number 1
	Board();

	pawn* check_valid_attack(pawn*);//If movement is an attack then checks if valid if so then calls the possible move for a cascading attack automagically
	pawn* check_valid_jump(pawn*);//checks for basic validty in movement
	pawn* create_pawn(int beg_x, int beg_y, int end_x, int end_y, int player);//Generates valid pawn struct // basically initializes struct pawn and calls checker funcs
	bool jump(int beg_x, int beg_y, int end_x, int end_y, int player);

}Board;

Board::Board():bot(1),player(2){
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

bool Board::jump(int beg_x, int beg_y, int end_x, int end_y, int player){
	if(check_valid_attack(check_valid_jump(create_pawn(beg_x,beg_y,end_x,end_y,player))))
		return true; else return false;
}
pawn* Board::create_pawn(int beg_x, int beg_y, int end_x, int end_y, int player){
	pawn* temp;
	temp->b_posx = beg_x;
	temp->b_posy = beg_y;
	temp->e_posx = end_x;
	temp->e_posy = end_y;
	temp->player = player;

	return temp;
}

pawn* Board::check_valid_jump(pawn* play){
	if(play == NULL){
		std::cout<<"create_pawn failure!!";
		return NULL;
	}
	else {
		//checks for board boundary and pawn overlapping and illegal pawn movement
		return play;
	}
}

pawn* Board::check_valid_attack(pawn* play){
	if(play == NULL){
		std::cout<<"jump validity failed!!";//temporary output for error checking
		return NULL;
	}
	else
		return play;
}
int main(){
	for(int i = 0 ; i<8 ; i++){
		for(int j = 0 ; j<8 ; j++){
			std::cout<<Board.board[i][j]<<" ";
		}
		std::cout<<"\n";
	}

}
