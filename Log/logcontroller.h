#ifndef LOGCONTROLLER_H
#define LOGCONTROLLER_H

#include <QObject>

class LogController : public QObject
{
    Q_OBJECT
public:
    explicit LogController(QObject *parent = nullptr);
    ~LogController()override;

signals:

};

#endif // LOGCONTROLLER_H