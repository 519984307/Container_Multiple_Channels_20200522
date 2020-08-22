#include "processing.h"

Processing::Processing(QObject *parent) : QObject(parent)
{
    p_LogController=new LogController ();
}
