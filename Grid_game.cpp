#include <iostream>                                                                                                          
using namespace std;                                                                                                        
const int gridSize = 5;                                                                                                       
int main() {                                                                                                                           
    char playerState = 'O';
    int playerX = 0;
    int playerY = 0;
    int choice;
    do {
        cout << "   ";
        for (int i = 0; i < gridSize; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < gridSize; i++) {
            cout << i << "  ";
            for (int j = 0; j < gridSize; j++) {
                if (i == playerY && j == playerX) {
                    cout << playerState << " ";
                } else {
                    cout << "- ";
                }
            }
            cout << endl;
        }
        cout << "Menu:" << endl;
        cout << "1. Place the player" << endl;
        cout << "2. Move the player" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter the X coordinate: ";
            cin >> playerX;
            cout << "Enter the Y coordinate: ";
            cin >> playerY;
            cout << "Player placed successfully!" << endl;
        }
        else if (choice == 2) {
            cout << "Enter the direction to move (1: Left, 2: Right, 3: Up, 4: Down): ";
            int direction;
            cin >> direction;
            switch (direction) {
                case 1:
                    if (playerX > 0) {
                        playerX--;
                        cout << "Player moved left." << endl;
                    } else {
                        cout << "Invalid move! Cannot move left." << endl;
                    }
                    break;
                case 2:
                    if (playerX < gridSize - 1) {
                        playerX++;
                        cout << "Player moved right." << endl;
                    } else {
                        cout << "Invalid move! Cannot move right." << endl;
                    }
                    break;
                case 3:
                    if (playerY > 0) {
                        playerY--;
                        cout << "Player moved up." << endl;
                    } else {
                        cout << "Invalid move! Cannot move up." << endl;
                    }
                    break;
                case 4:
                    if (playerY < gridSize - 1) {
                        playerY++;
                        cout << "Player moved down." << endl;
                    } else {
                        cout << "Invalid move! Cannot move down." << endl;
                    }
                    break;
                default:
                    cout << "Invalid direction!" << endl;
                    break;
            }
        }
    } while (choice != 3);
    cout << "Game exited." << endl;
    return 0;
}