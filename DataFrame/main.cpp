#include <iostream>

using namespace std;

class DataFrame
{
protected:    
    int** table;
    int noRows, noCols;
    char** colNames;
    char** rowNames;
 
public:
    DataFrame ();    
    DataFrame (int rows, int cols);
    void display();

    void setUpTable();
    void setRowName(int row, char* name);
    void setColName(int col, char* name);
    int* operator[] (int i);

    char** getRowNames();
    char** getColNames();
    int getNumberRows();
    int getNumberCols();
    DataFrame* getColumns(int* columns, int cLen);
    DataFrame* getRows(int* rows, int rLen);
    DataFrame* getRowsCols(int* rows, int rLen, int* cols, int cLen);

    ~DataFrame();
};

DataFrame::DataFrame() {}

DataFrame::DataFrame(int rows, int cols)
{
    noRows = rows;
    noCols = cols;

    table = new int*[noRows];

    for (int i = 0; i < noRows; ++i)
        table[i] = new int[noCols];

    colNames = new char*[noCols];
    rowNames = new char*[noRows];

    colNames = new char*[noCols];
    rowNames = new char*[noRows];
    
    for (int i=0; i < 100; i++)
        rowNames[i] = new char[100];

    for (int i=0; i < 100; i++)
        colNames[i] = new char[100];

    for (int i=0; i < noCols; i++)
        colNames[i][0] = '\0';

    for (int i=0; i < noRows; i++)
        rowNames[i][0] = '\0';    
}

void DataFrame::setUpTable()
{
    colNames = new char*[noCols];
    rowNames = new char*[noRows];

    colNames = new char*[noCols];
    rowNames = new char*[noRows];
    
    int j=0;
    char c;
    
    for (int i=0; i < 100; i++)
        rowNames[i] = new char[100];
    
    for (int i=0; i < 100; i++)
        colNames[i] = new char[100];

    for (int i=0; i < noCols; i++)
    {
        cin.get(c);
        j = 0;
        do {
            colNames[i][j] = c;
            j++;
            cin.get(c);
        } while ((c != ',') && (c != '\n'));
        colNames[i][j] = '\0';
    }
    
    int k=0;
    char e;

    for (int i=0; i < noRows; i++)
    {
        cin.get(e); //read the first character
        k = 0;
        do {
            rowNames[i][k++] = e;
            cin.get(e);
        } while ((e != ',') && (e != '\n'));
        rowNames[i][k] = '\0';
    }
    
    /** Set Up Table Content **/
    for (int i=0; i < noRows; i++) {
        for (int j=0; j < noCols; j++) {
            cin >> table[i][j];
        }
    }
}


void DataFrame::display() {
    
    /** print Column names **/
    for (int i = 0; i < noCols; ++i) {
        cout << colNames[i];
        if (i != (noCols - 1)) {
            cout << ",";
        }
    }
    cout << "\n";
    
    /** print Row names **/
    for (int i = 0; i < noRows; ++i) {
        cout << rowNames[i];
        if (i != (noRows - 1)) {
            cout << ",";
        }
    }
    cout << "\n";
    
    /** print Table contents **/
    for (int i = 0; i < noRows; ++i) {
        for (int j = 0; j < noCols; ++j) {
            cout << table[i][j] << " ";
        }
        if (i != (noRows - 1)) {
            cout << endl;
        }
        
    }
}

void DataFrame::setRowName(int row, char* name) {
    rowNames[row] = name;
}

void DataFrame::setColName(int col, char* name) {
    colNames[col] = name;
}

// return row i
int* DataFrame::operator[](int i) {
    return table[i];
}

/** Getter Methods **/
char** DataFrame::getRowNames() {
    return rowNames;
}

char** DataFrame::getColNames() {
    return colNames;
}

int DataFrame::getNumberRows() {
    return noRows;
}

int DataFrame::getNumberCols() {
    return noCols;
}
DataFrame* DataFrame::getColumns(int* columns, int cLen) {
    
    DataFrame* temp = new DataFrame();
    
    (*temp).noCols = cLen;
    (*temp).noRows = noRows;
    
    /** Set up the table itself **/
    
    // double pointers allow us to initialize an array of rows size where each element in the array has cols size.
    (*temp).table = new int*[noRows];
    
    
    for (int i = 0; i < noRows; ++i) {
        (*temp).table[i] = new int[cLen]; // each row has spaces for cLen
    }
    
    /** Set up Table Names **/
    
    (*temp).colNames = new char*[cLen]; // a 1-d array with cols number of names
    
    for (int i=0; i < 100; i++) {
        (*temp).colNames[i] = new char[100];
    }
    
    (*temp).rowNames = new char*[noRows]; // a 1-d array with rows number of names
    
    for (int i=0; i < 100; i++) { 
        (*temp).rowNames[i] = new char[100];
    }
    
    /** Column names **/
    for (int i = 0; i < cLen; ++i) {
        (*temp).colNames[i] = colNames[columns[i]];
    }
    
    /** Row names **/
    for (int i = 0; i < noRows; ++i) {
        (*temp).rowNames[i] = rowNames[i];
    }
    
    for (int i = 0; i < noRows; ++i) {
        for (int j = 0; j < cLen; ++j) {
            (*temp).table[i][j] = table[i][columns[j]];
        }
    }
    
    return temp;
}

DataFrame* DataFrame::getRows(int* rows, int rLen)
{
    DataFrame* temp = new DataFrame();
    
    (*temp).noCols = noCols;
    (*temp).noRows = rLen;
    
    /** Set up the table itself **/
    
    (*temp).table = new int*[rLen]; // double pointers allow us to initialize an array of rows size where each element in the array has cols size.
    
    for (int i = 0; i < rLen; ++i) {
        (*temp).table[i] = new int[noCols]; // each row has spaces for cLen
    }
    
    /** Set up Table Names **/
    
    (*temp).colNames = new char*[noCols]; // a 1-d array with cols number of names
    
    for (int i=0; i < 100; i++) {
        (*temp).colNames[i] = new char[100];
    }
    
    (*temp).rowNames = new char*[rLen]; // a 1-d array with rows number of names
    
    for (int i=0; i < 100; i++) {
        (*temp).rowNames[i] = new char[100];
    }
    
    /** Column names **/
    for (int i = 0; i < noCols; ++i) {
        (*temp).colNames[i] = colNames[i];
    }
    
    /** Row names **/
    for (int i = 0; i < rLen; ++i) {
        (*temp).rowNames[i] = rowNames[rows[i]];
    }
    
    for (int i = 0; i < rLen; ++i) {
        for (int j = 0; j < noCols; ++j) {
            (*temp).table[i][j] = table[rows[i]][j];
        }
    }
    
    return temp;
}

DataFrame* DataFrame::getRowsCols(int* rows, int rLen, int* cols, int cLen) {
    
    DataFrame* temp = new DataFrame();
    
    (*temp).noCols = cLen;
    (*temp).noRows = rLen;
    
    /** Set up the table itself **/
    
    (*temp).table = new int*[rLen]; // double pointers allow us to initialize an array of rows size where each element in the array has cols size.
    
    for (int i = 0; i < rLen; ++i) {
        (*temp).table[i] = new int[cLen]; // each row has spaces for cLen
    }
    
    /** Set up Table Names **/
    
    (*temp).colNames = new char*[cLen]; // a 1-d array with cols number of names
    
    for (int i=0; i < 100; i++) { 
        (*temp).colNames[i] = new char[100];
    }
    
    (*temp).rowNames = new char*[rLen]; // a 1-d array with rows number of names
    
    for (int i=0; i < 100; i++) { 
        (*temp).rowNames[i] = new char[100];
    }
    
    /** Column names **/
    for (int i = 0; i < cLen; ++i) {
        (*temp).colNames[i] = colNames[cols[i]];
    }
    
    /** Row names **/
    for (int i = 0; i < rLen; ++i) {
        (*temp).rowNames[i] = rowNames[rows[i]];
    }
    
    for (int i = 0; i < rLen; ++i) {
        for (int j = 0; j < cLen; ++j) {
            (*temp).table[i][j] = table[rows[i]][cols[j]];
        }
    }
    
    return temp;
}


DataFrame::~DataFrame() { //Destructor for table
    
    noRows = 0;
    noCols = 0;
    rowNames = NULL;
    colNames = NULL;
    
     for (int i = 0; i < noRows; ++i) {
         delete rowNames[i];
         delete table[i];
     }
     for (int j = 0; j < noCols; ++j) {
         delete colNames[j];
     }
    
     delete[] rowNames;
     delete[] colNames;
     delete[] table;
}


int main () {
    int c, r;
    int selectC[3];
    int selectR[10];
    
    // Read the dataframe from input
    // First line: two numbers seperated by space;
    // first number is the number of rows (r) and
    // second number is the number of columns (c)
    
    cin >> r >> c;
    DataFrame* firstDF = new DataFrame(r,c);
    
    // Second line: strings separated by a comma (c of them); representing column names
    // Third line: strings seperated by a comma (r of them); representing row names
    // Fourth line and more: c number of integers in each of the r rows (seperated by) // a space between integers in the same row.
    
    // using the display method, print (in the same format as the input):
    // - the column names of the dataframe
    // - the row names of the dataframe
    // - the contents of the table in dataframe
    
    (*firstDF).setUpTable();
    (*firstDF).display();
    
    // Execute the following code
    // Read the column numbers that you want to extract
    
    for (int i=0; i < 3; i++) cin >> selectC[i];
    
    DataFrame* tempColumns = (*firstDF).getColumns(selectC, 3);

    (*tempColumns).display();
    
    // Change the row names of select rows
    
    (*tempColumns).setRowName(2, "Jack"); (*tempColumns).setRowName(3, "Peter");
    (*tempColumns).display();
    
    // Read the row numbers that you want to extract
    for (int i=0; i < 10; i++)
        cin >> selectR[i];
    
    DataFrame* tempRows = (*firstDF).getRows(selectR, 10);

    (*tempRows).display();
    
    // Change the column names of selected columns
    (*tempRows).setColName(2, "Scores");
    (*tempRows).setColName(3, "Values");
    (*tempRows).display();
    
    // Extract the rows in SelectR and columns in SelectC
    
    DataFrame* tempColsRows = (*firstDF).getRowsCols(selectR, 10, selectC, 3);

    (*tempColsRows).display();
    
    delete tempRows;
    
     delete tempColumns;
  
     delete tempColsRows;
    
    // Sample Code for you and you must execute this
    
    DataFrame* myTable = new DataFrame(5,5);
    
    for (int i =0; i < 5; i++) {
        for (int j=0; j < 5; j++) {
            (*myTable)[i][j] = i*j;
        }
    }
    
    (*myTable).display();
    
    delete myTable;
    
    return 0;
}
