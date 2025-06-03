#include "mainWidget.h"

#include <QOverload>
#include <QFile>

mainWidget::mainWidget(QWidget *parent)
	: QMainWindow(parent)
	, m_pUi(std::make_unique<Ui::mainWidgetClass>())
	, m_pButtonGroup(nullptr)
{
	m_pUi->setupUi(this);

	initUi();

	setupConnections();
}

mainWidget::~mainWidget()
{

}

void mainWidget::initUi()
{
	m_pUi->m_pbtnSoftWareName->setIcon(QIcon("../image/image/Title.png"));
	m_pUi->m_pbtnSoftWareName->setIconSize(QSize(32, 32)); // 必须设置合适大小，否则图标可能不可见
	m_pUi->m_pbtnSoftWareName->setStyleSheet(R"(
		QPushButton {
			text-align: left;
			padding-left: 10px;
			font-size: 16px;
			color: #333333;
			font-weight: bold;
		}
	)");
	m_pUi->m_pbtnSoftWareName->setText("AkieMusicPlay");
}

void mainWidget::setupConnections()
{
	m_pButtonGroup = new QButtonGroup(this);  //由对象树回收
    m_pButtonGroup->addButton(m_pUi->m_pbtnCurrentPlaying, 0);
    m_pButtonGroup->addButton(m_pUi->m_pbtnLocalMusic, 1);
    m_pButtonGroup->addButton(m_pUi->m_pbtnFavoriteMusic, 2);
    m_pButtonGroup->addButton(m_pUi->m_pbtnSongList, 3);

	connect(m_pButtonGroup, &QButtonGroup::idClicked, m_pUi->stackedWidget, &QStackedWidget::setCurrentIndex);

	m_pUi->stackedWidget->setCurrentIndex(0);
}