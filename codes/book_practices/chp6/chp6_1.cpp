//
// Created by BlazarLin on 2020/7/25.
//

// NO.1 改写以下类，使它成为一个class template
class example{
public:
    example(double min, double max);
    example(const double *array, int size);
    double operator[](int index);
    bool operator==(const example&) const;
    bool insert(const double*, int);
    bool insert(double);
    double min() const {return _min;}
    double max() const {return _max;}
    void min(double);
    void max(double);

    int count(double value) const;

private:
    int size;
    double *parray;
    double _min;
    double _max;
};