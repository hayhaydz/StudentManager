#include "Student.h"

void Student::clear() {
	number = 0;
	name = "";
	courseMarks.fill(0);
	courseMarksTotal = 0;
	examMark = 0;
	totalMarks = 0;
	overallPercentage = 0;
	grade = 'f';
}
