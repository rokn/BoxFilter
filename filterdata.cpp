#include "filterdata.h"

FilterData::FilterData(int filterSize)
    :m_filterSize(filterSize)
{
    m_data = new float[m_filterSize * m_filterSize];
    for (int i = 0; i < m_filterSize * m_filterSize; ++i) {
        m_data[i] = 0;
    }
    m_data[m_filterSize * m_filterSize/2] = 1;
}

FilterData::FilterData(const FilterData &other)
{
    clone(other);
}

void FilterData::clone(const FilterData &other)
{
    m_filterSize = other.filterSize();

    m_data = new float[m_filterSize * m_filterSize];

    for (int i = 0; i < m_filterSize * m_filterSize; ++i) {
        m_data[i] = other.m_data[i];
    }
}

int FilterData::filterSize() const
{
    return m_filterSize;
}

void FilterData::setFilterSize(int filterSize)
{
    m_filterSize = filterSize;
}

float &FilterData::operator[](int i)
{
    return m_data[i];
}

float FilterData::operator[](int i) const
{
    return m_data[i];
}
