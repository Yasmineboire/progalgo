#include <string>
#include <limits>
#include <unordered_set>
#include <iostream>
#include <carte.txt>
#include <vector>
enum class Direction
{
    Up,
    Down,
    Left,
    Right,
};

struct Position
{
    int x{};
    int y{};
};
bool operator==(const Position &a, const Position &b)
{
    return a.x == b.x && a.y == b.y;
}
std::ostream &operator<<(std::ostream &os, const Position &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
Position &operator+=(Position &a, const Position &b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
Position &operator+=(Position &p, Direction d)
{
    switch (d)
    {
    case Direction::Up:
        p.y -= 1;
        break;
    case Direction::Down:
        p.y += 1;
        break;
    case Direction::Right:
        p.x += 1;
        break;
    case Direction::Left:
        p.x -= 1;
        break;
    }
    return p;
}
Position operator+(Position p, Direction d)
{
    p += d;
    return p;
}
Direction turn_right(Direction d)
{
    switch (d)
    {
    case Direction::Up:
        return Direction::Right;
    case Direction::Right:
        return Direction::Down;
    case Direction::Down:
        return Direction::Left;
    case Direction::Left:
        return Direction::Up;
    }

    return d;
}
struct Input_Structure
{
    Position guard_position;
    Direction guard_direction;
    vector<Position> obstacles;

}

Input_Structure
parse_input(std::istream &input_stream)
{
    Input_Structure input;

    int y = 0;
    for (std::string line{}; std::getline(input_stream, line, '\n') and line != "";)
    {
        for (int x = 0; x < (int)line.size(); ++x)
        {
            char c = line[x];

            if (c == '#')
            {
                input.obstacles.push_back({x, y});
            }
            else if (c == '^')
            {
                input.guard_position = {x, y};
                input.guard_direction = Direction::Up;
            }
            else if (c == '>')
            {
                input.guard_position = {x, y};
                input.guard_direction = Direction::Right;
            }
            else if (c == 'v')
            {
                input.guard_position = {x, y};
                input.guard_direction = Direction::Down;
            }
            else if (c == '<')
            {
                input.guard_position = {x, y};
                input.guard_direction = Direction::Left;
            }
        }

        ++y;
    }

    return input;
}
int main()
{
    Input_Structure input = parse_input(std::ifstream("carte.txt"));
}

namespace std
{
    template <>
    struct hash<Position>
    {
        std::size_t operator()(const Position &pos) const
        {
            return pos.x;
        }
    };
}
