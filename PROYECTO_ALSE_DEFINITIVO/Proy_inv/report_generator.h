#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <QObject>
#include <QAbstractItemModel>
#include <QString>

class report_generator : public QObject
{
    Q_OBJECT
public:
    explicit report_generator(QObject *parent = nullptr);

    bool exportToCSV(const QAbstractItemModel *model, const QString &filePath);
};

#endif // REPORT_GENERATOR_H
