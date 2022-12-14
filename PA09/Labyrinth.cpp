#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    MazeCell *Location = start;
    bool Book = false;
    bool stick = false;
    bool drink = false;
    for (int i = 0; i < moves.length(); i++) {
        if(moves.substr(i,1) == "S"){
            Location = Location->south;
        }else if(moves.substr(i,1) == "E"){
            Location = Location->east;
        }else if(moves.substr(i,1) == "N"){
            Location = Location->north;
        }else if(moves.substr(i,1) == "W"){
            Location = Location->west;
        }
        if(Location->whatsHere == Item::SPELLBOOK){
            Book = true;
        }
        if(Location->whatsHere == Item::WAND){
            stick = true;
        }
        if(Location->whatsHere == Item::POTION){
            drink = true;
        }
        if(Book && stick && drink){
            return true;
        }
    }
    return false;
}
