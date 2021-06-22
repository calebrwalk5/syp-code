#include "iostream"
#include "stdlib.h"
using namespace std;

// Text-based game for SYP

string name = "";
bool running = 0;
int choice = 1;

void lose() {
	for (;;) {
		system("echo you lose");
	}
}

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

void level5() {
	system("clear");
	std::cout << "sqrt(onion)\n";
	choice = 0;
	std::cout << "1. Onion\n" << "2. Obama Prism\n" << "3. Shallots\n" << "4. Answer\n";
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "correct!\n";
		win();
	} else if (choice == 2) {
		system("clear");
		lose();
	} else if (choice == 3) {
		system("clear");
		lose();
	} else if (choice == 4) {
		system("clear");
		lose();
	} else {
		lose();
	}
}

void level4() {
	system("clear");
	std::cout << ".sdrawkcab noitseuq siht rewsnA\n";
	choice = 0;
	std::cout << "1. .K.O\n" << "2. What?\n" << "3. Three\n" << "4. Tennis elbow\n";
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "correct!\n";
		level5();
	} else if (choice == 2) {
		system("clear");
		lose();
	} else if (choice == 3) {
		system("clear");
		lose();
	} else if (choice == 4) {
		system("clear");
		lose();
	} else {
		lose();
	}
}

void level3() {
	std::cout << "Can a match box?\n";
	choice = 0;
	std::cout << "1. Yes\n" << "2. No\n" << "3. No, but a tin can\n" << "4. Mike Tyson\n";
	std::cin >> choice;
	if (choice == 1) {
		system("clear");
		lose();
	} else if (choice == 2) {
		system("clear");
		lose();
	} else if (choice == 3) {
		std::cout << "correct!\n";
		level4();
	} else if (choice == 4) {
		system("clear");
		lose();
	} else {
		lose();
	}
}

void level2() {
	system("clear");
	std::cout << "How many holes in a polo?\n";
	choice = 0;
	std::cout << "1. One\n" << "2. Two\n" << "3. Three\n" << "4. Four\n";
	std::cin >> choice;
	if (choice == 1) {
		system("clear");
		lose();
	} else if (choice == 2) {
		system("clear");
		lose();
	} else if (choice == 3) {
		system("clear");
		lose();
	} else if (choice == 4) {
		std::cout << "correct!\n";
		level3();
	} else {
		lose();
	}
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
			lose();
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

int main() {
	running = 1;
	std::cout << "game running...\n";
	game();
}
