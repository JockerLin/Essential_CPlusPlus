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


// 改写如下：
template <typename elemType>
class exampleTempClass{
public:
    exampleTempClass(const elemType min, const elemType max);
    exampleTempClass(const elemType *array, int size);
    elemType& operator[](int index);
    bool operator==(const exampleTempClass&) const;
    bool insert(const elemType*, int);
    bool insert(const elemType&);
    elemType min() const {return _min;}
    elemType max() const {return _max;}
    void min(const elemType&);
    void max(const elemType&);

    int count(const elemType &value) const;

private:
    int size;
    double *parray;
    double _min;
    double _max;
};

