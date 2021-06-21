#include "iostream"
#include "stdlib.h"
using namespace std;

/*
 * Text-based game for SYP
*/

string name = "";
bool running = 0;
int choice = 1;

void quit() {
	for (;;) {
		std::cout << "there is no escape\n";
	}
}

void win() {
	for (;;) {
		system("echo You Win!");
		system("clear");
		std::cout << "You Win!";
	}
}

void level2() {
	system("clear");
	cout << "level 2 is easy";
	win();
}

void level1() {
	system("clear");
	std::cout << "I'm glad you want to continue\n";
	std::cout << "Well, kid, welcome to the game\n";
	choice = 0;
	system("clear");
	std::cout << "Welcome to level 1\n";
	std::cout << "Continue?\n" << "1. Yes\n" << "2. No\n";
	std::cin >> choice;
	if (choice == 1) {
		system("clear");
		std::cout << "Goblins are attacking the city!\n" << "1. Make your own path\n" << "2. Follow me\n";
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "YOU DIED\n" << "GAME OVER\n";
		} else if (choice == 2) {
			std::cout << "Good choice, " << name << ". You're still alive for now\n";
			level2();
		} else { std::cout << "what?\n"; }
	} else if (choice == 2) {
		quit();
	} else { 
		std::cout << "error\n";
	}
}

void game() {
	if (running == 1) {
		system("clear");
		std::cout << "What is your name? ";
		std::cin >> name;
		std::cout << "Hello, " << name << ". Welcome to my personal hell.\n";
		std::cout << "Press any key and enter to continue\n";
		string i = "";
		std::cin >> i;
		if (i != "") {
		for (;;) {
			system("clear");
			std::cout << "You're talking to a computer right now, and that's pretty sad.\n" << "\n1. Carry on" << "\n2. Give up\n";
			std::cin >> choice;
			if (choice == 1) {
				level1();
				} else if (choice == 2) {
					quit();
				} else {
					std::cout << "what?\n";
				break;
				}
			}
		} else {
			std::cout << "error\n";
		}
	}	
}

int main() {
	running = 1;
	std::cout << "game running...\n";
	game();
}
