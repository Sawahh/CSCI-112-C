
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

// function declarations
int ReadGrades(Student_t*);
void CalculateLetterGrade(Student_t*, int);
void PrintGrades(Student_t*, int);

