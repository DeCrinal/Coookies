#ifndef PROGRAMMSETTINGS_H
#define PROGRAMMSETTINGS_H
#include <QString>

class ProgrammSettings
{
private:
    ProgrammSettings();
    ~ProgrammSettings();
    double velocity;
    QString language;
public:
    static void instance();
    static void getVelocity();
};

#endif // PROGRAMMSETTINGS_H
