//
//  main.cpp
//  ComputerRecommendationSystem
//
//  Created by Elif Zeynep Çetinkaya on 26.08.2024.
//

#include <iostream>
using namespace std;

class Computer{
public:
    virtual void writeCode() = 0;
    virtual void playGame() = 0;
    virtual ~Computer(){}
};

class Laptop : public Computer{
private:
    string model;
    
public:
    Laptop(string m) : model(m){}
    
    void writeCode(){
        cout << "You can code on " << model << " laptop using C++ " << endl;
    }
    
    void playGame(){
        cout << "You can play Minecraft on " << model << " laptop." << endl;
    }
};

class Desktop : public Computer{
private:
    string type;
    
public:
    Desktop(string t) : type(t){}
    
    void writeCode() override {
        cout << "You can code on " << type << " desktop using C++ " << endl;
    }
    
    void playGame() override {
        cout << "You can play Minecraft on " << type << " desktop." << endl;
    }
};

Computer* recommendComputer(char preference, int budget){
    
    switch (preference) {
            case 'L':
            case 'l':
                if (budget >= 1500) {
                    cout << "We recommend the MacBook Pro for you:" << endl;
                    return new Laptop("MacBook Pro");
                } else if (budget >= 1000) {
                    cout << "We recommend the Dell XPS for you:" << endl;
                    return new Laptop("Dell XPS");
                } else {
                    cout << "Sorry, we couldn't find a suitable recommendation for your budget." << endl;
                    return nullptr; // nullptr: instead of using 'return 0' or 'break', I used nullptr to let the compiler understand that pointer is not addressing anything. (GeeksforGeeks - nullptr in C++)
                }

            case 'D':
            case 'd':
                if (budget >= 2500) {
                    cout << "We recommend the Workstation Desktop for you:" << endl;
                    return new Desktop("Workstation Desktop");
                } else if (budget >= 2000) {
                    cout << "We recommend the Gaming Desktop for you:" << endl;
                    return new Desktop("Gaming Desktop");
                } else {
                    cout << "Sorry, we couldn't find a suitable recommendation for your budget." << endl;
                    return nullptr;
                }

            default:
                cout << "Invalid preference! Please choose either Laptop or Desktop." << endl;
                return nullptr;
        }
        return nullptr;
    }
int main(){
    
    char recommendation, preference;
    int budget;
    cout << "Welcome to the Computer Recommendation System! " << endl;
    
    do {
        
       cout << "Do you prefer a Laptop or a Desktop (L/D): ";
        cin >> preference;

        if (preference == 'L' || preference == 'l' || preference == 'D' || preference == 'd') {
            cout << "What is your budget? (Enter a numeric value): ";
            cin >> budget;

            Computer* computer = recommendComputer(preference, budget);
            if (computer) {
                computer->writeCode();
                computer->playGame();
                delete computer;
            }
        } else {
            cout << "Invalid preference! Please choose either Laptop or Desktop." << endl;
        }
 
        cout << "Do you want another recommendation? (Y/N): ";
        cin >> recommendation;
        
    } while (recommendation == 'Y' || recommendation == 'y');
    
    cout << "Thank you for using the Computer Recommendation System! Goodbye! " << endl;
    
    return 0;
}
