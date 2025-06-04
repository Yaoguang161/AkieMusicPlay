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

	m_pUi->m_pbtnCurrentPlaying->setIcon(QIcon("../image/image/current-music.png"));
	m_pUi->m_pbtnCurrentPlaying->setIconSize(QSize(32, 32)); // 必须设置合适大小，否则图标可能不可见
	m_pUi->m_pbtnCurrentPlaying->setStyleSheet(R"(
		QPushButton {
			text-align: left;
			padding-left: 10px;
			font-size: 16px;
			color: #333333;
			font-weight: bold;
		}
	)");
	m_pUi->m_pbtnSoftWareName->setText("当前播放");


	m_pUi->m_pbtnLocalMusic->setIcon(QIcon("../image/image/local-music.png"));
	m_pUi->m_pbtnLocalMusic->setIconSize(QSize(32, 32)); // 必须设置合适大小，否则图标可能不可见
	m_pUi->m_pbtnLocalMusic->setStyleSheet(R"(
		QPushButton {
			text-align: left;
			padding-left: 10px;
			font-size: 16px;
			color: #333333;
			font-weight: bold;
		}
	)");
	m_pUi->m_pbtnSoftWareName->setText("本地音乐");


	m_pUi->m_pbtnFavoriteMusic->setIcon(QIcon("../image/image/favo-music.png"));
	m_pUi->m_pbtnFavoriteMusic->setIconSize(QSize(32, 32)); // 必须设置合适大小，否则图标可能不可见
	m_pUi->m_pbtnFavoriteMusic->setStyleSheet(R"(
		QPushButton {
			text-align: left;
			padding-left: 10px;
			font-size: 16px;
			color: #333333;
			font-weight: bold;
		}
	)");
	m_pUi->m_pbtnSoftWareName->setText("我的收藏");

	m_pUi->m_pbtnSongList->setIcon(QIcon("../image/image/myMusicList.png"));
	m_pUi->m_pbtnSongList->setIconSize(QSize(32, 32)); // 必须设置合适大小，否则图标可能不可见
	m_pUi->m_pbtnSongList->setStyleSheet(R"(
		QPushButton {
			text-align: left;
			padding-left: 10px;
			font-size: 16px;
			color: #333333;
			font-weight: bold;
		}
	)");
	m_pUi->m_pbtnSoftWareName->setText("我的歌单");
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