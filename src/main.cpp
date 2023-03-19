#include <iostream>
#include <chrono>
#include "Converter.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        auto layout = new QVBoxLayout();

            openZenButton = new QPushButton(tr("Zen öffnen"), this);
            layout->addWidget(openZenButton);

            convertButton = new QPushButton(tr("Konvertieren"), this);
            convertButton->setEnabled(false);
            layout->addWidget(convertButton);

            auto centralWidget = new QWidget();
            centralWidget->setLayout(layout);
            setCentralWidget(centralWidget);

            setStatusBar(new QStatusBar());
            statusBar()->showMessage(tr("Bitte wählen Sie eine ZEN-Datei."));
            connect(openZenButton, &QPushButton::clicked, this, &MainWindow::openZen);
            connect(convertButton, &QPushButton::clicked, this, &MainWindow::convert);
    }

private slots:
    void openZen()
    {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open .zen File"), QDir::homePath(), tr(".zen Files (*.zen)"));
        if (!fileName.isEmpty()) {
            // call the read function of the Converter class with the selected file name
			selectedFile = fileName;
            statusBar()->showMessage(selectedFile);
            convertButton->setEnabled(true);
        }
    }

    void convert()
    {
        QString outputFile = QFileDialog::getSaveFileName(this, tr("Save Converted File"), QDir::homePath(), tr(".wp Files (*.wp)"));
        if (!outputFile.isEmpty()) {
            // call the read and write functions of the Converter class with the selected file names
            Converter converter;
            converter.read(selectedFile.toStdString());
            converter.write(outputFile.toStdString());
            statusBar()->showMessage("Konvertierung abgeschlossen.");
        }
    }



private:
    QPushButton *openZenButton;
	QPushButton *convertButton;
    QString selectedFile;
};

int main(int argc, char **argv)
{
	/*
    std::cout << "Reveares' Waypoint Converter" << std::endl << std::endl;

    if (argc != 3)
    {
        std::cerr << "2 Arguments are needed!" << std::endl << "first: path/to/file.zen" << std::endl << "second: filename.wp" << std::endl;
        return -1;
    }

    auto start = std::chrono::high_resolution_clock::now();

    Converter converter;
    converter.read(argv[1]);
    converter.write(argv[2]);

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Which took " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;
	*/

    QApplication app(argc, argv);

	MainWindow mainWindow;
    mainWindow.show();

	return app.exec();
}

#include "main.moc"
