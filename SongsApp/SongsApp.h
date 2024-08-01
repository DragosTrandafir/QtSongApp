#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_SongsApp.h"
#include<QWidget>
#include<QTableWidget>
#include<QGridLayout>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QFormLayout>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QStringList>
#include<QHeaderView>
//#include <QAbstractScrollArea>
#include"SongController.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(SongController& ctrl, QWidget *parent = nullptr);
    ~MainWindow();

signals:

    public slots:
        void addSongSongs();
        void deleteSong();
        void addSongPlaylist();
private:
    //all objects that you use

    //left
    QLabel* leftTitle;
    QString* tableHeader;
    QTableWidget* songsTable;

    QLineEdit* titleEdit;
    QLineEdit* artistEdit;
    QLineEdit* durationEdit;
    QLineEdit* pathEdit;

    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* filterButton;

    //center
    QPushButton* arrowButton;

    //right
    QLabel* rightTitle;
    QTableWidget* playlistTable;
    QPushButton* playButton;
    QPushButton* nextButton;

    SongController& controller;
    void setupUi();
};
