#include "filterchanger.h"
#include <QLineEdit>
#include <QPushButton>
#include <QDoubleValidator>
#include <QDebug>

FilterChanger::FilterChanger(FilterData *data, QWidget *parent)
    : QDialog(parent), m_grid(new QGridLayout(this)), m_data(data), m_tempData(new FilterData(*data))
{
    setModal(true);
    setLayout(m_grid);
    int size = data->filterSize();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            QLineEdit* editor = new QLineEdit(this);
            editor->setProperty("cell", (i * size + j));
            editor->setText(QString::number((*data)[i * size + j]));
            editor->setValidator(new QDoubleValidator(-100, 100, 2, this));
            connect(editor, SIGNAL(textChanged(QString)), this, SLOT(editorChanged(QString)));
            this->m_grid->addWidget(editor, i, j);
        }
    }

    QPushButton *cancel = new QPushButton("Cancel", this);
    QPushButton *accept = new QPushButton("Accept", this);

    m_grid->addWidget(cancel, size, 0);
    m_grid->addWidget(accept, size, size - 1);

    connect(cancel, SIGNAL(pressed()), this, SLOT(cancelPressed()));
    connect(accept, SIGNAL(pressed()), this, SLOT(acceptPressed()));
}

void FilterChanger::cancelPressed()
{
    this->close();
}

void FilterChanger::editorChanged(QString text)
{
    int cell = sender()->property("cell").toInt();
    (*m_tempData)[cell] = text.toFloat();
    qInfo() << (*m_tempData)[cell];
    qInfo() << text.toFloat();
}

void FilterChanger::acceptPressed()
{
    m_data->clone(*m_tempData);
    this->close();
}
