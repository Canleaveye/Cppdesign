#ifndef MYSORTSTRATEGY_H
#define MYSORTSTRATEGY_H


class MySortStrategy
{
public:
    MySortStrategy();
    virtual void sort(StudentList* head) = 0;
};

#endif // MYSORTSTRATEGY_H
