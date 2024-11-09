#pragma once

#include <QMainWindow>
#include "ui_mainWidget.h"

class mainWidget : public QMainWindow
{
	Q_OBJECT

public:
	mainWidget(QWidget *parent = nullptr);
	~mainWidget();

private:
	Ui::mainWidgetClass ui;
};
