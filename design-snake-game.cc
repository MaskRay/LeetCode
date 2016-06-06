// Design Snake Game
class SnakeGame {
  int w, h, x = 0, y = 0;
  vector<pair<int, int>> food;
  vector<vector<bool>> occ;
  deque<pair<int, int>> a{{0, 0}};
public:
  /** Initialize your data structure here.
    @param width - screen width
    @param height - screen height
    @param food - A list of food positions
    E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
  SnakeGame(int width, int height, vector<pair<int, int>> food) {
    w = width;
    h = height;
    occ.assign(h, vector<bool>(w, false));
    occ[0][0] = true;
    reverse(food.begin(), food.end());
    this->food = std::move(food);
  }

  /** Moves the snake.
    @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
    @return The game's score after the move. Return -1 if game over.
    Game over when snake crosses the screen boundary or bites its body. */
  int move(string direction) {
    if (x < 0) return -1;
    if (direction == "U") y--;
    if (direction == "D") y++;
    if (direction == "L") x--;
    if (direction == "R") x++;
    if (x < 0 || x >= w || y < 0 || y >= h) return x = -1;
    a.emplace_back(x, y);
    if (food.size() && x == food.back().second && y == food.back().first)
      food.pop_back();
    else {
      occ[a.front().second][a.front().first] = false;
      a.pop_front();
      if (occ[y][x]) return x = -1;
    }
    occ[y][x] = true;
    return a.size()-1;
  }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
