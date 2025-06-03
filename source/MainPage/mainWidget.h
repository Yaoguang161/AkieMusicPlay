#pragma once

#include <QMainWindow>
#include <QButtonGroup>
#include "ui_mainWidget.h"

class mainWidget : public QMainWindow
{
	Q_OBJECT

public:
	mainWidget(QWidget *parent = nullptr);
	~mainWidget();

private:
	void initUi();
	void setupConnections();

private:
	std::unique_ptr<Ui::mainWidgetClass>  m_pUi;
	QButtonGroup						 *m_pButtonGroup;
};
