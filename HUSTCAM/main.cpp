#include "mainwindow.h"
#include "database.h"
#include <QApplication>

//#include <Eigen/Geometry>
#include <iostream>
using namespace std;
//using namespace Eigen;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createConnection())
        return EXIT_FAILURE;

//    Matrix3d m1 = Matrix3d::Random();
//    cout << m1 << endl;
//    Matrix3d m2 = Matrix3d::Random();
//    cout << m2 << endl;
//    cout << m1 + m2 << endl;
//    cout << m1 - m2 << endl;
//    cout << m1 * m2;

//    Matrix3d m = Matrix3d::Random();
//    cout << m << endl;
//    cout << m.inverse() << endl;

    MainWindow w;
    w.show();
    return a.exec();
}
