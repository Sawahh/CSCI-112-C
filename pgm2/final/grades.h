
typedef struct {
    char first_name[30];
    char last_name[30];
    double grade;
    char letter_grade[3];
    char curved; 
} Student_t;

typedef struct {
    char letter[3];
    double lower_limit;
} Grade_t;

typedef struct node_t {
	Student_t* student;
	struct node_t *next;
}Node_t;

// Function declarations
void ReadGrades(Node_t**);
void CalculateLetterGrade(Node_t**);
void PrintGrades(Node_t*);
void Sort(Node_t**);

