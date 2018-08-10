#include<iostream>

//Just for wrapping a singl instance of the game! That it is contains data for one particular move by an player
typedef struct pawn{
	int player;
	int b_posx,b_posy;
	int e_posx,e_posy;
}pawn;

class Board{
public:
	int status; //HOLDS GAME STATUS// //-1 = initial state// //0 = Tie// //1 = playerAI Won// //2 = botAI Won//
	int board[8][8];//0 marks empty tile// //1 marks bot tile// //2 marks player tile// //-1 marks bot_king tile// //-2 marks player_king tile//
	const int player; //2// //player is designated with number 2 for easier reference throught the code
	const int bot; //1// //similarily designated with number 1
	const int player_king;//-2//
	const int bot_king;//-1//
	Board();

	bool playerAI(); //Runs the AI// //Contestant can use bool to error check code, also used by check_game_status!//
	bool botAI(); //Runs Computer's AI
	bool check_game_status(bool);//Checks for change in board's status and returns true if game's status hasn't changed!//

	pawn* check_valid_jump(pawn*);//checks for basic validty in movement//
	pawn* create_pawn(int beg_x, int beg_y, int end_x, int end_y, int player);//Generates valid pawn struct // basically initializes struct pawn and calls checker funcs
	bool jump(int beg_x, int beg_y, int end_x, int end_y, int player);

}Board;

Board::Board():bot(1),player(2),bot_king(-1),player_king(-2){
	//Inits data members!
	status = -1;
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
	//GAME STARTS HERE
	while(status==-1){
		if(check_game_status(playerAI())) //After playerAI's call and the return value is true check_game_status will checks board's status and update status
			check_game_status(botAI());
	}
}

bool Board::check_game_status(bool flag){
	if(flag){
		for(int i = 0 ; i<8 ; i++){
			for(int j = 0 ; j<8 ; j++){
				//status check will update flag value
				flag = true;//if all checks passed!
			}
		}
	}
	else{
		std::cout<<"AI function call failed!\n";
	}
	return flag;
}
bool Board::jump(int beg_x, int beg_y, int end_x, int end_y, int player){
	bool success = false;
	if(check_valid_jump(create_pawn(beg_x,beg_y,end_x,end_y,player)))
		success = true; else success = false;
	return success;
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
		std::cout<<"create_pawn failure!!";//temporary output for error checking
		return NULL;
	}
	else {
		//checks for board boundary and pawn overlapping and illegal pawn movement
		return play;
	}
}

bool Board::playerAI(){
	return true;
}
bool Board::botAI(){
	return true;
}

int main(){
	for(int i = 0 ; i<8 ; i++){
		for(int j = 0 ; j<8 ; j++){
			std::cout<<Board.board[i][j]<<" ";
		}
		std::cout<<"\n";
	}

}
