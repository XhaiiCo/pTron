#ifndef CASE_H
#define CASE_H


class Case
{
    private:

    public:
        Case();
        virtual ~Case();
        Case(const Case& other);
        Case& operator=(const Case& other);

};

#endif // CASE_H
