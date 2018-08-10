#include<iostream>
//Just for wrapping a singl instance of the game! That it is contains data for one particular move by an player
typedef struct tile{
	pawn* coin;
}tile;

typedef struct pawn{
	int player;
	int x,y;
}pawn;

class Board{
public:
	int status; //HOLDS GAME STATUS// //-1 = initial state// //0 = Tie// //1 = playerAI Won// //2 = botAI Won//
	tile board[8][8];//0 marks empty tile// //1 marks bot tile// //2 marks player tile// //-1 marks bot_king tile// //-2 marks player_king tile//
	const int player; //2// //player is designated with number 2 for easier reference throught the code
	const int bot; //1// //similarily designated with number 1
	const int player_king;//-2//
	const int bot_king;//-1//
	const int tile;
	Board();

	bool playerAI(); //Runs the AI// //Contestant can use bool to error check code, also used by check_game_status!//
	bool botAI(); //Runs Computer's AI
	bool check_game_status(bool);//Checks for change in board's status and returns true if game's status hasn't changed!//

	pawn* check_valid_jump(int beg_x, int beg_y, int end_x, int end_y, int player);//checks for basic validty in movement//
	pawn* create_pawn(int beg_x, int beg_y, int end_x, int end_y, int player);//Generates valid pawn struct // basically initializes struct pawn and calls checker funcs
	bool jump(int beg_x, int beg_y, int end_x, int end_y, int player);

};

Board::Board():bot(1),player(2),bot_king(-1),player_king(-2),tile(0){
	//Inits data members!
	status = -1;
	//Generates Board
	for (int i = 0; i<8 ; i++){
		for(int j = 0; j<8 ; j++)
			if(i<3 && ((i%2==0 && j%2!=0)||(i%2!=0 && j%2==0)))
				this->board[i][j] = create_pawn(i,j,this->bot);
			else if(i>4 && ((i%2!=0 && j%2==0)||(i%2==0 && j%2!=0)))
				this->board[i][j]->coin = create_pawn(i,j,this->player);
			else
				this->board[i][j]->coin = create_pawn(i,j,this->tile);
	}
	//GAME STARTS HERE
	while(status==-1){//will continue till game status is changed by check_game_status
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
	//The function that must be called to make move it will return false if illegal move is made
	bool success = false;
	if(check_valid_jump(beg_x,beg_y,end_x,end_y,player))
		success = true; else success = false;
	return success;
}

pawn* Board::create_pawn(int x, int y, int player){
	pawn* temp;
	temp->x = x;
	temp->y = y;
	temp->player = player;
	return temp;
}

pawn* Board::check_valid_jump(int beg_x, int beg_y, int end_x, int end_y, int player)
	
}

bool Board::playerAI(){
	//This function does not run per turn the bot must either loop and run methods again other wise call itself
	//if cascading moves aren't taken care of check_game_status will throw errors
	return true;
}
bool Board::botAI(){
	return true;
}

int main(){
	Board Game;
}
