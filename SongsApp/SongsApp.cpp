#include "SongsApp.h"
#include<stdexcept>
//#include <QMessageBox>
MainWindow::MainWindow(SongController& ctrl, QWidget *parent)
    : QMainWindow(parent), controller{ctrl}
{
    setupUi();
    // all the connects
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addSongSongs);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteSong);
    connect(arrowButton, &QPushButton::clicked, this, &MainWindow::addSongPlaylist);
}

MainWindow::~MainWindow()
{}
void MainWindow::addSongSongs()
{
    controller.add(titleEdit->text().toStdString(), artistEdit->text().toStdString(), durationEdit->text().toFloat(), pathEdit->text().toStdString());
    
    int currentRow = songsTable->rowCount();
    songsTable->insertRow(currentRow);

    songsTable->setItem(currentRow, 0, new QTableWidgetItem(titleEdit->text()));
    songsTable->setItem(currentRow, 1, new QTableWidgetItem(artistEdit->text()));
    songsTable->setItem(currentRow, 2, new QTableWidgetItem(durationEdit->text()));
    songsTable->setItem(currentRow, 3, new QTableWidgetItem(pathEdit->text()));

    titleEdit->clear();
    artistEdit->clear();
    durationEdit->clear();
    pathEdit->clear();

    songsTable->resizeRowsToContents();
}

void MainWindow::deleteSong()
{
    // Get selected ranges from songsTable
    QList<QTableWidgetSelectionRange> selectedRanges = songsTable->selectedRanges();
    for (const QTableWidgetSelectionRange& range : selectedRanges)
    {
        for (int row = range.bottomRow(); row >= range.topRow(); --row)
        {
            QTableWidgetItem* titleItem = songsTable->item(row, 0); // Assuming title is in the first column
            QTableWidgetItem* artistItem = songsTable->item(row, 1); // Assuming artist is in the second column

                songsTable->removeRow(row);

        }
    }
}

void MainWindow::addSongPlaylist()
{
    controller.add_playlist(titleEdit->text().toStdString(), artistEdit->text().toStdString(), durationEdit->text().toFloat(), pathEdit->text().toStdString());

    QList<QTableWidgetItem*> selectedItems = songsTable->selectedItems();

    // Check if any item is selected
    if (selectedItems.isEmpty()) {
        return;
    }

    // Get the row of the first selected item
    int selectedRow = songsTable->row(selectedItems.first());

    int currentRow = playlistTable->rowCount();
    playlistTable->insertRow(currentRow);
    // Populate the input fields with the data from the selected row
    playlistTable->setItem(currentRow, 0, new QTableWidgetItem(songsTable->item(selectedRow, 0)->text()));
    playlistTable->setItem(currentRow, 1, new QTableWidgetItem(songsTable->item(selectedRow, 1)->text()));
    playlistTable->setItem(currentRow, 2, new QTableWidgetItem(songsTable->item(selectedRow, 2)->text()));
    playlistTable->setItem(currentRow, 3, new QTableWidgetItem(songsTable->item(selectedRow, 3)->text()));

    playlistTable->resizeRowsToContents();


}
void MainWindow::setupUi() {
    QWidget* widget = new QWidget(this);

    //create all the object in the memory
    leftTitle = new QLabel{ "All Songs" };
    songsTable = new QTableWidget{ this };

    titleEdit = new QLineEdit{ this };
    artistEdit= new QLineEdit{ this };
    durationEdit= new QLineEdit{ this };
    pathEdit= new QLineEdit{ this };

    addButton = new QPushButton{ "Add",this };
    deleteButton= new QPushButton{ "Delete",this };
    updateButton = new QPushButton{ "Update",this };
    filterButton = new QPushButton{ "Filter",this };

    arrowButton = new QPushButton{ ">",this };

   rightTitle = new QLabel{ "Playlist" };
   playlistTable = new QTableWidget{ this };
   playButton = new QPushButton{ "Play",this };
   nextButton = new QPushButton{ "Next",this };
    
    //the main implementation
    setWindowTitle("Playlist Qt");
    
    //table
    //songsTable->setRowCount(5);        //setting the nr of rows
    songsTable->setColumnCount(4);      //Title, Artist, Duration
    QStringList headers = { "Title", "Artist","Duration","Path" };
    songsTable->setHorizontalHeaderLabels(headers);
    //songsTable->horizontalHeader()->setVisible(true);//make the table headers visible
    //songsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);// adjust to fit contents
    songsTable->verticalHeader()->setVisible(false);   //hide vertical header

    std::ifstream f("fisier.txt");
    if (!f.is_open())
        throw std::runtime_error("cant open");
    Song s;
    int i = 0;
    while (f >> s) {
        songsTable->insertRow(i);
        songsTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(s.getArtist())));
        songsTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(std::to_string(s.getDuration()))));
        songsTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(s.getArtist())));
        songsTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(s.getArtist())));
        i ++ ;
    }

    playlistTable->setColumnCount(4);
    playlistTable->horizontalHeader()->setVisible(false);
    playlistTable->verticalHeader()->setVisible(false);
    //form layout
    QFormLayout* formLayout = new QFormLayout{ this };
    formLayout->addRow(new QLabel{ "Title:" }, titleEdit);
    formLayout->addRow(new QLabel{ "Artist:" }, artistEdit);
    formLayout->addRow(new QLabel{ "Duration:" }, durationEdit);
    formLayout->addRow(new QLabel{ "Path:" }, pathEdit);
    
    //hlayout of buttons
    QHBoxLayout* buttonsLayout = new QHBoxLayout{ this };
    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(deleteButton);
    buttonsLayout->addWidget(updateButton);
    buttonsLayout->addWidget(filterButton);
    
    //form the whole left side
    QVBoxLayout* leftLayout = new QVBoxLayout{ this };
    leftLayout->addWidget(leftTitle);
    leftLayout->addWidget(songsTable);
    leftLayout->addLayout(formLayout);
    leftLayout->addLayout(buttonsLayout);


    //form the whole right side
    songsTable->horizontalHeader()->setVisible(true);
    playlistTable->verticalHeader()->setVisible(false);

    QVBoxLayout* rightLayout = new QVBoxLayout{ this };
    rightLayout->addWidget(rightTitle);
    rightLayout->addWidget(playlistTable);
    rightLayout->addWidget(playButton);
    rightLayout->addWidget(nextButton);

    QGridLayout* mainLayout = new QGridLayout{};
    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addWidget(arrowButton,0,1);
    mainLayout->addLayout(rightLayout, 0, 2);
    
    widget->setLayout(mainLayout);
    setCentralWidget(widget);

}