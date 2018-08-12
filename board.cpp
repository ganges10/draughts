#include<iostream>
//Just for wrapping a singl instance of the game! That it i s contains data for one particular move by an player
struct pawn{
	int player;
	int x,y;
};
struct tile{
	pawn* coin;
};
class Board{
public:
	int status; //HOLDS GAME STATUS// //-1 = initial state// //0 = Tie// //1 = playerAI Won// //2 = botAI Won//
	tile board[8][8];//0 marks empty tile// //1 marks bot tile// //2 marks player tile// //-1 marks bot_king tile// //-2 marks player_king tile//
	const int player; //2// //player is designated with number 2 for easier reference throught the code
	const int bot; //1// //similarily designated with number 1
	const int player_king;//-2//
	const int bot_king;//-1//
	const int board_tile;//0//
	Board();

	bool playerAI(); //Runs the AI// //Contestant can use bool to error check code, also used by check_game_status!//
	bool botAI(); //Runs Computer's AI
	bool check_game_status(bool);//Checks for change in board's status and returns true if game's status hasn't changed!//

	pawn* check_valid_jump(pawn* ,int end_x,int end_y);//checks for basic validty in movement//
	pawn* create_pawn(int x, int y,int player);//Generates valid pawn struct // basically initializes struct pawn and calls checker funcs
	bool jump(int beg_x, int beg_y, int end_x, int end_y, int player);

};

Board::Board():bot(1),player(2),bot_king(-1),player_king(-2),board_tile(0){
	//Inits data members!
	status = -1;
	//Generates Board
	for (int i = 0; i<8 ; i++){
		for(int j = 0; j<8 ; j++)
			if(i<3 && ((i%2==0 && j%2!=0)||(i%2!=0 && j%2==0)))
				this->board[i][j].coin = create_pawn(i,j,bot);
			else if(i>4 && ((i%2!=0 && j%2==0)||(i%2==0 && j%2!=0)))
				this->board[i][j].coin = create_pawn(i,j,player);
			else
				this->board[i][j].coin = create_pawn(i,j,board_tile);
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
	pawn *play;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(i==beg_x && j==beg_y)
			{
				play=this->board[i][j].coin;
				break;
			}
		}
	}
	if(check_valid_jump(play,end_x,end_y))
		success = true;
	else
		success = false;
	return success;
}

pawn* Board::create_pawn(int x, int y, int player){
	pawn* temp;
	temp->x = x;
	temp->y = y;
	temp->player = player;
	return temp;
}

pawn* Board::check_valid_jump(pawn* play,int end_x,int end_y)
{
	if(play == NULL)
	{
		std::cout<<"create_pawn failure!!";//temporary output for error checking
		return NULL;
	}
	//checks for board boundary and pawn overlapping and illegal pawn movement
	else
	{
		if(end_x>8 || end_y>8 || end_x<0 || end_y<0)
			return NULL; //checking for board boundary;
		else if(board[end_x][end_y].coin->player==0) //to check if the position is empty
		{
			if((end_x-1==play->x && end_y-1==play->y) || (end_x+1==play->x && end_y-1 ==play->y) || (end_x-2==play->x && end_y-2==play->y) || (end_x+2==play->x && end_y-2 ==play->y))
			{
				play->x=end_x;
				play->y=end_y;
				if(end_x==7 && play->player==bot) //if the bot reaches the end of the board the pawn is made to king
						play->player=bot_king;
				if(end_x==0 && play->player==player)//if the player reaches the end of the board the pawn is made to king
						play->player=player_king;
				return play;
			}
			else if(play->player==bot_king || play->player==player_king)//condition to check for backward movement of the king
			{
				if((end_x-1==play->x && end_y+1==play->y) || (end_x+1==play->x && end_y+1==play->y)|| (end_x-2==play->x && end_y+2==play->y) || (end_x+2==play->x && end_y+2==play->y))
				{
					play->x=end_x;
					play->y=end_y;
					return play;
				}
			}
		}
		return NULL;
	}
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
	for(int i = 0 ; i<8 ; i++){
		for(int j = 0 ; j<8 ; j++){
			std::cout<<Game.board[i][j].coin->player<<" ";
		}
		std::cout<<"\n";
	}
}
