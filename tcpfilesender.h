#ifndef TCPFILESENDER_H
#define TCPFILESENDER_H

#include <QDialog>
#include <QtNetwork>
#include <QtWidgets>



class TcpFileSender : public QDialog
{
    Q_OBJECT

public:
    TcpFileSender(QWidget *parent = nullptr);
    ~TcpFileSender();
private slots:
    void start();
    void startTransfer();
    void openFile();
    void updateClientProgress(qint64 numBytes);
private:
    QProgressBar     *clientProgressBar;
    QLabel           *clientStatusLabel;
    QPushButton      *startButton;
    QPushButton      *quitButton;
    QPushButton      *openButton;
    QDialogButtonBox *buttonBox;
    QTcpSocket       tcpclient;


    qint64           totalBytes;
    qint64           bytesWritten;
    qint64           bytesToWrite;
    qint64           loadSize;
    QString          fileName;
    QFile            *loadFile;
    QByteArray       outBlock;
};
#endif // TCPFILESENDER_H
