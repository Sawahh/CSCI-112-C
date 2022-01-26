// Structure to define student
// Includes first and last name, numerical grade, 
// letter grade and whether it is curved

typedef struct {
	char name[30]; // First and last name together
	double grade; // double for numerical grade
	char letter[3]; // Letter grade
	char curved; // y or n for whether it is curved or not
} Student_t;

// Declarations
void print_grades(Student_t students[], int num);
int read_grades(Student_t students[]);
void calculate(Student_t students[], int num);
