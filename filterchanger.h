#ifndef FILTERCHANGER_H
#define FILTERCHANGER_H

#include <QDialog>
#include <QGridLayout>
#include <QLayout>
#include "filterdata.h"

class FilterChanger : public QDialog
{
    Q_OBJECT
public:
    explicit FilterChanger(FilterData* data, QWidget *parent = 0);

signals:

public slots:
    void cancelPressed();
    void editorChanged(QString text);
    void acceptPressed();

private:
    QGridLayout* m_grid;
    FilterData* m_data;
    FilterData* m_tempData;
};

#endif // FILTERCHANGER_H
