#include "editor.h"
#include <iostream>
#include <string>

using namespace lab06;

void _create_npc(Editor& e) {
    TypeNPC type;
    std::cout << "NPC type (orc, knight or bear): ";
    std::string typestr, name;
    Coord coord;
    std::cin >> typestr;
    if (typestr == "orc") {
        type = ORC;
    } else if (typestr == "knight") {
        type = KNIGHT_ERRANT;
    } else if (typestr == "bear") {
        type = BEAR;
    } else {
        std::cout << "Wrong type!" << std::endl;
        return;
    }
    std::cout << "NPC name: ";
    std::cin >> name;
    std::cout << "Coordinates (x and y): ";
    std::cin >> coord.first >> coord.second;
    try {
        e.create_NPC(type, name, coord);
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return;
    }
}

void _delete_npc(Editor& e) {
    Coord coord;
    std::cout << "Enter coordinates of NPC (x and y): ";
    std::cin >> coord.first >> coord.second;
    try {
        e.delete_NPC(coord);
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return;
    }
}

void _move_npc(Editor& e) {
    std::cout << "Enter old coordinates of NPC (x and y): ";
    Coord oldc;
    std::cin >> oldc.first >> oldc.second;
    std::cout << "Enter new coordinates of NPC (x and y): ";
    Coord newc;
    std::cin >> newc.first >> newc.second;
    try {
        e.move_NPC(oldc, newc);
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return;
    }
}

void _save(const Editor& e) {
    std::cout << "Enter path to file: ";
    std::string filename;
    std::cin >> filename;
    try {
        e.save_to_file(filename);
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return;
    }
    std::cout << "Saved!" << std::endl;
}

void _load(Editor& e) {
    std::cout << "Enter path to file: ";
    std::string filename;
    std::cin >> filename;
    try {
        e.load_from_file(filename);
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return;
    }
    std::cout << "Loaded!" << std::endl;
}

void _fight(Editor& e) {
    std::cout << "Enter distance of fight: ";
    int distance;
    std::cin >> distance;
    try {
        e.fight(distance);
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return;
    }
}

void interface() {
    Editor e;
    std::cout << "Welcome to Balagur Fate 3 Editor" << std::endl;
    std::cout << "Enter <h> to show help page" << std::endl;
    std::cout << "> ";
    char state;
    while (1) {
        std::cin >> state;
        if (state == 'h') {
            std::cout << "Menu:\n";
            std::cout << "1. Create a NPC\n";
            std::cout << "2. Delete a NPC\n";
            std::cout << "3. Move a NPC\n";
            std::cout << "4. Save configuration to file\n";
            std::cout << "5. Load configuration from file\n";
            std::cout << "6. Print game map\n";
            std::cout << "7. Initiate a fight\n";
            std::cout << "q - exit\n";
        } else if (state == '1') {
            _create_npc(e);
        } else if (state == '2') {
            _delete_npc(e);
        } else if (state == '3') {
            _move_npc(e);
        } else if (state == '4') {
            _save(e);
        } else if (state == '5') {
            _load(e);
        } else if (state == '6') {
            e.print_map();
            std::cout << std::endl;
        } else if (state == '7') {
            _fight(e);
        } else if (state == 'q') {
            return;
        } else {
            std::cout << "Wrong command!" << std::endl;
        }
        std::cout << "> ";
    }
}

int main() {
    interface();

    return 0;
}
