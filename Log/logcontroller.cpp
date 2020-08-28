#include "logcontroller.h"
#include "log.h"

#include <QPointer>
#include <QMessageLogContext>

QPointer<Log> vklog;

void myMessageOutput( QtMsgType type, const QMessageLogContext &context, const QString &msg )
{
    vklog->outPutMessage( type, context, msg );
}

LogController::LogController(QObject *parent) : QObject(parent)
{
    vklog = new Log( );
    qInstallMessageHandler( myMessageOutput );
}

LogController::~LogController()
{
    delete vklog;    
    vklog=nullptr;
}
