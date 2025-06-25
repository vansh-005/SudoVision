#include <cstring>
#include <string>

extern "C" {

static char result_buffer[82];


bool is_valid(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; ++x) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            if (grid[startRow + r][startCol + c] == num)
                return false;
    return true;
}

//

bool solve_recursive(int grid[9][9], int row, int col) {
    if (row == 9)
        return true;
    if (grid[row][col] != 0) {
        if (col == 8) return solve_recursive(grid, row + 1, 0);
        else return solve_recursive(grid, row, col + 1);
    }
    for (int num = 1; num <= 9; ++num) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (col == 8) {
                if (solve_recursive(grid, row + 1, 0)) return true;
            } else {
                if (solve_recursive(grid, row, col + 1)) return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

const char* solve(const char* puzzle) {
    int grid[9][9] = {0};
    for (int i = 0; i < 81 && puzzle[i]; ++i) {
        char c = puzzle[i];
        if (c >= '1' && c <= '9')
            grid[i/9][i%9] = c - '0';
        else
            grid[i/9][i%9] = 0;
    }

    if (!solve_recursive(grid, 0, 0)) {
        result_buffer[0] = '\0';
        return result_buffer;
    }

    for (int i = 0; i < 81; ++i) {
        result_buffer[i] = '0' + grid[i/9][i%9];
    }
    result_buffer[81] = '\0';
    return result_buffer;
}

}
