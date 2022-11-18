#include <stdio.h>		//C 표준 라이브러리 함수 포함 
#include <windows.h>	//콘솔 창 관련 함수 포함
#include <conio.h>		//kbhit() 함수와 getch() 함수를 쓰기 위해 
#include <string.h>		//문자열 관련 함수 포함, 배열 복사에 쓰이는 memcpy를 쓰기 위해 
void gotoxy(int x, int y);			//커서 이동 함수 
void CursorTrue();					//커서 보이게 하기 
void CursorFalse();					//커서 안 보이게 하기 

//첫 줄에 system("cls")를 포함시켜 편하게 함. 
void Game_start();					//게임 시작 화면 
void Loading();						//로딩 화면  
void Game_main();					//게임 메인 화면
void Game_rule();					//라이프 게임 규칙 화면 
void Game_sample();					//라이프 게임 예시 화면 
void Game_sample_pg1();
void Game_sample_pg2();
void Game_sample_pg3();
void Game_sample_pg4();
void Game_sample_pg5();
void Game_sample_pg6();
void Game_play();					//라이프 게임 실행 화면 
void Game_info();					//라이프 게임 정보 화면 

void Teduri();						//테두리 

void Egg();							//이스터 에그 

#define COL GetStdHandle(STD_OUTPUT_HANDLE)				// 콘솔창의 핸들정보 받기
#define BLACK SetConsoleTextAttribute(COL, 0x0000);		// 검정색
#define DARK_BLUE SetConsoleTextAttribute(COL, 0x0001);	// 파란색
#define GREEN SetConsoleTextAttribute(COL, 0x0002);		// 녹색
#define BLUE_GREEN SetConsoleTextAttribute(COL, 0x0003);// 청녹색
#define BLOOD SetConsoleTextAttribute(COL, 0x0004);		// 검붉은색 
#define PURPLE SetConsoleTextAttribute(COL, 0x0005);	// 보라색
#define GOLD SetConsoleTextAttribute(COL, 0x0006);		// 금색
#define ORIGINAL SetConsoleTextAttribute(COL, 0x0007);	// 밝은 회색 (ORIGINAL CONSOLE COLOR)
#define GRAY SetConsoleTextAttribute(COL, 0x0008);		// 회색
#define BLUE SetConsoleTextAttribute(COL, 0x0009);		// 파란색
#define HIGH_GREEN SetConsoleTextAttribute(COL, 0x000a);// 연두색
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);	// 하늘색
#define RED SetConsoleTextAttribute(COL, 0x000c);		// 빨간색
#define PLUM SetConsoleTextAttribute(COL, 0x000d);		// 자주색
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);	// 노란색
#define WHITE SetConsoleTextAttribute(COL, 0x000f);		// 흰색

#define SQUARE printf("■");
#define SPACE printf("  ");

#define CIRCLE printf("●"); 

int pan[36][36] = {										//Game_play()에 쓰이는 판 전역변수로 설정 
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					};									//tap 사용해서 보기 좋게 함.  -1: 선택되지 않음, 1: 선택됨. 

int pan_next[36][36] = {								//Game_play()에서 다음으로 바꿔줄 판 
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					};									//tap 사용해서 보기 좋게 함.  -1: 선택되지 않음, 1: 선택됨. 

int x=0, y=0;											//현재 위치가 초기화되지 않기 위해서 전역변수로 설정. 
int velocity=50;										//속도 초기화되지 않기 위해서 전역변수로 설정. 

int main (void)
{
	system("mode con cols=80 lines=40");	//cols: 가로, lines: 세로, 가로 2칸의 크기는 세로 1칸의 크기와 동일
	SetConsoleTitle("Game of Life");		//console의 title 설정 
	CursorFalse();							//커서 숨김 
	Game_start();	//게임 시작 화면 불러오기 
	return 0;		//main 함수 종료
}

void gotoxy(int x, int y)//
{
    COORD CursorPosition = {x, y};
    SetConsoleCursorPosition(COL, CursorPosition);
}

void CursorTrue()//
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };//CONSOLE_CURSOR_INFO 구조체 선언 
    cursorInfo.dwSize = 1;					//커서 두께 설정 (1~100) 
    cursorInfo.bVisible = TRUE;				//커서를 보임  
    SetConsoleCursorInfo(COL, &cursorInfo);
}

void CursorFalse()//
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };//CONSOLE_CURSOR_INFO 구조체 선언 
    cursorInfo.dwSize = 1;					//커서 두께 설정 (1~100) 
    cursorInfo.bVisible = FALSE;			//커서를 숨김 
    SetConsoleCursorInfo(COL, &cursorInfo);
}

void Game_start()//
{
	system("cls");
	int i;
	gotoxy(0, 0);
	DARK_BLUE
	for(i=0;i<40;i++) SQUARE
	
	gotoxy(0, 1);
	for(i=0;i<18;i++) SQUARE
	RED
	SQUARE
	DARK_BLUE
	SQUARE
	SQUARE
	RED
	SQUARE
	DARK_BLUE
	for(i=0;i<18;i++) SQUARE
	
	gotoxy(0, 2);
	for(i=0;i<17;i++) SQUARE
	RED
	for(i=0;i<6;i++) SQUARE
	DARK_BLUE
	for(i=0;i<17;i++) SQUARE
	
	gotoxy(0, 3);
	BLUE
	for(i=0;i<18;i++) SQUARE
	RED
	for(i=0;i<4;i++) SQUARE
	BLUE
	for(i=0;i<18;i++) SQUARE
	
	gotoxy(0, 4);
	for(i=0;i<19;i++) SQUARE
	RED
	SQUARE
	SQUARE
	BLUE
	for(i=0;i<19;i++) SQUARE
	
	gotoxy(0, 5);
	for(i=0;i<40;i++) SQUARE
	
	gotoxy(0, 6);
	BLUE_GREEN
	for(i=0;i<8;i++) SQUARE
	for(i=0;i<4;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<3;i++) SPACE
	for(i=0;i<4;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<7;i++) SQUARE
	
	gotoxy(0, 7);
	for(i=0;i<7;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<11;i++) SQUARE
	
	gotoxy(0, 8);
	for(i=0;i<7;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<2;i++) SPACE
	for(i=0;i<2;i++) SQUARE 
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<7;i++) SQUARE
	
	gotoxy(0, 9);
	SKY_BLUE
	for(i=0;i<7;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<11;i++) SQUARE
	
	gotoxy(0, 10);
	for(i=0;i<8;i++) SQUARE
	for(i=0;i<3;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<7;i++) SQUARE
	
	gotoxy(0, 11);
	for(i=0;i<40;i++) SQUARE
	
	gotoxy(0, 12);
	for(i=0;i<40;i++) SQUARE
	
	gotoxy(0, 13);
	for(i=0;i<15;i++) SQUARE
	for(i=0;i<3;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<14;i++) SQUARE
	
	gotoxy(0, 14);
	BLUE_GREEN
	for(i=0;i<2;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	BLUE_GREEN
	for(i=0;i<9;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<18;i++) SQUARE
	
	gotoxy(0, 15);
	SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE_GREEN
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<14;i++) SQUARE
	
	gotoxy(0, 16);
	SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE_GREEN
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<18;i++) SQUARE
	
	gotoxy(0, 17);
	BLUE
	SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	BLUE
	for(i=0;i<6;i++) SQUARE
	for(i=0;i<3;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<13;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	BLUE
	for(i=0;i<2;i++) SQUARE
	
	gotoxy(0, 18);
	for(i=0;i<2;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	BLUE
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	BLUE
	for(i=0;i<26;i++) SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE
	SQUARE
	
	gotoxy(0, 19);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	BLUE
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	BLUE
	for(i=0;i<27;i++) SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE
	SQUARE
	
	gotoxy(0, 20);
	DARK_BLUE
	for(i=0;i<3;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	DARK_BLUE
	SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	DARK_BLUE
	SQUARE
	
	gotoxy(0, 21);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	DARK_BLUE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<4;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	DARK_BLUE
	for(i=0;i<2;i++) SQUARE
	
	gotoxy(0, 22);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	DARK_BLUE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<4;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	DARK_BLUE
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 23);
	GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<4;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	SPACE
	for(i=0;i<4;i++) SQUARE
	GRAY
	for(i=0;i<4;i++) SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 24);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	SQUARE
	GRAY
	SQUARE
	GREEN
	SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 25);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<29;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 26);
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<32;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 27);
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<32;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 28);
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<31;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 29);
	HIGH_GREEN
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<29;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 30);
	GRAY
	for(i=0;i<2;i++) SQUARE
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<28;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 31);
	for(i=0;i<5;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<28;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 32);
	for(i=0;i<5;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<34;i++) SQUARE
	
	gotoxy(0, 33);
	GOLD
	for(i=0;i<8;i++) SQUARE
	for(i=0;i<24;i++) SPACE
	for(i=0;i<8;i++) SQUARE
	
	gotoxy(0, 34);
	for(i=0;i<6;i++) SQUARE
	for(i=0;i<28;i++) SPACE
	for(i=0;i<6;i++) SQUARE
	
	gotoxy(0, 35);
	for(i=0;i<5;i++) SQUARE
	for(i=0;i<30;i++) SPACE
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 36);
	for(i=0;i<5;i++) SQUARE
	for(i=0;i<30;i++) SPACE
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 37);
	for(i=0;i<4;i++) SQUARE
	for(i=0;i<32;i++) SPACE
	for(i=0;i<4;i++) SQUARE
	
	gotoxy(0, 38);
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<34;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 39);
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<34;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	
	WHITE
	for(i=0;;i++)	//i를 1씩 증가시키면서 계속 반복	//Press enter to start 반짝이는 애니메이션 효과 
	{
        if(kbhit() and (GetAsyncKeyState(VK_RETURN))) break;	//키입력이 있으면 무한루프 종료	(입력이 있다면 1(True), 입력이 없다면 0(False) 값 반환) //다른 키를 입력하면 깜빡이는 효과가 없어져 VK_RETURN(Enter) 키 입력이 되어야 무한루프 종료로 수정 
        if(i%80==0)			//i가 80으로 나누어 떨어질때 글을 표시 
		{
			gotoxy(29, 36);
			printf("Press enter to start");
		}
        else if(i%80==40)	//i의 나머지가 40일 때 글을 지움
		{
			gotoxy(29, 36);
			printf("                    ");
		}
        Sleep(10); //시간 지연(10ms)
    }
	
	while(1)
		if((GetAsyncKeyState(VK_RETURN)))
		{
			Loading();	//지금까지 enter키가 눌린 적이 있다면 로딩 창 불러옴
			break;		//더이상 enter키 입력을 받지 않으므로 while문 종료 
		}
	Game_main();	//라이프 게임 메인 화면 불러오기 
}

void Loading()//
{
	int percent=0, i;
	system("cls");
	gotoxy(35, 17);
	printf("Loading");
	for(i=0;i<5;i++)
	{
		Sleep(200);
		gotoxy(30+i, 21);
		printf("|");
		percent+=6;
		gotoxy(46, 21);
		printf("%d%%", percent);
	}

	gotoxy(42, 17);
	printf(".");
	for(i=0;i<5;i++)
	{
		Sleep(200);
		gotoxy(35+i, 21);
		printf("|");
		if(i==0) percent+=7;
		else percent+=6;
		gotoxy(46, 21);
		printf("%d%%", percent);
	}

	gotoxy(43, 17);
	printf(".");
	Sleep(1000);
	
	gotoxy(44, 17);
	printf(".");
	Sleep(500);
	for(i=0;i<5;i++)
	{
		Sleep(80);
		gotoxy(40+i, 21);
		printf("|");
		if(i==0) percent+=7;
		else percent+=8;
		gotoxy(46, 21);
		printf("%d%%", percent);
	}
	Sleep(100);
}

void Game_main()
{
	//초기 화면 불러오기 
	system("cls");
	
	WHITE
	gotoxy(34, 6);
	printf("Game of Life"); 
	
	RED
	gotoxy(31, 11);
	printf("┌───────────────┐ ");
	gotoxy(31, 12);
	printf("│               │ ");
	gotoxy(31, 13);
	printf("│      Rule     │ ");
	gotoxy(31, 14);
	printf("│               │ ");
	gotoxy(31, 15);
	printf("└───────────────┘ ");
	
	WHITE
	gotoxy(31, 17);
	printf("┌───────────────┐ ");
	gotoxy(31, 18);
	printf("│               │ ");
	gotoxy(31, 19);
	printf("│     Sample    │ ");
	gotoxy(31, 20);
	printf("│               │ ");
	gotoxy(31, 21);
	printf("└───────────────┘ ");
	
	gotoxy(31, 23);
	printf("┌───────────────┐ ");
	gotoxy(31, 24);
	printf("│               │ ");
	gotoxy(31, 25);
	printf("│      Play     │ ");
	gotoxy(31, 26);
	printf("│               │ ");
	gotoxy(31, 27);
	printf("└───────────────┘ ");
	
	gotoxy(31, 29);
	printf("┌───────────────┐ ");
	gotoxy(31, 30);
	printf("│               │ ");
	gotoxy(31, 31);
	printf("│      Info     │ ");
	gotoxy(31, 32);
	printf("│               │ ");
	gotoxy(31, 33);
	printf("└───────────────┘ ");
	
	gotoxy(31, 35);
	printf("key: ↑, ↓, enter");
	gotoxy(35, 36);
	printf("restart: r");
	
	int input = getch(), i, n=1;	//현재 버퍼에 저장되어 있는 enter키 혹은 다른 키를 받아 없애주자. 버퍼를 비우는 과정. 
	while(1)	//무한 루프 : 계속 입력 받음 
	{
		input = getch();	//입력 받는 함수, ASCII코드로 입력 받음 (input이 int형이기 때문) 
		if(input == 224)	//방향키는 2byte로, 앞 글자의 ASCII코드는 224임. 앞 글자가 224라면 
							//VK_UP		(↑)	: 224 72
							//VK_LEFT	(←)	: 224 75
							//VK_RIGHT	(→)	: 224 77
							//VK_DOWN	(↓)	: 224 80
		{
			input = getch();	//뒤의 숫자 가져오기
			if(input == 72)		//위 방향키 입력 시
			{
				n-=1;
				if(n==0) n=4;
			}
			else if(input == 80)//아래 방향키 입력 시 
			{
				n+=1;
				if(n==5) n=1;
			}
			
			if(n==1)			//Rule을 빨간색으로 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life"); 
				
				RED
				gotoxy(31, 11);
				printf("┌───────────────┐ ");
				gotoxy(31, 12);
				printf("│               │ ");
				gotoxy(31, 13);
				printf("│      Rule     │ ");
				gotoxy(31, 14);
				printf("│               │ ");
				gotoxy(31, 15);
				printf("└───────────────┘ ");
				
				WHITE
				gotoxy(31, 17);
				printf("┌───────────────┐ ");
				gotoxy(31, 18);
				printf("│               │ ");
				gotoxy(31, 19);
				printf("│     Sample    │ ");
				gotoxy(31, 20);
				printf("│               │ ");
				gotoxy(31, 21);
				printf("└───────────────┘ ");
	
				gotoxy(31, 23);
				printf("┌───────────────┐ ");
				gotoxy(31, 24);
				printf("│               │ ");
				gotoxy(31, 25);
				printf("│      Play     │ ");
				gotoxy(31, 26);
				printf("│               │ ");
				gotoxy(31, 27);
				printf("└───────────────┘ ");
				
				gotoxy(31, 29);
				printf("┌───────────────┐ ");
				gotoxy(31, 30);
				printf("│               │ ");
				gotoxy(31, 31);
				printf("│      Info     │ ");
				gotoxy(31, 32);
				printf("│               │ ");
				gotoxy(31, 33);
				printf("└───────────────┘ ");
			}
			else if (n==2)			//Sample을 빨간색으로 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life"); 
				
				WHITE
				gotoxy(31, 11);
				printf("┌───────────────┐ ");
				gotoxy(31, 12);
				printf("│               │ ");
				gotoxy(31, 13);
				printf("│      Rule     │ ");
				gotoxy(31, 14);
				printf("│               │ ");
				gotoxy(31, 15);
				printf("└───────────────┘ ");
				
				RED
				gotoxy(31, 17);
				printf("┌───────────────┐ ");
				gotoxy(31, 18);
				printf("│               │ ");
				gotoxy(31, 19);
				printf("│     Sample    │ ");
				gotoxy(31, 20);
				printf("│               │ ");
				gotoxy(31, 21);
				printf("└───────────────┘ ");
				
				WHITE
				gotoxy(31, 23);
				printf("┌───────────────┐ ");
				gotoxy(31, 24);
				printf("│               │ ");
				gotoxy(31, 25);
				printf("│      Play     │ ");
				gotoxy(31, 26);
				printf("│               │ ");
				gotoxy(31, 27);
				printf("└───────────────┘ ");
				
				gotoxy(31, 29);
				printf("┌───────────────┐ ");
				gotoxy(31, 30);
				printf("│               │ ");
				gotoxy(31, 31);
				printf("│      Info     │ ");
				gotoxy(31, 32);
				printf("│               │ ");
				gotoxy(31, 33);
				printf("└───────────────┘ ");
			}
			else if (n==3)			//Play를 빨간색으로 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life"); 
				
				WHITE
				gotoxy(31, 11);
				printf("┌───────────────┐ ");
				gotoxy(31, 12);
				printf("│               │ ");
				gotoxy(31, 13);
				printf("│      Rule     │ ");
				gotoxy(31, 14);
				printf("│               │ ");
				gotoxy(31, 15);
				printf("└───────────────┘ ");
				
				gotoxy(31, 17);
				printf("┌───────────────┐ ");
				gotoxy(31, 18);
				printf("│               │ ");
				gotoxy(31, 19);
				printf("│     Sample    │ ");
				gotoxy(31, 20);
				printf("│               │ ");
				gotoxy(31, 21);
				printf("└───────────────┘ ");
				
				RED
				gotoxy(31, 23);
				printf("┌───────────────┐ ");
				gotoxy(31, 24);
				printf("│               │ ");
				gotoxy(31, 25);
				printf("│      Play     │ ");
				gotoxy(31, 26);
				printf("│               │ ");
				gotoxy(31, 27);
				printf("└───────────────┘ ");
				
				WHITE
				gotoxy(31, 29);
				printf("┌───────────────┐ ");
				gotoxy(31, 30);
				printf("│               │ ");
				gotoxy(31, 31);
				printf("│      Info     │ ");
				gotoxy(31, 32);
				printf("│               │ ");
				gotoxy(31, 33);
				printf("└───────────────┘ ");
			}
			
			else					//Info를 빨간색으로 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life");
				
				WHITE
				gotoxy(31, 11);
				printf("┌───────────────┐ ");
				gotoxy(31, 12);
				printf("│               │ ");
				gotoxy(31, 13);
				printf("│      Rule     │ ");
				gotoxy(31, 14);
				printf("│               │ ");
				gotoxy(31, 15);
				printf("└───────────────┘ ");
				
				gotoxy(31, 17);
				printf("┌───────────────┐ ");
				gotoxy(31, 18);
				printf("│               │ ");
				gotoxy(31, 19);
				printf("│     Sample    │ ");
				gotoxy(31, 20);
				printf("│               │ ");
				gotoxy(31, 21);
				printf("└───────────────┘ ");
	
				gotoxy(31, 23);
				printf("┌───────────────┐ ");
				gotoxy(31, 24);
				printf("│               │ ");
				gotoxy(31, 25);
				printf("│      Play     │ ");
				gotoxy(31, 26);
				printf("│               │ ");
				gotoxy(31, 27);
				printf("└───────────────┘ ");
				
				RED
				gotoxy(31, 29);
				printf("┌───────────────┐ ");
				gotoxy(31, 30);
				printf("│               │ ");
				gotoxy(31, 31);
				printf("│      Info     │ ");
				gotoxy(31, 32);
				printf("│               │ ");
				gotoxy(31, 33);
				printf("└───────────────┘ ");
			}
		}
		
		else if(input == 13)//VK_RETURN (Enter) : 13
		{
			//현재 n값에 따라(현재 붉은색인 버튼에 따라) 맞는 함수 호출 
			WHITE 
			if(n==1)
			{
				Game_rule();
				break;
			}
			else if(n==2)
			{
				Game_sample();
				break;
			}
			else if(n==3)
			{
				Game_play();
				break;
			}
			else
			{
				Game_info(); 
				break;
			}
		}
		
		else if(input == 82 or input == 114)//R: 82, r: 114
		{
			Game_start();
			break;
		}
	}
}

void Game_rule()
{
	Teduri();
	gotoxy(28, 6);
	printf("How to play Life of Game");
	
	gotoxy(13, 9);
	printf("Q: 라이프 게임이 무엇인가요?");
	gotoxy(13, 10);
	printf("A: 영국의 수학자 존 호턴 콘웨이가 고안해낸 세포 자동자");
	gotoxy(16, 11);
	printf("의 일종으로, 가장 널리 알려진 세포 자동자 가운데 하");
	gotoxy(16, 12);
	printf("나입니다.");
	
	gotoxy(13, 14);
	printf("Q: 어떻게 플레이하나요?");
	gotoxy(13, 15);
	printf("A: 현재 세대의 세포 상태를 바탕으로 아래 두 규칙에 의해");
	gotoxy(16, 16);
	printf("다음 세대의 세포 상태가 결정됩니다.");
	
	gotoxy(14, 18);
	printf("- 죽은 세포의 이웃 중 정확히 세 개가 살아 있으면 그 세");
	gotoxy(14, 19);
	printf("포는 살아난다('태어난다').");
	
	gotoxy(14, 20);
	printf("- 살아 있는 세포의 이웃 중에 두 개나 세 개가 살아 있으");
	gotoxy(14, 21);
	printf("면, 그 세포는 계속 살아 있는 상태를 유지하고, 이외에는");
	gotoxy(14, 22);
	printf("'외로워서', 또는 '숨이 막혀서' 죽어버린다.");
	
	gotoxy(13, 25);
	printf("Q. 어떻게 하면 이 게임을 즐길 수 있나요?");
	gotoxy(13, 26);
	printf("A. 자신만의 라이프 게임 도형을 만들어보세요. 재밌어요.");
	
	gotoxy(13, 29);
	printf("Q. 이스터에그가 존재하나요?");
	gotoxy(13, 30);
	printf("A. 게임을 많이 플레이하시면 충분히 찾으실 수 있습니다!");
	gotoxy(16, 31);
	printf("화이팅하세요!");
	
	gotoxy(60, 33);
	printf("Quit: q");
	
	char input;
	while(1)
	{
		input = getch();
		if(input==81 or input == 113)	//Q: 81, q: 113
		{
			Game_main();
			break;
		}
	}
}

void Game_sample()
{
	int input, now_pg=1, change=0;
	Game_sample_pg1();
	while(1)
	{
		input = getch();
	 	if(input == 81 or input == 113)	//Q: 81, q: 113
	 	{
	 		Game_main();
		}
		else if(input == 224)
		{
			input = getch();
			if(input == 75)		//왼쪽 방향키 
			{
				if(now_pg>1) 
				{
					now_pg-=1;
					change=1;
				}
			}
			else if(input == 77)//오른쪽 방향키 
			{
				if(now_pg<6) 
				{
					now_pg+=1;
					change=1;
				}
			}
			
			if(change==1)
			{
				if(now_pg==1)
				{
					Game_sample_pg1();
				}
				else if(now_pg==2)
				{
					Game_sample_pg2();
				}
				else if(now_pg==3)
				{
					Game_sample_pg3();
				}
				else if(now_pg==4)
				{
					Game_sample_pg4();
				}
				else if(now_pg==5)
				{
					Game_sample_pg5();
				}
				else if(now_pg==6)
				{
					Game_sample_pg6();
				}
				change=0;
			}
		}
	}
}

void Game_sample_pg1()
{
	Teduri();
	gotoxy(66, 6);
	printf("→");
	gotoxy(31, 6);
	printf("정물 (Still Lifes)");
	gotoxy(13, 9);
	printf("- 블록");
	gotoxy(17, 11);
	SQUARE
	SQUARE
	gotoxy(17, 12);
	SQUARE
	SQUARE
	gotoxy(13, 14);
	printf("- 벌집");
	gotoxy(17, 16);
	SPACE
	SQUARE
	SQUARE
	SPACE
	gotoxy(17, 17);
	SQUARE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 18);
	SPACE
	SQUARE
	SQUARE
	SPACE
	gotoxy(13, 20);
	printf("- 빵덩이");
	gotoxy(17, 22);
	SPACE
	SQUARE
	SQUARE
	SPACE
	gotoxy(17, 23);
	SQUARE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 24);
	SPACE
	SQUARE
	SPACE
	SQUARE
	gotoxy(17, 25);
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(13, 27);
	printf("- 보트");
	gotoxy(17, 29);
	SQUARE
	SQUARE
	SPACE
	gotoxy(17, 30);
	SQUARE
	SPACE
	SQUARE
	gotoxy(17, 31);
	SPACE
	SQUARE
	SPACE
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.1 -");
}

void Game_sample_pg2()
{
	Teduri();
	gotoxy(12, 6);
	printf("←");
	gotoxy(66, 6);
	printf("→");
	gotoxy(30, 6);
	printf("진동자 (Oscillators)");
	gotoxy(13, 9);
	printf("- 깜빡이");
	gotoxy(17, 11);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 12);
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 13);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(13, 15);
	printf("- 두꺼비");
	gotoxy(17, 17);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 18);
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 19);
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 20);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	gotoxy(13, 22);
	printf("- 등대");
	gotoxy(17, 24);
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 25);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 26);
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	gotoxy(17, 27);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.2 -");
}

void Game_sample_pg3()
{
	Teduri();
	gotoxy(12, 6);
	printf("←");
	gotoxy(66, 6);
	printf("→");
	gotoxy(30, 6);
	printf("진동자 (Oscillators)");
	gotoxy(13, 9);
	printf("- 펄사");
	gotoxy(17, 11);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 13);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 14);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 15);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 16);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 18);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 19);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 20);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 21);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 23);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.3 -");
}

void Game_sample_pg4()
{
	Teduri();
	gotoxy(12, 6);
	printf("←");
	gotoxy(66, 6);
	printf("→");
	gotoxy(30, 6);
	printf("우주선  (Spaceships)");
	gotoxy(13, 9);
	printf("- 글라이더");
	gotoxy(17, 11);
	SQUARE
	SPACE
	SQUARE
	gotoxy(17, 12);
	SPACE
	SQUARE
	SQUARE
	gotoxy(17, 13);
	SPACE
	SQUARE
	SPACE
	gotoxy(13, 15);
	printf("- 경량 우주선 (LWSS)");
	gotoxy(17, 17);
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	gotoxy(17, 18);
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 19);
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 20);
	SQUARE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.4 -");
}

void Game_sample_pg5()
{
	Teduri();
	gotoxy(12, 6);
	printf("←");
	gotoxy(66, 6);
	printf("→");
	gotoxy(31, 6);
	printf("장수  (Methuselah)");
	gotoxy(13, 9);
	printf("- R-펜토미노");
	gotoxy(17, 11);
	SPACE
	SQUARE
	SQUARE
	gotoxy(17, 12);
	SQUARE
	SQUARE
	SPACE
	gotoxy(17, 13);
	SPACE
	SQUARE
	SPACE
	gotoxy(13, 15);
	printf("- 다이하드");
	gotoxy(17, 17);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 18);
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 19);
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	gotoxy(13, 21);
	printf("- 도토리");
	gotoxy(17, 23);
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 24);
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 25);
	SQUARE
	SQUARE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.5 -");
}

void Game_sample_pg6()
{
	Teduri();
	gotoxy(12, 6);
	printf("←");
	gotoxy(33, 6);
	printf("무한 성장 패턴"); 
	gotoxy(13, 9);
	printf("- 최소 세포로 무한 성장 (10)");
	gotoxy(17, 11);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 12);
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SQUARE
	gotoxy(17, 13);
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 14);
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 15);
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 16);
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	gotoxy(13, 18);
	printf("- 최소 면적으로 무한 성장 (2×12)");
	gotoxy(17, 20);
	SQUARE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SQUARE
	gotoxy(17, 21);
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SQUARE
	 
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.6 -");
}

void Game_play()
{
	system("cls");
	
	int i, j, input, change_x, change_y, change_cnt, changexy_x, changexy_y; 
	
	int generation=0;
	
	gotoxy(31, 0);
	printf("[[ Game of Life ]]");
	
	for(i=0;i<36;i++)
	{
		gotoxy(4, 2+i);
			
		for(j=0;j<36;j++)
		{ 
			if(i==x and j==y)
			{
				if(pan[i][j]==-1)
				{
					WHITE
					CIRCLE
				}
				else
				{
					RED
					CIRCLE
				}
			}
			else
			{
				if(pan[i][j]==-1)
				{
					WHITE
					SQUARE
				}
				else
				{
					RED
					SQUARE
				}
			}
		}
	}
	
	gotoxy(2, 38);
	printf("Move: ↑, ↓, ←, →, Select: space, Start: enter, Stop: Backspace, Reset: r");
	gotoxy(71, 0);
	printf("Quit: q");
	gotoxy(50, 1);
	printf("Use +, - to control Velocity");
	gotoxy(2, 0);
	printf("                             ");
	gotoxy(2, 0);
	printf("Generation: %d", generation);
	gotoxy(2, 1);
	printf("                                      ");
	gotoxy(2, 1);
	printf("Velocity  : %d", velocity);
	while(1)
	{
		input = getch();
		if(input == 82 or input == 114)			//R: 82, r: 114
		{
			for(i=0;i<36;i++)	//판 초기화 
			{
				for(j=0;j<36;j++)
				{
					pan[i][j]=-1;
				}
			}
			//현재 위치 초기화 
			x=0;
			y=0;
			//세대 초기화 
			generation=0;
		}
		else if(input == 45)					//-: 45
		{
			if(velocity>1)
			{
				velocity -=1;
			}
		}
		else if(input == 43)					//+: 43
		{
			if(velocity<100)
			{
				velocity +=1;
			}
		}
		else if(input == 81 or input == 113)	//Q: 81, q: 113
		{
			Game_main();		//메인 화면 불러오기
			break; 
		}
		else if(input == 224)
		{
			input = getch();
			if(input == 72)
			{
				if(x!=0) x-=1;
			}
			else if(input == 75)
			{
				if(y!=0) y-=1;
			}
			else if(input == 77)
			{
				if(y!=35) y+=1;
			}
			else if(input == 80)
			{
				if(x!=35) x+=1;
			}
		}
		else if(input == 32)			//VK_SP : 스페이스 바 
		{
			pan[x][y] *= -1;
		}
		
			
		for(i=0;i<36;i++)
		{
			gotoxy(4, 2+i);
			
			for(j=0;j<36;j++)
			{
				if(i==x and j==y)
				{
					if(pan[i][j]==-1)
					{
						WHITE
						CIRCLE
					}
					else
					{
						RED
						CIRCLE
					}
				}
				else
				{
					if(pan[i][j]==-1)
					{
						WHITE
						SQUARE
					}
					else
					{
						RED
						SQUARE
					}
				}
			}
		}
		gotoxy(2, 0);
		printf("                             ");
		gotoxy(2, 0);
		printf("Generation: %d", generation);
		gotoxy(2, 1);
		printf("                                      ");
		gotoxy(2, 1);
		printf("Velocity  : %d", velocity);
		
		int playing_input;
		
		if(input == 13)	//VK_CR: 엔터 키 
		{
			while(1)
			{
				if(kbhit())
				{
					playing_input = getch();
					{
						if(playing_input == 8)			//VK_BS: 백스페이스 
						{
							break;
						}
						else if(playing_input == 81 or playing_input == 113)	//Q: 81, q: 113
						{
							Game_main();		//메인 화면 불러오기
							break; 
						}
						else if(playing_input == 82 or playing_input == 114)	//R: 82, r: 114
						{
							for(i=0;i<36;i++)	//판 초기화 
							{
								for(j=0;j<36;j++)
								{
									pan[i][j]=-1;
								}
							}
						//현재 위치 초기화 
						x=0;
						y=0;
						Game_play();
						break;
						}
						else if(playing_input == 224)	//방향키 
						{
							input = getch();
							if(input == 72)
							{
								if(x!=0) x-=1;
							}
							else if(input == 75)
							{
								if(y!=0) y-=1;
							}
							else if(input == 77)
							{
								if(y!=35) y+=1;
							}
							else if(input == 80)
							{
								if(x!=35) x+=1;
							}
						}
						else if(playing_input == 43)	//+: ASCII 43
						{
							if(velocity<100)
							{
								velocity +=1;
							}
						}
						else if(playing_input == 45)	//-: ASCII 45
						{
							if(velocity>1)
							{
								velocity -=1;
							}
						}
					}
				}
				gotoxy(2, 1);
				printf("                                      ");
				gotoxy(2, 1);
				printf("Velocity  : %d", velocity);
				for(change_x=0;change_x<36;change_x++)
				{
					for(change_y=0;change_y<36;change_y++)
					{
						change_cnt = 0;
						for(changexy_x=change_x-1;changexy_x<=change_x+1;changexy_x++)
						{
							for(changexy_y=change_y-1;changexy_y<=change_y+1;changexy_y++)
							{
								if(changexy_x != change_x || changexy_y != change_y)
								{
									if(changexy_x!=-1 and changexy_x!=36)
									{
										if(changexy_y!=-1 and changexy_y!=36)
										{
											if(pan[changexy_x][changexy_y] == 1)
											{
												change_cnt += 1;
											}
										}
									}
								}
							}
						}
						if(pan[change_x][change_y] == -1 && change_cnt == 3)
						{
							pan_next[change_x][change_y] = 1;
						}
						else if(pan[change_x][change_y] == 1 && (change_cnt == 2 || change_cnt == 3))
						{
							pan_next[change_x][change_y] = 1;
						}
						else
						{
							pan_next[change_x][change_y] = -1;
						}
					}
				}
				memcpy(pan, pan_next, sizeof(pan_next));
				
				for(i=0;i<36;i++)
				{
					gotoxy(4, 2+i);
					
					for(j=0;j<36;j++)
					{
						if(i==x and j==y)
						{
							if(pan[i][j]==-1)
							{
								WHITE
								CIRCLE
							}
							else
							{
								RED
								CIRCLE
							}
						}
						else
						{
							if(pan[i][j]==-1)
							{
								WHITE
								SQUARE
							}
							else
							{
								RED
								SQUARE
							}
						}
					}
				}
				generation += 1;
				gotoxy(2, 0);
				printf("                             ");
				gotoxy(2, 0);
				printf("Generation: %d", generation);
				
				Sleep(5*(101-velocity));
			}
		}
	}
}

void Game_info()
{
	Teduri();
	
	gotoxy(38, 6);
	printf("Info");
	
	gotoxy(13, 9);
	printf("Name: Life of Game");
	
	gotoxy(13, 11);
	printf("Zero-player game determined by initial state");
	
	gotoxy(13, 14);
	printf("Made by 1203 김명준, 1209 박민재");
	
	gotoxy(13, 16);
	printf("October 19th, 2022 ~ November 11st, 2022");
	
	gotoxy(13, 19);
	printf("강원과학고등학교 1학년 2학기 정보 수행평가");
	
	gotoxy(13, 21);
	printf("무단 복제 및 배포 금지");
	
	gotoxy(13, 24);
	printf("Username: papa2538");
	
	gotoxy(13, 26);
	printf("Github: https://github.com/papa2538");
	
	gotoxy(13, 28);
	printf("Solved.ac: https://solved.ac/profile/papa2538");
	
	gotoxy(13, 30);
	printf("Codeforces: https://codeforces.com/profile/papa2538");
	
	gotoxy(13, 32);
	printf("Atcoder: https://atcoder.jp/users/papa2538");
	
	gotoxy(60, 33);
	printf("Quit: q");
	
	int input;
	while(1)
	{
		input = getch();
		if(input == 81 or input == 113)	//Q: 81, q: 113
		{
			Game_main();
		}
		else if(input == 224)
		{
			input = getch();
			if(input == 72)
			{
				Egg();
			}
		}
	}
}

void Teduri()
{
	int i, j;
	system("cls");
	gotoxy(10, 5);
	printf("┌");
	for(i=0;i<57;i++) printf("─");
	printf("┐");
	for(i=6;i<34;i++)
	{
		gotoxy(10, i);
		printf("│");
		for(j=0;j<57;j++) printf(" ");
		printf("│");
	}
	gotoxy(10, 34);
	printf("└");
	for(i=0;i<57;i++) printf("─");
	printf("┘");
}

void Egg()
{
	system("cls");
	gotoxy(4, 29);	//1203 김명준 생일 
	printf("Egg");
	gotoxy(11, 14);	//1209 박민재 생일 
	printf("Egg");
	Sleep(1000);
	Game_info();
}
