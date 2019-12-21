#ifndef FIRSTLEVEL_H
#define FIRSTLEVEL_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlField>
#include <QSqlRecord>
//переделать : хранение паролей в качестве hash
//сделать : + 1)смену пользователя
//          2) получение информации для всех уровней,
//             смотря на уровень доступа
//          3) добавление информации для 2 уровня
//          4) сделать место,заявки, где будет хранится информация,
//             которая отправлена 1 и 2 уровнем
//          5) 3 и 4 уровень дать доступ на изменение и
//             удаление информации
//          6) логирование для изменений и удалений
//          7) сделать постоянное обновление данных
//          8) подозрительная активность
//          9) задачи на объекты, на персонал, выполненость
//          10) сохранение pdf

class firstLevel
{
public:
    firstLevel();
    QSqlQuery getAllInfo(QString str);
    QSqlQuery getcityInfo(QString str, QString city);
};

#endif // FIRSTLEVEL_H
