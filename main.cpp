#include <QtGui/QApplication>
#include "MappingAnalysis.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MappingAnalysis w;
    w.show();

    return a.exec();
}
