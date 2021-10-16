class Verifier {
    private:
        int grid[9][9];
    public:
        void readGrid(const char*);
        void printGrid();
        bool verifySolution();
};
