#include <iostream>
#include <string>

class Player {
    int score;
    std::string forename, surname;
    bool alive;

public:
    // Constructor
    Player(const std::string &forename, const std::string &surname) {
        this->forename = forename;
        this->surname = surname;
        this->score = 0;
        this->alive = true;
    }

    void addOnePoint(){this->score++;}
    void kill(){this->alive = false;}
    bool isAlive() {return this->alive;}
    int getScore(){return this->score;}
};

class Ghost {
    int doorNumber;

public:
    Ghost() {this->doorNumber = 0;};
    void setNewDoor() {
        srand(time(0));
        this->doorNumber = (rand() % 5) + 1;
    }
    int getDoorNumber(){return this->doorNumber;}
};

int main() {
    std::cout << "Welcome to !GHOST GAME!\n" << std::endl;

    bool game_running = true;
    while (game_running) {
        std::string forename, surname;
        std::cout << "Please enter your name" << std::endl;
        std::cout << "Forename: ";
        std::cin >> forename;
        std::cout << "Surname: ";
        std::cin >> surname;

        std::cout << "\nThe Ghost is behind 1 of 5\nIf choose the door with ghost behind you die\nIf you dodge the ghost, you live and gain 1 point\n" << std::endl;

        Player player = Player(forename, surname);
        Ghost ghost;
        int choice;

        while (player.isAlive()) {
            ghost.setNewDoor();
            std::cout << "Choose your door (1-5): ";
            std::cin >> choice;

            // input validation
            if (choice < 1 || choice > 5) {
                std::cout << "\nInvalid Door Number!\n" << std::endl;
                continue;
            }

            // checks if user dodges ghost door
            if (choice != ghost.getDoorNumber()) {
                std::cout << "You dodged the ghost! You gain 1 point\n" << std::endl;
                player.addOnePoint();
            } else {
                std::cout << "You chose the ghost door! You die!\n" << std::endl;
                player.kill();
            }

        }
        std::cout << "Your final score: " << player.getScore();
        game_running = false;
    }

    return 0;
}
