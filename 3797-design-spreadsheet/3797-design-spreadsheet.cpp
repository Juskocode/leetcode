class Spreadsheet {
public:

    unordered_map<string, int> spreadSheet;

    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        spreadSheet[cell] = value;
    }
    
    void resetCell(string cell) {
        spreadSheet.erase(cell);
    }

    int getValue(string formula) {
        int idx = formula.find('+');
        string cell1 = formula.substr(1, idx - 1);
        string cell2 = formula.substr(idx + 1);
        return (isalpha(cell1[0]) ? spreadSheet[cell1] : stoi(cell1)) +
               (isalpha(cell2[0]) ? spreadSheet[cell2] : stoi(cell2));
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */