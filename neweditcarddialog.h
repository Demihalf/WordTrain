/******************************************************************************
** WordTrain 0.8.4 -- Foreign words trainer
** Copyright (C) 2010  Valery Kharitonov
**
** This file is part of WordTrain.
**
** $QT_BEGIN_LICENSE:GPL$
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
** $QT_END_LICENSE$
**
******************************************************************************/

#ifndef NEWCARDDIALOG_H
#define NEWCARDDIALOG_H

#include <QtGui>
#include "wordscard.h"
#include "exampleswidget.h"

// Create new card or edit existing one
class NewEditCardDialog : public QDialog
{
    Q_OBJECT
public:
    /* If we want to add new card (you should use getNewCard() to get values) */
    NewEditCardDialog(QWidget *parent = 0);
    /* If we want to edit existing card (we don't change value of card directly,
       you should use getNewCard() to get new values) */
    NewEditCardDialog(const WordCard &card, QWidget *parent = 0);
    const WordCard& getNewCard();

public slots:
    void addExample();

private:
    void createInterface();
    /* Fills the form with current card's content */
    void fillForm();

    QLineEdit* txtWord;
    QLineEdit* txtTranscription;
    QLineEdit* txtTranslation;
    QLineEdit* txtPlural;
    QComboBox* cmbCategory;
    QComboBox* cmbGender;
    QPushButton* btnAddExample;
    QPushButton* btnOk;
    QPushButton* btnCancel;
    ExamplesWidget* wgtExamples;
    QScrollArea *scrollExamples;

    /* Temporary card for holding new values */
    WordCard mNewCard;
};

#endif // NEWCARDDIALOG_H
