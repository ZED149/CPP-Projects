// COURSE.CPP - Course class implementation
#define _CRT_SECURE_NO_WARNINGS

#include "course.h"

Course::Course()
{
    name[0] = '\0'; // it is a char * string, not a C++ string object.
}

Course::Course(const char* nam, char sect,
    unsigned cred)
{
    //strncpy(name, nam, CourseNameSize);
    strcpy_s(name, sizeof nam, nam);
    section = sect;
    credits = cred;
}

istream& operator >>(istream& input, Course& C)
{
    input >> C.name >> C.section >> C.credits;
    return input;
}

ostream& operator <<(ostream& os, const Course& C)
{
    os << "  Course:  " << C.name << '\n'
        << "  Section: " << C.section << '\n'
        << "  Credits: " << C.credits << '\n';
    return os;
}
