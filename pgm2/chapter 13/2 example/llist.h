
typedef struct {
    int num1;
} Data_t;

typedef struct node_t {
    Data_t* data;
    struct node_t *next;
} Node_t;


int read(Node_t**);
int sort
