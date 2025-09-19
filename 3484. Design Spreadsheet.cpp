class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid; // 2D vector for spreadsheet

    // Helper: check if operand is a number or cell
    bool isNumber(const string& s) {
        return isdigit(s[0]);
    }

    // Helper: get cell value from reference like "A1"
    int getCellValue(const string& ref) {
        int col = ref[0] - 'A';               // column index
        int row = stoi(ref.substr(1)) - 1;    // 1-indexed to 0-indexed
        return grid[row][col];
    }

public:
    Spreadsheet(int r) {
        rows = r;
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        // formula like "=X+Y"
        formula = formula.substr(1); // remove '='
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        int val1 = isNumber(left) ? stoi(left) : getCellValue(left);
        int val2 = isNumber(right) ? stoi(right) : getCellValue(right);

        return val1 + val2;
    }
};