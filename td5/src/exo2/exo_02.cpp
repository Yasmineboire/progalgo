#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

// question 1
enum class Direction { Up, Down, Left, Right };

struct Position {
    int x{};
    int y{};

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template <>
    struct hash<Position> {
        std::size_t operator()(const Position& pos) const {
            return std::hash<int>()(pos.x) ^ (std::hash<int>()(pos.y) << 1);
        }
    };
}

Position operator+(Position p, Direction d) {
    switch (d) {
        case Direction::Up:    p.y -= 1; break;
        case Direction::Down:  p.y += 1; break;
        case Direction::Right: p.x += 1; break;
        case Direction::Left:  p.x -= 1; break;
    }
    return p;
}

Direction turn_right(Direction d) {
    switch (d) {
        case Direction::Up:    return Direction::Right;
        case Direction::Right: return Direction::Down;
        case Direction::Down:  return Direction::Left;
        case Direction::Left:  return Direction::Up;
    }
    return d;
}

//question 2
struct Input_Structure {
    Position guard_position;
    Direction guard_direction;
    std::unordered_set<Position> obstacles;
    int width{0};
    int height{0};
};

Input_Structure parse_input(std::istream& input_stream) {
    Input_Structure input;
    std::string line;
    int y = 0;
    int max_x = 0;

    while (std::getline(input_stream, line) && !line.empty()) {
        if ((int)line.size() > max_x) max_x = (int)line.size();
        for (int x = 0; x < (int)line.size(); ++x) {
            char c = line[x];
            if (c == '#') {
                input.obstacles.insert({x, y});
            } else if (c == '^') {
                input.guard_position = {x, y};
                input.guard_direction = Direction::Up;
            } else if (c == 'v') {
                input.guard_position = {x, y};
                input.guard_direction = Direction::Down;
            } else if (c == '>') {
                input.guard_position = {x, y};
                input.guard_direction = Direction::Right;
            } else if (c == '<') {
                input.guard_position = {x, y};
                input.guard_direction = Direction::Left;
            }
        }
        y++;
    }
    input.width = max_x;
    input.height = y;
    return input;
}

//question 3
struct WalkResult {
    Position final_position;
    int steps_taken{0};
    std::unordered_set<Position> visited_positions;
};

WalkResult simulate_walk(const Input_Structure& input) {
    WalkResult result;
    Position pos = input.guard_position;
    Direction dir = input.guard_direction;

    while (true) {
        result.visited_positions.insert(pos);
        Position next = pos + dir;

        if (next.x < 0 || next.y < 0 || next.x >= input.width || next.y >= input.height) {
            result.final_position = pos;
            return result;
        }

        if (input.obstacles.count(next)) {
            dir = turn_right(dir);
        } else {
            pos = next;
            result.steps_taken++;
        }
    }
}

//question 4


int main() {
    std::ifstream file("input_guard_patrol.txt");
    Input_Structure data = parse_input(file);
    WalkResult result = simulate_walk(data);

    std::cout << "Dimensions de la carte : " << data.width << "x" << data.height << std::endl;
    std::cout << "Nombre de positions visitees : " << result.visited_positions.size() << std::endl;

    return 0;
}
