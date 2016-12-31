#ifndef FILTERDATA_H
#define FILTERDATA_H


class FilterData
{
public:
    FilterData(int filterSize);
    FilterData(const FilterData& other);

    void clone(const FilterData& other);

    int filterSize() const;
    void setFilterSize(int filterSize);

    float &operator[](int i);
    float operator[](int i) const;

private:
    int m_filterSize;
    float* m_data;
};

#endif // FILTERDATA_H
