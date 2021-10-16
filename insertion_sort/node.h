struct mynode {
    int const value;
    struct mynode *next;
    struct mynode *prev;
};

void printlist(struct mynode* start);
struct mynode *insertionsort(struct mynode* start1);
