#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

/* Jesse Chess Master Engine v0.1
	  "Anything's possible"*/

//data type bitb represents a 64bit number -> a bitboard
//uint64_t is an unsigned integer with a width of exactly! 64 bits
typedef uint64_t bitb;

/*typedef struct bitboard {
	bitb bitboard;
	char* c;
} bitboard;*/

typedef struct gstate {
	bitb test;
	
	bitb bishops;
	
	bitb wpawns;
	bitb wknights;
	bitb wbishops;
	bitb wrooks;
	bitb wqueens;
	bitb wking;
	
	bitb bpawns;
	bitb bknights;
	bitb bbishops;
	bitb brooks;
	bitb bqueens;
	bitb bbking;
} gstate;

//void function that receives a bitboard and prints the individual bits represented
//function that prints the chessboard
void printb(bitb state) {
	bitb mask = 0x0000000000000001;
	mask <<= ((sizeof(uint64_t) * 8) - 1);
	
	//PRIu64 prints a uint64_t in decimal notation
	//PRIx64 prints a uint64_t in hexadecimal notation
	printf("printb %" PRIx64 "\n", state);
	
	
	int i = 0;
	
	while(mask) {
	
		if( i++ % 8 == 0 ) { 
			printf( "\n----------------" );
			printf( "\n" ); 
		}
		
		printf( "%d ", (state&mask ? 1 : 0) );
		mask >>= 1;
		
	}
	printf( "\n" ); 
}

/*bitb* init_state() {
	bitb init;
	bitb* init_board = &init;
	
	//initialize the bitboard to the initial state of the game
	*init_board = 0xffff00000000ffff;
	printf("init_state %" PRIx64 "\n", *init_board);
	
	return init_board;
}*/



gstate* init_game(){
	gstate* game_state = malloc(sizeof(gstate));
	
	game_state->test = 0x000000000000ffff;
	game_state->bishops = 0x4200000000000042;
	
	game_state->wpawns = 0x000000000000ff00;
	//printb(game_state->wpawns);
	game_state->wknights = 0x0000000000000024;
	game_state->wbishops = 0x0000000000000042;
	game_state->wrooks = 0x0000000000000081;
	game_state->wqueens = 0x0000000000000010;
	game_state->wking = 0x0000000000000008;
	
	game_state->bpawns = 0x00ff000000000000;
	//printb(game_state->wpawns);
	game_state->bknights = 0x2400000000000000;
	game_state->bbishops = 0x4200000000000000;
	game_state->brooks = 0x8100000000000000;
	game_state->bqueens = 0x1000000000000000;
	game_state->bbking = 0x0800000000000000;
	
	return game_state;
}
	

/*
white bishops: 4200 0000 0000 0000
black bishops: 0000 0000 0000 0042

white rooks: 8100 0000 0000 0000
black rooks: 0000 0000 0000 0081

white knights: 2400 0000 0000 0000
black knights: 0000 0000 0000 0024

white pawns: 00ff 0000 0000 0000
black pawns: 0000 0000 0000 ff00

white queen: 1000 0000 0000 0000
black queen: 0000 0000 0000 0010

white king: 0800 0000 0000 0000
black king: 0000 0000 0000 0800
*/



int main() {
	//bitboard* init_board;
	//init_board = init_state();

	//bitb* init_board;
	//init_board = init_state();
	
	gstate* game_state;
	game_state = init_game();
	
	printf("\npawn union\n");
	printb(game_state->wpawns | game_state->bpawns);
	
	printf("\npawn intersection\n");
	printb(game_state->test & game_state->bishops);
	
	/*printf("\nwhite bishops\n");
	printb(game_state->wbishops);
	
	printf("\nwhite rooks\n");
	printb(game_state->wrooks);
	
	printf("\nwhite knights\n");
	printb(game_state->wknights);
	
	printf("\nwhite king\n");
	printb(game_state->wking);
	
	printf("\nblack pawns\n");
	printb(game_state->bpawns);*/
	
	//printf("main %" PRIx64 "\n", *init_board);
	//printb(*init_board);
	
	return 0;
}
