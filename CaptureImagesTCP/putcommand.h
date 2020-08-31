#ifndef PUTCOMMAND_H
#define PUTCOMMAND_H

#include <QObject>

class PutCommand : public QObject
{
    Q_OBJECT
public:
    explicit PutCommand(QObject *parent = nullptr);

signals:

};

#endif // PUTCOMMAND_H
